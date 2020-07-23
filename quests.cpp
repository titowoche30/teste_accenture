#include <iostream>
#include <vector>
#include <iterator>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h> 
#include <string.h>

using namespace std;

void showstack(stack <double> s) { 
    cout<<"imprimindo pilha"<<endl;
    while (!s.empty()) { 
        cout <<s.top()<<','; 
        s.pop(); 
    } 
    cout << '\n'; 
}

double quest1(int num){
    int d = 2;
    stack<double> factors;
    
    while (num != 1){
        if (!(num % d)){
            factors.push(d);
            num /= d;
            //d = 2;
        }
        else
            d++;
    }

    cout<<"olha os factors: "<<endl;
    showstack(factors);
    

    int size = factors.size();
    double numerador = 0;
    double denominador = 0;
    double weight,factor;

    for (int i = 0; i < size; i++){
        weight = i+1;
        cout<<endl<<"weight="<<weight;
        factor = factors.top();
        factors.pop();
        cout<<" factor no laco= "<<factor<<endl;
        factor *= weight;

        numerador += factor;
        denominador += weight;
    }
    
    cout<<"\ndeu="<<numerador/denominador<<endl;
}

double busca_binaria(vector<int> vetor,int num,int inicio,int fim,int comp){
    int meio = (inicio + fim) / 2;

    if (num == vetor[meio]){
        comp++;
        cout<<"Achei no índice "<<meio<<endl<<"Com "<<comp<<" comparações"<<endl;
    }
    else if (num > vetor[meio]){
        comp++;
        return busca_binaria(vetor,num,meio,fim,comp);
    }
    else{
        comp++;
        return busca_binaria(vetor,num,inicio,meio,comp);
    }
}

void showvector(vector <int> vec){
  //  cout<<"imprimindo vector"<<endl;
    for (auto i = vec.begin(); i != vec.end(); i++)
        cout<<*i<<',';
    
    cout<<endl;
}

int numeroAcomodacoes(int numeroReservas, int *diaInicio, int *diaFim){
    int last_day;
    int numAcomod = 0;
    vector <int> final,inicio;

    for (int i = 0; i < numeroReservas; i++){
        final.push_back(diaFim[i]);
        inicio.push_back(diaInicio[i]);
    }
    
    for (int i = 0; i < final.size(); i++){
        last_day = final[i];
        cout<<"\nAcomodação"<<numAcomod+1<<" = "<<inicio[i]<<","<< last_day<<" ; ";
        numAcomod++;

        for (int j = i; j < final.size(); j++){
            if (inicio[j] >= last_day){
                cout<<inicio[j]<<","<<final[j]<<endl;
                final.erase(final.begin()+j);
                inicio.erase(inicio.begin()+j);
                break;
            }
            
        }
    }
    
    //cout<<endl<<"acomodações necessárias = "<<numAcomod<<endl;

    return numAcomod;
}

double subSet(int vetor[],int size,int sum){
    int a,b,c;
    int i,j,k;
    for (i = 0; i < size; i++){
        a = vetor[i];
        for (j = i+1; j < size; j++){
            b = vetor[j];
            for (k = j+1; k < size; k++){
                c = vetor[k];
                //cout<<"a,b,c="<<a<<b<<c<<endl;
                if (a+b+c == sum)
                    cout<<a<<b<<c<<" deu hein"<<endl;
             }
        }
    }

    return true;
}

int soma_menor(int vetor[],int tamanho){
    int metade = 0;

    if (!(tamanho%2)) metade = (tamanho/2) +1;
    else metade = ceil(tamanho/2) +1 ;

    int contador = 1; 
    int soma = 0;
    if (tamanho == 0 ) return -1;

    cout<<"maioria absoluta= "<<metade<<endl;
    sort(vetor, vetor+tamanho);
    
    int maioria = vetor[0];
    for (int i = 1; i < tamanho; i++){
        if (vetor[i] == maioria){
            contador++;
            if (contador == metade){
                break;
            }
        } 
        else{
            maioria = vetor[i];
            contador = 1;
        }
    }
    
    //int vetor[] = {2, 1, 7, 2, 2, 8, 2, 1}
    //1,1,2,2,2,2,7,8

//    cout<<"contador ="<<contador<<endl;
    if (contador != metade){
//        cout<<"entrou aqui"<<endl;
        return -1;
    }
    for (int i = 0; i < tamanho; i++){
        if(vetor[i]<maioria) 
            soma += vetor[i];
        else
            break;
        
        
    }
    cout<<"soma= "<<soma<<endl;

    return 0;
}

double pol_inverse(string operacao){
    operacao.push_back(' ');
    string delimitador = " ";
    size_t pos = 0;
    string token;
    vector <string> new_operacao;
    // string.find('a') will EITHER return the position of the first appearance of 'a' in some_string if 'a' appears at least once in some_string, OR it will return a value that is equal to std::string::npos if 'a' does not appear at all in some_string.
    
    while ((pos = operacao.find(delimitador)) != string::npos){
        token = operacao.substr(0,pos);
        operacao.erase(0,pos+delimitador.length());
        new_operacao.push_back(token);
    }

    stack <double> resultados;
    double topo0,topo1;

    for (auto i = new_operacao.begin(); i != new_operacao.end(); i++){
        if (*i == "+"){
            topo1 = resultados.top();
            resultados.pop();
            topo0 = resultados.top();
            resultados.pop();
            resultados.push(topo0+topo1);
        }
        else if (*i == "-"){
            topo1 = resultados.top();
            resultados.pop();
            topo0 = resultados.top();
            resultados.pop();
            resultados.push(topo0-topo1);
        }
        else if (*i == "*"){
            topo1 = resultados.top();
            resultados.pop();
            topo0 = resultados.top();
            resultados.pop();
            resultados.push(topo0*topo1);
        }
        else if (*i == "/"){
            topo1 = resultados.top();
            resultados.pop();
            topo0 = resultados.top();
            resultados.pop();
            resultados.push(topo0/topo1);
        }
        else{
            resultados.push(stod(*i));
        }
    }

    cout<<"Resultado = ";
    //showvector(resultados);
    showstack(resultados);
}

double Romano(string romano, int n){
    map<char, int> algarismos;   
    algarismos.insert(pair<char, int>('I', 1)); 
    algarismos.insert(pair<char, int>('V', 5)); 
    algarismos.insert(pair<char, int>('X', 10)); 
    algarismos.insert(pair<char, int>('L', 50)); 
    algarismos.insert(pair<char, int>('C', 100)); 
    algarismos.insert(pair<char, int>('D', 500)); 
    algarismos.insert(pair<char, int>('M', 1000)); 
    
    int sum = 0;
    bool flag = false;
    
    for (int i = 0 ;i<romano.length();i++){
     //   cout<<"soma parcial= "<<sum<<endl;
        if (flag){ 
            flag = false;
            continue; 
        }
        if(algarismos[romano[i+1]]>algarismos[romano[i]]){
         //   cout<<romano[i]<<" menor que "<<romano[i+1]<<" hein"<<endl;
         //   cout<<"dife é: "<< algarismos[romano[i+1]] - algarismos[romano[i]]<<endl;
            sum += algarismos[romano[i+1]] - algarismos[romano[i]];
            flag = true;
        }
        else{
            sum += algarismos[romano[i]];
        }
        
     }
    cout<<"soma final= "<<sum<<endl; 
    return 0;
}

double calc(string num1, string sinal, string num2){
    double num_1 = stod(num1);
    double num_2 = stod(num2);

    if (sinal == "+") return num_1+num_2;
    
    if (sinal == "-") return num_1-num_2;
    
    if (sinal == "*") return num_1*num_2;
    
    if (sinal == "/") return num_1/num_2;
    
    return 0.0;
}

double operacao_norm(string operacao){
    operacao.push_back(' ');
    size_t pos = 0;
    string delimitador = " ";
    string token;
    vector <string> new_operacao;
    // string.find('a') will EITHER return the position of the first appearance of 'a' in some_string if 'a' appears at least once in some_string, OR it will return a value that is equal to std::string::npos if 'a' does not appear at all in some_string.
    
    while ((pos = operacao.find(delimitador)) != string::npos){
        token = operacao.substr(0,pos);
        operacao.erase(0,pos+delimitador.length());
        new_operacao.push_back(token);
    }

    cout<<"olha a splitada= "<<endl;
    showvector(new_operacao);
    int tam = new_operacao.size();
    double resul = 0;

    while (new_operacao.size() != 1){
        for (int i = 1; i < tam-1; i++)
            if(new_operacao[i] == "*" || new_operacao[i] == "/"){
                resul = calc(new_operacao[i-1],new_operacao[i],new_operacao[i+1]);
               //cout<<"calc = "<<resul<<endl;
                new_operacao.erase(new_operacao.begin()+(i-1),new_operacao.begin()+(i-1)+3);
                new_operacao.insert(new_operacao.begin()+(i-1),to_string(resul));
                //cout<<"olha o vector\n";
                //showvector(new_operacao);
                //i--;
            }   

        for (int i = 1; i < tam-1; i++)
            if(new_operacao[i] == "+" || new_operacao[i] == "-"){
                resul = calc(new_operacao[i-1],new_operacao[i],new_operacao[i+1]);
                //cout<<"calc = "<<resul<<endl;
                new_operacao.erase(new_operacao.begin()+(i-1),new_operacao.begin()+(i-1)+3);
                new_operacao.insert(new_operacao.begin()+(i-1),to_string(resul));
            }  
    }
    

    cout<<"operacao no final=";
    showvector(new_operacao);
    }

int main (){
    // quest1(3960);
    // vector<int> vetor;
    // for (int i = 1; i <= 30; i++) 
    //     vetor.push_back(i); 

    // busca_binaria(vetor,23,0,vetor.size()-1,0);

    // int diasInicio[] = {1,1,3,7,6};
    // int diasFim[] = {7,4,10,12,15};

    // quest_hotel(5,diasInicio,diasFim);

    // int vetor[] = {1,2,3,4,5};
    // subSet(vetor,5,8);

    // int vetor[] = {3, 1, 1, 3, 3, 8, 3} ;
    // soma_menor(vetor,7);

    // vector <int> vet;
    // vet.push_back(0);
    // vet.push_back(1);
    // vet.push_back(2);
    // vet.push_back(3);

    // vet.erase(vet.begin()+2);
    // for (auto i = vet.begin(); i != vet.end(); i++)
    // {
    //     cout<<*i<<endl;
    // }
    
     string operacao("10 5 + 2 /");
    //   string operacao("5 1 2 + 4 * + 3 -");
       pol_inverse(operacao);

    // string romano("MMMCIV");
    // Romano(romano,romano.length());

    //string operacao("5 + 4 * 3");
    // string operacao("5 + 4 * 3 - 7");
    // operacao_norm(operacao);


    return 0;
}

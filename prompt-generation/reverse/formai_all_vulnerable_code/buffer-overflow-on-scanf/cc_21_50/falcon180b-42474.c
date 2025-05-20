//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: high level of detail
#include<stdio.h>
#include<math.h>

int main(){
    char expression[100];
    int i=0;
    int j=0;
    int k=0;
    double num1=0;
    double num2=0;
    double result=0;
    double temp=0;
    int flag=0;
    int count=0;
    
    while(1){
        printf("\nEnter the expression: ");
        scanf("%s",expression);
        
        if(strlen(expression)==0){
            printf("\nExpression cannot be empty");
            continue;
        }
        
        count=0;
        for(i=0;expression[i]!='\0';i++){
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*' || expression[i]=='/' || expression[i]=='(' || expression[i]==')' || expression[i]=='^' || expression[i]=='s' || expression[i]=='c' || expression[i]=='t' || expression[i]=='=' || expression[i]==' '){
                count++;
            }
        }
        
        if(count==0){
            printf("\nInvalid expression");
            continue;
        }
        
        j=0;
        k=0;
        flag=0;
        temp=0;
        result=0;
        while(expression[j]!='\0'){
            if(expression[j]==' '){
                j++;
                continue;
            }
            if(isdigit(expression[j])){
                num1=num1*10+(expression[j]-48);
            }
            else if(expression[j]=='+' || expression[j]=='-' || expression[j]=='*' || expression[j]=='/' || expression[j]=='(' || expression[j]==')' || expression[j]=='^' || expression[j]=='s' || expression[j]=='c' || expression[j]=='t' || expression[j]=='='){
                if(flag==0){
                    temp=num1;
                    num1=0;
                    flag=1;
                }
                else{
                    result=result+temp*num1;
                    temp=0;
                }
                if(expression[j]=='s'){
                    result=sin(result);
                }
                else if(expression[j]=='c'){
                    result=cos(result);
                }
                else if(expression[j]=='t'){
                    result=tan(result);
                }
                else if(expression[j]=='='){
                    printf("\nResult: %.2lf",result);
                    flag=0;
                    num1=0;
                    result=0;
                    temp=0;
                }
            }
            else{
                printf("\nInvalid character");
                return 0;
            }
            j++;
        }
        if(flag==0){
            printf("\nResult: %.2lf",num1);
        }
    }
}
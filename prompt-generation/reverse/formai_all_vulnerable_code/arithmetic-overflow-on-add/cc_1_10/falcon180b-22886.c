//Falcon-180B DATASET v1.0 Category: Error handling ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void Error(int code){
    switch(code){
        case 1:
            printf("Error: Invalid Input\n");
            break;
        case 2:
            printf("Error: Division by Zero\n");
            break;
        case 3:
            printf("Error: Out of Memory\n");
            break;
        default:
            printf("Error: Unknown Error\n");
            break;
    }
    exit(1);
}

int main(){
    int a,b,result;
    char op;

    printf("Enter an expression in the form of a*b+c\n");
    scanf("%d%c%d",&a,&op,&b);

    switch(op){
        case '+':
            result = a+b;
            break;
        case '-':
            result = a-b;
            break;
        case '*':
            result = a*b;
            break;
        case '/':
            if(b==0){
                Error(2);
            }
            result = a/b;
            break;
        default:
            Error(1);
    }

    printf("Result = %d\n",result);

    return 0;
}
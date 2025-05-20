//Falcon-180B DATASET v1.0 Category: Error handling ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

double add(double a,double b);
double subtract(double a,double b);
double multiply(double a,double b);
double divide(double a,double b);

int main(){
    int choice;
    double num1,num2;
    char operation[10];
    printf("Enter the number of operations to be performed:");
    scanf("%d",&choice);
    for(int i=0;i<choice;i++){
        printf("\nEnter the operation to be performed:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
        scanf("%s",operation);
        printf("\nEnter the two numbers:\n");
        scanf("%lf %lf",&num1,&num2);
        switch(operation[0]){
            case '1':
                printf("\nResult: %lf",add(num1,num2));
                break;
            case '2':
                printf("\nResult: %lf",subtract(num1,num2));
                break;
            case '3':
                printf("\nResult: %lf",multiply(num1,num2));
                break;
            case '4':
                if(num2!=0)
                    printf("\nResult: %lf",divide(num1,num2));
                else
                    printf("\nError: Division by zero");
                break;
            default:
                printf("\nInvalid operation");
        }
    }
    return 0;
}

double add(double a,double b){
    return a+b;
}

double subtract(double a,double b){
    return a-b;
}

double multiply(double a,double b){
    return a*b;
}

double divide(double a,double b){
    if(b==0)
        return 0;
    else
        return a/b;
}
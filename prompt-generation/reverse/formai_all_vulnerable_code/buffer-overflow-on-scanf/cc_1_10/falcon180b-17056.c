//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define SIZE 100

typedef struct {
    char *name;
    int (*func)(int,int);
}operation;

int add(int a,int b) {
    return a+b;
}

int subtract(int a,int b) {
    return a-b;
}

int multiply(int a,int b) {
    return a*b;
}

int divide(int a,int b) {
    if(b==0) {
        printf("Error! Division by zero is not allowed.\n");
        exit(0);
    }
    return a/b;
}

int power(int a,int b) {
    return pow(a,b);
}

int factorial(int a) {
    int fact=1;
    for(int i=1;i<=a;i++) {
        fact*=i;
    }
    return fact;
}

int main() {
    char input[SIZE];
    int num1,num2,choice;
    operation oper[]={{"+",add},{"-",subtract},{"*",multiply},{"/",divide},{"^",power},{"!",factorial}};
    printf("Enter first number: ");
    scanf("%d",&num1);
    printf("Enter second number: ");
    scanf("%s",input);
    printf("Enter the operation you want to perform:\n");
    for(int i=0;i<6;i++) {
        printf("%d. %s\n",i+1,oper[i].name);
    }
    scanf("%d",&choice);
    int result=oper[choice-1].func(num1,atoi(input));
    printf("Result: %d\n",result);
    return 0;
}
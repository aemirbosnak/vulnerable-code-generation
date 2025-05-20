//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int (*func)(int,int);
} operation;

int add(int a, int b) {
    return a+b;
}

int subtract(int a, int b) {
    return a-b;
}

int multiply(int a, int b) {
    return a*b;
}

int divide(int a, int b) {
    if(b==0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    return a/b;
}

int power(int a, int b) {
    return pow(a,b);
}

int main() {
    char input[MAX_SIZE];
    int num1, num2, result, i;
    operation op[10] = {{"+", add}, {"-", subtract}, {"*", multiply}, {"/", divide}, {"^", power}};
    printf("Welcome to the Surrealist Calculator!\n");
    while(1) {
        printf("Enter a mathematical expression or type 'exit' to quit: ");
        scanf("%s", input);
        if(strcmp(input, "exit") == 0) {
            break;
        }
        for(i=0; i<5; i++) {
            if(strcmp(input, op[i].name) == 0) {
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = op[i].func(num1, num2);
                printf("Result: %d\n", result);
            }
        }
    }
    return 0;
}
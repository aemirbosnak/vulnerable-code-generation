//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 100

int top = -1;
double stack[MAX_STACK_SIZE];

void push(double value){
    if(top == MAX_STACK_SIZE-1){
        printf("Stack Overflow!\n");
    }
    else{
        top++;
        stack[top] = value;
    }
}

double pop(){
    if(top == -1){
        printf("Stack Underflow!\n");
        return -1;
    }
    else{
        double value = stack[top];
        top--;
        return value;
    }
}

void calculate(double value1, double value2, char op){
    switch(op){
        case '+':
            push(value1 + value2);
            break;
        case '-':
            push(value1 - value2);
            break;
        case '*':
            push(value1 * value2);
            break;
        case '/':
            push(value1 / value2);
            break;
        case '^':
            push(pow(value1, value2));
            break;
    }
}

int main(){
    char input[100];
    double op1, op2;
    
    printf("\nWelcome to the Cyberpunk Scientific Calculator!\n");
    
    while(1){
        printf("\nEnter an operation (q to quit): ");
        scanf("%s", input);
        
        if(input[0] == 'q' && input[1] == '\0'){
            break;
        }
        
        if(input[0] >= '0' && input[0] <= '9'){
            push(atof(input));
        }
        else{
            op2 = pop();
            op1 = pop();
            calculate(op1, op2, input[0]);
        }
    }
    
    printf("\nBye!\n");
    
    return 0;
}
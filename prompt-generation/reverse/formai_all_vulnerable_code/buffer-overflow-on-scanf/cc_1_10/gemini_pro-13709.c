//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 100

typedef struct {
    double value;
    char op;
} stack_item;

stack_item stack[MAX_STACK_SIZE];
int stack_top = 0;

void push(double value, char op) {
    if (stack_top == MAX_STACK_SIZE) {
        printf("Error: stack overflow\n");
        exit(1);
    }
    stack[stack_top].value = value;
    stack[stack_top].op = op;
    stack_top++;
}

double pop() {
    if (stack_top == 0) {
        printf("Error: stack underflow\n");
        exit(1);
    }
    stack_top--;
    return stack[stack_top].value;
}

double evaluate(char *expr) {
    int i = 0;
    double op1, op2;
    while (expr[i] != '\0') {
        if (expr[i] >= '0' && expr[i] <= '9') {
            push(atof(&expr[i]), 'n');
            while (expr[i] >= '0' && expr[i] <= '9') {
                i++;
            }
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            op2 = pop();
            op1 = pop();
            switch (expr[i]) {
                case '+':
                    push(op1 + op2, '+');
                    break;
                case '-':
                    push(op1 - op2, '-');
                    break;
                case '*':
                    push(op1 * op2, '*');
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("Error: division by zero\n");
                        exit(1);
                    }
                    push(op1 / op2, '/');
                    break;
            }
            i++;
        } else {
            printf("Error: invalid character '%c'\n", expr[i]);
            exit(1);
        }
    }
    return pop();
}

int main() {
    char expr[100];
    printf("Enter an expression: ");
    scanf("%s", expr);
    printf("Result: %f\n", evaluate(expr));
    return 0;
}
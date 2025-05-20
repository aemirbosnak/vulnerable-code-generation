//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 100

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_NEG,
    OP_POW,
    OP_SIN,
    OP_COS,
    OP_TAN,
    OP_LN,
    OP_LOG,
    OP_SQRT,
    OP_CBRT,
    OP_FACTORIAL
} operator;

typedef struct {
    double value;
    operator op;
} stack_item;

stack_item stack[MAX_STACK_SIZE];
int stack_top = -1;

void push(double value, operator op) {
    if (stack_top == MAX_STACK_SIZE - 1) {
        printf("Error: stack overflow\n");
        exit(1);
    }
    stack[++stack_top].value = value;
    stack[stack_top].op = op;
}

double pop() {
    if (stack_top == -1) {
        printf("Error: stack underflow\n");
        exit(1);
    }
    return stack[stack_top--].value;
}

double evaluate(char *expression) {
    int i = 0;
    double operand1, operand2, result;
    while (expression[i] != '\0') {
        if (expression[i] >= '0' && expression[i] <= '9') {
            double value = 0;
            while (expression[i] >= '0' && expression[i] <= '9') {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            push(value, OP_ADD);
        } else if (expression[i] == '(') {
            push(0, OP_ADD);
            i++;
        } else if (expression[i] == ')') {
            operand2 = pop();
            operand1 = pop();
            result = operand1 + operand2;
            push(result, OP_ADD);
            i++;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '%') {
            operator op;
            switch (expression[i]) {
                case '+':
                    op = OP_ADD;
                    break;
                case '-':
                    op = OP_SUB;
                    break;
                case '*':
                    op = OP_MUL;
                    break;
                case '/':
                    op = OP_DIV;
                    break;
                case '%':
                    op = OP_MOD;
                    break;
            }
            push(0, op);
            i++;
        } else {
            printf("Error: invalid expression\n");
            exit(1);
        }
    }
    return pop();
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);
    double result = evaluate(expression);
    printf("Result: %f\n", result);
    return 0;
}
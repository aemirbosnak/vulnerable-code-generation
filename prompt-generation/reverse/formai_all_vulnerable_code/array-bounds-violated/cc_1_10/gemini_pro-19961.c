//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mind-bending
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
double evaluate(char *);
bool isOperator(char);
int precedence(char);
double applyOperator(double, double, char);

int main() {
    printf("\n\033[0;34mCALCULATOR\033[0m\033[1;34m++\033[0m: Mind-Bending Edition\n\n");
    printf("Instructions:\n");
    printf("\033[1;33m*\033[0m Enter expressions in prefix notation.\n");
    printf("\033[1;33m*\033[0m Supported operators: +, -, *, /, ^.\n");
    printf("\033[1;33m*\033[0m Example: To evaluate 1+2*3, enter \"+ 1 * 2 3\".\n\n");

    while (true) {
        printf("> ");
        char expression[100];
        if (!fgets(expression, sizeof(expression), stdin)) {
            printf("\n\033[0;31mGoodbye!\033[0m\n");
            return 0;
        }
        double result = evaluate(expression);
        printf("= \033[1;32m%f\033[0m\n\n", result);
    }

    return 0;
}

double evaluate(char *expression) {
    int len = strlen(expression);
    char stack[len];
    int top = -1;

    for (int i = len - 1; i >= 0; i--) {
        char token = expression[i];
        if (isOperator(token)) {
            double operand2 = atof(stack[top--]);
            double operand1 = atof(stack[top--]);
            double result = applyOperator(operand1, operand2, token);
            char resultStr[50];
            sprintf(resultStr, "%f", result);
            strcpy(stack[top++], resultStr);
        } else {
            stack[++top] = token;
        }
    }

    return atof(stack[top]);
}

bool isOperator(char token) {
    return token == '+' || token == '-' || token == '*' || token == '/' || token == '^';
}

int precedence(char token) {
    switch (token) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

double applyOperator(double operand1, double operand2, char token) {
    switch (token) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
            return pow(operand1, operand2);
        default:
            return 0;
    }
}
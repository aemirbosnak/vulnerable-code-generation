//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char expr[1024], result[1024];

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int get_precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void infix_to_postfix() {
    int i, j, top = -1;
    char stack[1024];

    for (i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            stack[++top] = expr[i];
        }
        else if (expr[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                result[j++] = stack[top--];
            }
            if (top != -1) {
                top--;
            }
        }
        else if (is_operator(expr[i])) {
            while (top != -1 && get_precedence(expr[i]) <= get_precedence(stack[top])) {
                result[j++] = stack[top--];
            }
            stack[++top] = expr[i];
        }
        else {
            result[j++] = expr[i];
        }
    }
    while (top != -1) {
        result[j++] = stack[top--];
    }
    result[j] = '\0';
}

double evaluate_postfix() {
    int i, top = -1;
    double stack[1024];

    for (i = 0; result[i] != '\0'; i++) {
        if (isdigit(result[i])) {
            stack[++top] = result[i] - '0';
        }
        else if (is_operator(result[i])) {
            double op1 = stack[top--];
            double op2 = stack[top--];
            switch (result[i]) {
                case '+':
                    stack[++top] = op1 + op2;
                    break;
                case '-':
                    stack[++top] = op2 - op1;
                    break;
                case '*':
                    stack[++top] = op1 * op2;
                    break;
                case '/':
                    if (op1 == 0) {
                        printf("Division by zero error\n");
                        exit(EXIT_FAILURE);
                    }
                    stack[++top] = op2 / op1;
                    break;
            }
        }
    }
    return stack[top];
}

int main() {
    printf("Enter infix expression: ");
    gets(expr);
    infix_to_postfix();
    printf("Postfix expression: %s\n", result);
    double result = evaluate_postfix();
    printf("Result: %.2f\n", result);
    return 0;
}
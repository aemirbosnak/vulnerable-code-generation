//MISTRAL-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    double value;
    int op;
} CalcStackElement;

#define MAX_STACK_SIZE 100

CalcStackElement stack[MAX_STACK_SIZE];
int top = -1;

void push(CalcStackElement data) {
    if (top >= MAX_STACK_SIZE - 1) {
        fprintf(stderr, "Stack Overflow!\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = data;
}

CalcStackElement pop() {
    if (top < 0) {
        fprintf(stderr, "Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

void clear_stack() {
    top = -1;
}

int precedence(int op) {
    switch (op) {
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

void apply_operator(int op) {
    CalcStackElement b, a;

    b = pop();
    a = pop();

    switch (op) {
        case '+':
            push((CalcStackElement) {a.value + b.value});
            break;
        case '-':
            push((CalcStackElement) {a.value - b.value});
            break;
        case '*':
            push((CalcStackElement) {a.value * b.value});
            break;
        case '/':
            push((CalcStackElement) {a.value / b.value});
            break;
        case '^':
            push((CalcStackElement) {pow(a.value, b.value)});
            break;
    }
}

void parse_token(char token) {
    if (isdigit(token)) {
        double num = strtod((&token), NULL);
        push((CalcStackElement) {num});
    } else if (isalnum(token)) {
        apply_operator(token);
    } else if (token == '(') {
        push((CalcStackElement) {.op = 0});
    } else if (token == ')') {
        while (stack[top].op != 0) {
            apply_operator(stack[top].op);
            clear_stack();
        }
        clear_stack();
    }
}

void calculate(char *expression) {
    int i;
    for (i = 0; expression[i] != '\0'; i++) {
        parse_token(expression[i]);
    }

    if (top > 0) {
        apply_operator(stack[top].op);
        clear_stack();
    }
}

int main() {
    char expr[100];

    printf("Calm Scientific Calculator v1.0.0\n");
    printf("Enter an expression in the following format: [number] [operator] [number] ...\n");
    printf("Supported operators: +, -, *, /, ^ (exponentiation), (, ), \n");

    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';

    calculate(expr);

    printf("Result: %.12lf\n", stack[top].value);

    return 0;
}
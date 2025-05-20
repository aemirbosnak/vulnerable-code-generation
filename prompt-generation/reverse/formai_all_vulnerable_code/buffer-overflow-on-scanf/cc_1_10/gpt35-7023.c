//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_EXPR_LEN 100

struct Stack {
    char items[MAX_EXPR_LEN];
    int top;
};

void push(struct Stack* stack, char item) {
    if (stack->top == MAX_EXPR_LEN - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->top++;
    stack->items[stack->top] = item;
}

char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    char item = stack->items[stack->top];
    stack->top--;
    return item;
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

int parse_expression(char* expr) {
    struct Stack operators;
    operators.top = -1;

    struct Stack operands;
    operands.top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (isdigit(c)) {
            push(&operands, c);
        } else if (is_operator(c)) {
            while (operators.top != -1 && precedence(c) <= precedence(operators.items[operators.top])) {
                char op = pop(&operators);
                char rhs = pop(&operands);
                char lhs = pop(&operands);
                switch(op) {
                    case '+':
                        push(&operands, lhs + rhs);
                        break;
                    case '-':
                        push(&operands, lhs - rhs);
                        break;
                    case '*':
                        push(&operands, lhs * rhs);
                        break;
                    case '/':
                        push(&operands, lhs / rhs);
                        break;
                }
            }
            push(&operators, c);
        }
    }

    while (operators.top != -1) {
        char op = pop(&operators);
        char rhs = pop(&operands);
        char lhs = pop(&operands);
        switch(op) {
            case '+':
                push(&operands, lhs + rhs);
                break;
            case '-':
                push(&operands, lhs - rhs);
                break;
            case '*':
                push(&operands, lhs * rhs);
                break;
            case '/':
                push(&operands, lhs / rhs);
                break;
        }
    }

    return pop(&operands);
}

int main() {
    char expr[MAX_EXPR_LEN];
    printf("Enter an arithmetic expression: ");
    scanf("%s", expr);
    int result = parse_expression(expr);
    printf("Result: %d\n", result);
    return 0;
}
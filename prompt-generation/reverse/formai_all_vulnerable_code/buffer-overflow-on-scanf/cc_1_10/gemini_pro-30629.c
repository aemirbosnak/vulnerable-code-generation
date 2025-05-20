//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_SIZE 100

typedef struct {
    double data[STACK_SIZE];
    int top;
} stack;

void push(stack *s, double value) {
    if (s->top == STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = value;
}

double pop(stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

double peek(stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top];
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

double evaluate(char *expr) {
    stack s;
    s.top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == ' ') {
            continue;
        } else if (isdigit(c)) {
            double value = 0;
            while (isdigit(c)) {
                value = value * 10 + (c - '0');
                c = expr[++i];
            }
            i--;
            push(&s, value);
        } else if (is_operator(c)) {
            double op1 = pop(&s);
            double op2 = pop(&s);
            switch (c) {
                case '+':
                    push(&s, op2 + op1);
                    break;
                case '-':
                    push(&s, op2 - op1);
                    break;
                case '*':
                    push(&s, op2 * op1);
                    break;
                case '/':
                    push(&s, op2 / op1);
                    break;
                case '^':
                    push(&s, pow(op2, op1));
                    break;
            }
        } else {
            printf("Invalid character in expression\n");
            exit(1);
        }
    }

    return pop(&s);
}

int main() {
    char expr[100];
    printf("Enter an expression: ");
    scanf("%s", expr);
    double result = evaluate(expr);
    printf("Result: %f\n", result);
    return 0;
}
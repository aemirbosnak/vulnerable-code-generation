//MISTRAL-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_EXP 100
#define MAX_LEN 100
#define MAX_NUM 50

typedef struct {
    char op[3];
    int precedence;
} Operator;

typedef struct {
    double num[MAX_NUM];
    int top;
} Stack;

void push(Stack *s, double num) {
    if (s->top >= MAX_NUM) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->num[s->top++] = num;
}

double pop(Stack *s) {
    if (s->top <= 0) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->num[--s->top];
}

int prec(char op) {
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

void apply_op(Stack *s, Operator op) {
    double b, a;
    a = pop(s);
    b = pop(s);

    switch (op.precedence) {
        case 3:
            push(s, pow(b, a));
            break;
        case 2:
            switch (op.op[0]) {
                case '*':
                    push(s, b * a);
                    break;
                case '/':
                    push(s, b / a);
                    break;
            }
            break;
        case 1:
            switch (op.op[0]) {
                case '+':
                    push(s, b + a);
                    break;
                case '-':
                    push(s, b - a);
                    break;
            }
            break;
    }
}

void evaluate_postfix(char *exp) {
    int i, len = strlen(exp);
    Stack s;
    s.top = -1;

    for (i = 0; i < len; i++) {
        if (isdigit(exp[i])) {
            push(&s, strtod(&(exp[i]), NULL));
        } else {
            Operator op;
            strncpy(op.op, &(exp[i]), 2);
            op.op[2] = '\0';
            apply_op(&s, op);
        }
    }

    if (s.top != 0) {
        printf("Result: %lf\n", pop(&s));
    }
}

int main() {
    char exp[MAX_LEN];

    printf("Enter the postfix expression: ");
    fgets(exp, sizeof(exp), stdin);
    exp[strlen(exp) - 1] = '\0';

    evaluate_postfix(exp);

    return EXIT_SUCCESS;
}
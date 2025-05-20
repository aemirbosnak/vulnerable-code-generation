//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 100

typedef struct stack {
    int top;
    double values[MAX_STACK_SIZE];
} stack;

void push(stack *s, double value) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->values[++s->top] = value;
}

double pop(stack *s) {
    if (s->top == -1) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->values[s->top--];
}

int main() {
    stack s;
    s.top = -1;

    char input[100];
    while (1) {
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "+") == 0) {
            double a = pop(&s);
            double b = pop(&s);
            push(&s, a + b);
        } else if (strcmp(input, "-") == 0) {
            double a = pop(&s);
            double b = pop(&s);
            push(&s, b - a);
        } else if (strcmp(input, "*") == 0) {
            double a = pop(&s);
            double b = pop(&s);
            push(&s, a * b);
        } else if (strcmp(input, "/") == 0) {
            double a = pop(&s);
            double b = pop(&s);
            push(&s, b / a);
        } else if (strcmp(input, "sin") == 0) {
            double a = pop(&s);
            push(&s, sin(a));
        } else if (strcmp(input, "cos") == 0) {
            double a = pop(&s);
            push(&s, cos(a));
        } else if (strcmp(input, "tan") == 0) {
            double a = pop(&s);
            push(&s, tan(a));
        } else if (strcmp(input, "sqrt") == 0) {
            double a = pop(&s);
            push(&s, sqrt(a));
        } else if (strcmp(input, "ln") == 0) {
            double a = pop(&s);
            push(&s, log(a));
        } else if (strcmp(input, "log") == 0) {
            double a = pop(&s);
            push(&s, log10(a));
        } else {
            double value = atof(input);
            push(&s, value);
        }

        printf("%f\n", s.values[s.top]);
    }

    return 0;
}
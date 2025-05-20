//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 100

typedef struct _stack {
    double* data;
    int top;
} stack;

void stack_init(stack* s) {
    s->data = malloc(MAX_STACK_SIZE * sizeof(double));
    s->top = -1;
}

void stack_push(stack* s, double value) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = value;
}

double stack_pop(stack* s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

int main() {
    stack s;
    stack_init(&s);

    char input[100];
    while (1) {
        printf("> ");
        scanf("%s", input);

        switch (input[0]) {
            case '+':
                stack_push(&s, stack_pop(&s) + stack_pop(&s));
                break;
            case '-':
                stack_push(&s, -stack_pop(&s) + stack_pop(&s));
                break;
            case '*':
                stack_push(&s, stack_pop(&s) * stack_pop(&s));
                break;
            case '/':
                stack_push(&s, 1 / stack_pop(&s) * stack_pop(&s));
                break;
            case '^':
                stack_push(&s, pow(stack_pop(&s), stack_pop(&s)));
                break;
            case 's':
                stack_push(&s, sin(stack_pop(&s)));
                break;
            case 'c':
                stack_push(&s, cos(stack_pop(&s)));
                break;
            case 't':
                stack_push(&s, tan(stack_pop(&s)));
                break;
            case 'l':
                stack_push(&s, log(stack_pop(&s)));
                break;
            case 'e':
                stack_push(&s, exp(stack_pop(&s)));
                break;
            case 'p':
                printf("%f\n", stack_pop(&s));
                break;
            case 'q':
                exit(0);
            default:
                stack_push(&s, atof(input));
                break;
        }
    }

    return 0;
}
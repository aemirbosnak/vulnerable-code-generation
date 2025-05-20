//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_SIZE 100

typedef struct {
    double *stack;
    int top;
} stack;

void init_stack(stack *s) {
    s->stack = (double *) malloc(STACK_SIZE * sizeof(double));
    s->top = -1;
}

void push(stack *s, double x) {
    if (s->top >= STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->top++;
    s->stack[s->top] = x;
}

double pop(stack *s) {
    if (s->top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    double x = s->stack[s->top];
    s->top--;
    return x;
}

double peek(stack *s) {
    if (s->top < 0) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->stack[s->top];
}

void clear_stack(stack *s) {
    s->top = -1;
}

int is_empty(stack *s) {
    return s->top == -1;
}

int is_full(stack *s) {
    return s->top >= STACK_SIZE - 1;
}

int main() {
    stack s;
    init_stack(&s);

    int choice;
    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Clear\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                double x;
                printf("Enter a number to push: ");
                scanf("%lf", &x);
                push(&s, x);
                break;
            }
            case 2: {
                double x = pop(&s);
                printf("Popped element: %lf\n", x);
                break;
            }
            case 3: {
                double x = peek(&s);
                printf("Top element: %lf\n", x);
                break;
            }
            case 4: {
                clear_stack(&s);
                printf("Stack cleared\n");
                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    } while (1);

    return 0;
}
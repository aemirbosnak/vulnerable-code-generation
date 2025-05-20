#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    double data[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack *stack, double value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}

double pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

double calculate(char *expression) {
    Stack stack;
    initStack(&stack);

    char *token = strtok(expression, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && token[1] != '\0')) {
            push(&stack, atof(token));
        } else {
            double b = pop(&stack);
            double a = pop(&stack);
            switch (token[0]) {
                case '+':
                    push(&stack, a + b);
                    break;
                case '-':
                    push(&stack, a - b);
                    break;
                case '*':
                    push(&stack, a * b);
                    break;
                case '/':
                    push(&stack, a / b);
                    break;
                default:
                    printf("Invalid operator: %s\n", token);
                    exit(1);
            }
        }
        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s \"expression\"\n", argv[0]);
        return 1;
    }

    printf("%f\n", calculate(argv[1]));

    return 0;
}

//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 100

typedef struct {
    double data[MAX_STACK_SIZE];
    int top;
} Stack;

void stack_init(Stack *stack) {
    stack->top = -1;
}

int stack_is_empty(Stack *stack) {
    return stack->top == -1;
}

int stack_is_full(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void stack_push(Stack *stack, double value) {
    if (stack_is_full(stack)) {
        printf("Error: Stack overflow\n");
        return;
    }

    stack->data[++stack->top] = value;
}

double stack_pop(Stack *stack) {
    if (stack_is_empty(stack)) {
        printf("Error: Stack underflow\n");
        return 0.0;
    }

    return stack->data[stack->top--];
}

double stack_peek(Stack *stack) {
    if (stack_is_empty(stack)) {
        printf("Error: Stack underflow\n");
        return 0.0;
    }

    return stack->data[stack->top];
}

int main() {
    Stack stack;
    stack_init(&stack);

    char input[100];
    while (1) {
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "push") == 0) {
            double value;
            scanf("%lf", &value);
            stack_push(&stack, value);
            printf("Pushed %lf onto the stack\n", value);
        } else if (strcmp(input, "pop") == 0) {
            double value = stack_pop(&stack);
            printf("Popped %lf from the stack\n", value);
        } else if (strcmp(input, "peek") == 0) {
            double value = stack_peek(&stack);
            printf("Peeked at %lf on the stack\n", value);
        } else if (strcmp(input, "add") == 0) {
            double value1 = stack_pop(&stack);
            double value2 = stack_pop(&stack);
            double result = value1 + value2;
            stack_push(&stack, result);
            printf("Added %lf and %lf, result: %lf\n", value1, value2, result);
        } else if (strcmp(input, "subtract") == 0) {
            double value1 = stack_pop(&stack);
            double value2 = stack_pop(&stack);
            double result = value1 - value2;
            stack_push(&stack, result);
            printf("Subtracted %lf from %lf, result: %lf\n", value2, value1, result);
        } else if (strcmp(input, "multiply") == 0) {
            double value1 = stack_pop(&stack);
            double value2 = stack_pop(&stack);
            double result = value1 * value2;
            stack_push(&stack, result);
            printf("Multiplied %lf by %lf, result: %lf\n", value1, value2, result);
        } else if (strcmp(input, "divide") == 0) {
            double value1 = stack_pop(&stack);
            double value2 = stack_pop(&stack);
            double result = value1 / value2;
            stack_push(&stack, result);
            printf("Divided %lf by %lf, result: %lf\n", value1, value2, result);
        } else if (strcmp(input, "power") == 0) {
            double value1 = stack_pop(&stack);
            double value2 = stack_pop(&stack);
            double result = pow(value1, value2);
            stack_push(&stack, result);
            printf("Raised %lf to the power of %lf, result: %lf\n", value1, value2, result);
        } else if (strcmp(input, "sqrt") == 0) {
            double value = stack_pop(&stack);
            double result = sqrt(value);
            stack_push(&stack, result);
            printf("Square root of %lf: %lf\n", value, result);
        } else if (strcmp(input, "clear") == 0) {
            while (!stack_is_empty(&stack)) {
                stack_pop(&stack);
            }
            printf("Cleared the stack\n");
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}
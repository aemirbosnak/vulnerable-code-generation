#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10

typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

void init_stack(Stack *stack) {
    stack->top = -1;
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (stack->top == STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

int main() {
    char input[256];
    Stack stack;
    init_stack(&stack);

    fgets(input, sizeof(input), stdin);

    int i = 0;
    while (input[i] != '\0') {
        if (input[i] >= '0' && input[i] <= '9') {
            int num = 0;
            while (input[i] >= '0' && input[i] <= '9') {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            push(&stack, num);
        } else if (input[i] == ' ') {
            int op1 = pop(&stack);
            int op2 = pop(&stack);
            push(&stack, op1 + op2);
            i++;
        } else {
            printf("Invalid character: %c\n", input[i]);
            return 1;
        }
        i++;
    }

    printf("Result: %d\n", pop(&stack));
    return 0;
}

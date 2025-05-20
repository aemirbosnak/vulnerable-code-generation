//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    int arr[MAX_SIZE];
    int capacity;
    int top;
} Stack;

void init_stack(Stack *stack) {
    stack->capacity = MAX_SIZE;
    stack->top = -1;
}

int is_full(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (is_full(stack)) {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

void reverse_string(char *str) {
    Stack stack;
    init_stack(&stack);

    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        push(&stack, str[i]);
    }

    for (int i = 0; i < len / 2; ++i) {
        char temp = pop(&stack);
        str[len - i - 1] = temp;
        str[i] = pop(&stack);
    }
}

int main() {
    char input[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", input);

    reverse_string(input);
    printf("Reversed string: %s\n", input);

    return 0;
}
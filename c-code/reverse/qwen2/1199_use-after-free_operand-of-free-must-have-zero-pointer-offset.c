#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 1024

typedef struct {
    char data[MAX_STACK_SIZE];
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

void push(Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = item;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

int main() {
    char input[] = "int main() { if(x > y) { return x; } else { return y; } }";
    Stack stack;
    initStack(&stack);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{') {
            push(&stack, input[i]);
        } else if (input[i] == ')' || input[i] == ']' || input[i] == '}') {
            if (isEmpty(&stack)) {
                printf("Unbalanced: %c\n", input[i]);
            } else {
                char top = pop(&stack);
                if ((input[i] == ')' && top != '(') ||
                    (input[i] == ']' && top != '[') ||
                    (input[i] == '}' && top != '{')) {
                    printf("Mismatched: %c with %c\n", input[i], top);
                } else {
                    printf("Balanced: %c with %c\n", input[i], top);
                }
            }
        }
    }

    if (!isEmpty(&stack)) {
        printf("Unbalanced symbols left in stack\n");
    }

    return 0;
}

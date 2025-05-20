//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} node_t;

typedef struct stack {
    node_t* top;
} stack_t;

void push(stack_t* stack, int data) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(stack_t* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    int data = stack->top->data;
    node_t* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int peek(stack_t* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->top->data;
}

int isEmpty(stack_t* stack) {
    return stack->top == NULL;
}

int main() {
    stack_t stack;
    stack.top = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is: %d\n", peek(&stack));

    pop(&stack);
    printf("Top element after pop is: %d\n", peek(&stack));

    push(&stack, 40);
    printf("Size of the stack is: %d\n", stack.top->data);

    return 0;
}
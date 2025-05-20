//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure using linked list
typedef struct Stack {
    Node* top;
} Stack;

// Initialize an empty stack
void init(Stack* stack) {
    stack->top = NULL;
}

// Push an element onto the stack
void push(Stack* stack, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Stack overflow\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    Node* temp_node = stack->top;
    int data = temp_node->data;
    stack->top = temp_node->next;
    free(temp_node);
    return data;
}

// Peek at the top element of the stack
int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->top->data;
}

// Check if the stack is empty
bool is_empty(Stack* stack) {
    return stack->top == NULL;
}

// Main function to demonstrate stack operations
int main() {
    Stack stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    pop(&stack);
    pop(&stack);

    printf("Top element after popping twice: %d\n", peek(&stack));

    return 0;
}
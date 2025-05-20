//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack definition using linked list
typedef struct {
    Node* top;
} Stack;

// Initialize an empty stack
void init(Stack* stack) {
    stack->top = NULL;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    Node* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}

// Peek at the top element of the stack
int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    return stack->top->data;
}

// Check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Main function to demonstrate stack operations
int main() {
    Stack myStack;
    init(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element is: %d\n", peek(&myStack));

    pop(&myStack);
    pop(&myStack);

    printf("Top element after popping twice is: %d\n", peek(&myStack));

    if (isEmpty(&myStack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }

    return 0;
}
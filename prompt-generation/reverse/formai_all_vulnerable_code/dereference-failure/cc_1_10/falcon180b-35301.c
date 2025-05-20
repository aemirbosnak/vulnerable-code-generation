//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_SIZE 100

// Linked List Node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack Data Structure
typedef struct stack {
    Node* top;
    int size;
} Stack;

// Stack Functions
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(0);
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack* stack, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(0);
    }
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty\n");
        exit(0);
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty\n");
        exit(0);
    }
    return stack->top->data;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

int getSize(Stack* stack) {
    return stack->size;
}

void destroyStack(Stack* stack) {
    Node* temp = stack->top;
    while (temp!= NULL) {
        temp = temp->next;
        free(temp);
    }
    free(stack);
}

// Main Function
int main() {
    Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("Stack size: %d\n", getSize(stack));
    printf("Top element: %d\n", peek(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Stack size: %d\n", getSize(stack));
    printf("Is stack empty? %s\n", isEmpty(stack)? "Yes" : "No");
    destroyStack(stack);
    return 0;
}
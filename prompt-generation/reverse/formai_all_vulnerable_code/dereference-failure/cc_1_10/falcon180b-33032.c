//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in a linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a structure for a stack
typedef struct stack {
    int top;
    int capacity;
    Node* nodes;
} Stack;

// Function to create a new stack
Stack* createStack(int capacity) {
    Stack* stack = malloc(sizeof(Stack));
    stack->nodes = malloc(sizeof(Node) * capacity);
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

// Function to push a value onto the stack
void push(Stack* stack, int value) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->nodes[stack->top].data = value;
    stack->nodes[stack->top].next = NULL;
}

// Function to pop a value off the stack
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    int value = stack->nodes[stack->top].data;
    stack->top--;
    return value;
}

// Function to print the contents of the stack
void printStack(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->nodes[i].data);
    }
    printf("\n");
}

// Function to visualize the stack as a linked list
void visualizeStack(Stack* stack) {
    printf("Visualization of stack as a linked list:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d -> ", stack->nodes[i].data);
    }
    printf("NULL\n");
}

int main() {
    Stack* stack = createStack(5);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    printStack(stack);
    visualizeStack(stack);
    int popped = pop(stack);
    printf("Popped value: %d\n", popped);
    printStack(stack);
    visualizeStack(stack);
    return 0;
}
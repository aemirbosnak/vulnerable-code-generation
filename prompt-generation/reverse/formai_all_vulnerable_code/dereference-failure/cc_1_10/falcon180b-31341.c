//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a node structure for our linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a stack structure using linked lists
typedef struct stack {
    Node* top;
} Stack;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty stack
Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->top = NULL;
    return newStack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Function to push a node onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a node from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    Node* tempNode = stack->top;
    int poppedData = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);
    return poppedData;
}

// Function to print the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    Node* currentNode = stack->top;
    while (currentNode!= NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Main function to demonstrate the usage of our stack implementation
int main() {
    Stack* myStack = createStack();

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    printStack(myStack);

    int poppedData = pop(myStack);
    printf("Popped data: %d\n", poppedData);

    printStack(myStack);

    poppedData = pop(myStack);
    printf("Popped data: %d\n", poppedData);

    printStack(myStack);

    poppedData = pop(myStack);
    printf("Popped data: %d\n", poppedData);

    printStack(myStack);

    return 0;
}
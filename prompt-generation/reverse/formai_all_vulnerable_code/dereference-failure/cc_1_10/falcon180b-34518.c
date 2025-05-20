//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the node structure for the stack
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the stack structure
typedef struct {
    Node* top;
    int size;
} Stack;

// Create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a new empty stack
Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    if (newStack == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    newStack->top = NULL;
    newStack->size = 0;
    return newStack;
}

// Check if the stack is empty
bool isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Push a new node onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// Pop a node from the stack and return its data
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty!\n");
        exit(1);
    }
    Node* tempNode = stack->top;
    int data = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);
    stack->size--;
    return data;
}

// Print the current state of the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    Node* tempNode = stack->top;
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

// Main function
int main() {
    Stack* myStack = createStack();

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    push(myStack, 40);

    printStack(myStack);

    int poppedData = pop(myStack);
    printf("Popped data: %d\n", poppedData);

    printStack(myStack);

    return 0;
}
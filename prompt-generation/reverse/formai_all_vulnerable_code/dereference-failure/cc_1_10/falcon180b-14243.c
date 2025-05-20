//Falcon-180B DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure using linked list
typedef struct stack {
    Node* top;
} Stack;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty stack
Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    if (newStack == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newStack->top = NULL;
    return newStack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(0);
    }
    Node* tempNode = stack->top;
    int data = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);
    return data;
}

// Function to display the elements in the stack
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    Node* tempNode = stack->top;
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    display(stack);

    int poppedData = pop(stack);
    printf("Popped element: %d\n", poppedData);

    display(stack);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: standalone
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

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
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
    Node* tempNode = stack->top;
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prevNode = NULL;
    Node* currNode = head;
    while (currNode!= NULL) {
        Node* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}

// Main function to test the stack operations
int main() {
    Stack* myStack = (Stack*) malloc(sizeof(Stack));
    myStack->top = NULL;

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    printf("Original stack:\n");
    printStack(myStack);

    Node* reversedStack = reverseList(myStack->top);
    printf("Reversed stack:\n");
    while (reversedStack!= NULL) {
        printf("%d ", reversedStack->data);
        reversedStack = reversedStack->next;
    }
    printf("\n");

    int poppedData = pop(myStack);
    printf("Popped data: %d\n", poppedData);

    printf("Stack after popping:\n");
    printStack(myStack);

    free(myStack);
    return 0;
}
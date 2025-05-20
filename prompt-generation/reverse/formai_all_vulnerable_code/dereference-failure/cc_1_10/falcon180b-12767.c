//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a stack structure using linked lists
struct Stack {
    struct Node* top;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty stack
struct Stack* createStack() {
    struct Stack* newStack = (struct Stack*) malloc(sizeof(struct Stack));
    newStack->top = NULL;
    return newStack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push a value onto the stack
void push(struct Stack* stack, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a value from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* tempNode = stack->top;
    int poppedValue = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);
    return poppedValue;
}

// Function to print the stack
void printStack(struct Stack* stack) {
    struct Node* currNode = stack->top;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

int main() {
    struct Stack* myStack = createStack();

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    printStack(myStack);

    int poppedValue = pop(myStack);
    printf("Popped value: %d\n", poppedValue);

    printStack(myStack);

    return 0;
}
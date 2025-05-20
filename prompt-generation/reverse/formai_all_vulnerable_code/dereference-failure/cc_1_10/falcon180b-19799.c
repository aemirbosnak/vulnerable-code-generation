//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a stack structure using linked list
struct Stack {
    struct Node* top;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty stack
struct Stack* createStack() {
    struct Stack* newStack = (struct Stack*)malloc(sizeof(struct Stack));
    newStack->top = NULL;
    return newStack;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to print the elements in the stack
void printStack(struct Stack* stack) {
    struct Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printStack(stack);

    int poppedElement = pop(stack);
    printf("Popped element: %d\n", poppedElement);

    printStack(stack);

    return 0;
}
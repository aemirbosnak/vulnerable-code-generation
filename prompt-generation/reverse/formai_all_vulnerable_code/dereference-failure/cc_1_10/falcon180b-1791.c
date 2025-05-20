//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a stack structure
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

// Function to push a node onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a node from the stack
Node* pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return NULL;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    return temp;
}

// Function to print the stack
void printStack(Stack* stack) {
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    // Push some nodes onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Print the stack
    printStack(&stack);

    // Pop a node from the stack
    Node* poppedNode = pop(&stack);
    if (poppedNode!= NULL) {
        printf("Popped node: %d\n", poppedNode->data);
    }

    // Print the stack again
    printStack(&stack);

    return 0;
}
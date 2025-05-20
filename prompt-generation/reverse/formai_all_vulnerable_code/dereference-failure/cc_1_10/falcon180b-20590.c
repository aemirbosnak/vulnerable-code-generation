//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
} Stack;

// Function to create an empty stack
void createStack(Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmptyStack(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("Stack underflow\n");
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
    Node* tempNode = stack->top;
    if (isEmptyStack(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    // Create an empty stack
    Stack stack;
    createStack(&stack);

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    // Display the elements in the stack
    display(&stack);

    // Pop elements from the stack
    int poppedElement = pop(&stack);
    printf("Popped element is: %d\n", poppedElement);
    display(&stack);

    // Pop all elements from the stack
    while (!isEmptyStack(&stack)) {
        poppedElement = pop(&stack);
        printf("Popped element is: %d\n", poppedElement);
    }

    // Check if the stack is empty
    if (isEmptyStack(&stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}
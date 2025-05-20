//Falcon-180B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if (stack->top == NULL)
        return -1;
    Node* tempNode = stack->top;
    int poppedData = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);
    return poppedData;
}

// Function to display the current stack
void display(Stack* stack) {
    if (stack->top == NULL)
        printf("Stack is empty\n");
    else {
        printf("Stack elements are: ");
        Node* tempNode = stack->top;
        while (tempNode!= NULL) {
            printf("%d ", tempNode->data);
            tempNode = tempNode->next;
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    stack.top = NULL;

    // Test pushing elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);

    // Test popping elements from the stack
    int poppedElement1 = pop(&stack);
    int poppedElement2 = pop(&stack);
    display(&stack);

    // Test if stack is empty
    if (stack.top == NULL)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");

    return 0;
}
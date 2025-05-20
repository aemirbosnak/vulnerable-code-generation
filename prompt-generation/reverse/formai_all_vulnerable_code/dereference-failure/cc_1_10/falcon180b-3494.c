//Falcon-180B DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for linked list
struct node {
    int data;
    struct node* next;
};

// Define a stack structure with linked list implementation
struct stack {
    struct node* top;
};

// Function prototypes
void initStack(struct stack* stack);
int isEmpty(struct stack* stack);
void push(struct stack* stack, int data);
int pop(struct stack* stack);
void printStack(struct stack* stack);

int main() {
    // Initialize stack
    struct stack stack;
    initStack(&stack);

    // Push elements onto stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Print stack
    printStack(&stack);

    // Pop elements from stack
    int popped = pop(&stack);
    printf("Popped element: %d\n", popped);

    // Print stack again
    printStack(&stack);

    return 0;
}

// Function to initialize stack
void initStack(struct stack* stack) {
    stack->top = NULL;
}

// Function to check if stack is empty
int isEmpty(struct stack* stack) {
    return stack->top == NULL;
}

// Function to push element onto stack
void push(struct stack* stack, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop element from stack
int pop(struct stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    struct node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to print stack
void printStack(struct stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    struct node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
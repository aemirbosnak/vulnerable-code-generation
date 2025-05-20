//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a node structure for the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a stack structure using linked list
typedef struct stack {
    Node* top;
} Stack;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to print the stack
void printStack(Stack stack) {
    Node* temp = stack.top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the stack implementation
int main() {
    srand(time(NULL));
    Stack stack;
    stack.top = NULL;

    // Test push function
    for (int i = 0; i < 10; i++) {
        int data = rand() % 100;
        push(&stack, data);
        printf("Pushed: %d\n", data);
    }

    // Test print function
    printf("Stack: ");
    printStack(stack);

    // Test pop function
    for (int i = 0; i < 10; i++) {
        int data = pop(&stack);
        printf("Popped: %d\n", data);
    }

    // Test print function again
    printf("Stack after popping: ");
    printStack(stack);

    return 0;
}
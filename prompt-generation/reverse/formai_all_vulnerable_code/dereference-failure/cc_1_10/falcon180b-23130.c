//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the node structure for the stack
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define the stack structure
typedef struct {
    Node *top;
    int size;
} Stack;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Stack *stack, int data) {
    Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    int data = stack->top->data;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

// Function to display the elements in the stack
void display(Stack stack) {
    Node *temp = stack.top;
    printf("Stack elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the stack implementation
int main() {
    Stack stack;
    stack.top = NULL;
    stack.size = 0;

    // Test pushing elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    display(stack);

    // Test popping elements from the stack
    int poppedElement = pop(&stack);
    printf("Popped element is: %d\n", poppedElement);
    display(stack);

    // Test pushing more elements onto the stack
    push(&stack, 50);
    push(&stack, 60);
    push(&stack, 70);
    display(stack);

    // Test popping all elements from the stack
    while (stack.top!= NULL) {
        int poppedElement = pop(&stack);
        printf("Popped element is: %d\n", poppedElement);
    }

    return 0;
}
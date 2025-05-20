//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: shocked
// A unique C data structures visualization example program

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in the list
struct Node {
    int data;
    struct Node* next;
};

// Define a structure to represent a stack
struct Stack {
    struct Node* top;
    int size;
};

// Define a function to push an element onto the stack
void push(struct Stack* stack, int data) {
    // Create a new node to hold the data
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

// Define a function to pop an element from the stack
int pop(struct Stack* stack) {
    // Check if the stack is empty
    if (stack->size == 0) {
        return -1;
    }
    // Remove the top node from the stack
    struct Node* node = stack->top;
    stack->top = node->next;
    stack->size--;
    // Return the data stored in the popped node
    int data = node->data;
    free(node);
    return data;
}

// Define a function to display the stack
void display(struct Stack* stack) {
    // Check if the stack is empty
    if (stack->size == 0) {
        printf("Stack is empty\n");
        return;
    }
    // Display the data in each node
    struct Node* node = stack->top;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Define a function to free the stack
void freeStack(struct Stack* stack) {
    // Check if the stack is empty
    if (stack->size == 0) {
        return;
    }
    // Free each node in the stack
    struct Node* node = stack->top;
    while (node != NULL) {
        struct Node* next = node->next;
        free(node);
        node = next;
    }
    stack->top = NULL;
    stack->size = 0;
}

// Define a function to print the stack in reverse order
void printReverse(struct Stack* stack) {
    // Check if the stack is empty
    if (stack->size == 0) {
        printf("Stack is empty\n");
        return;
    }
    // Print the data in each node in reverse order
    struct Node* node = stack->top;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a stack
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->top = NULL;
    stack->size = 0;
    // Push some elements onto the stack
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    // Display the stack
    display(stack);
    // Pop an element from the stack
    int data = pop(stack);
    printf("Popped %d\n", data);
    // Display the stack again
    display(stack);
    // Free the stack
    freeStack(stack);
    // Print the stack in reverse order
    printReverse(stack);
    return 0;
}
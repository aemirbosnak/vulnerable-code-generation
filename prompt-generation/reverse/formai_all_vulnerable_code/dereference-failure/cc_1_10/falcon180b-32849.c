//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure for the linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define the stack structure
typedef struct stack {
    Node *top;
} Stack;

// Create a new node with the given data
Node* create_node(int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Push a node onto the stack
void push(Stack *stack, int data) {
    Node *node = create_node(data);
    node->next = stack->top;
    stack->top = node;
}

// Pop a node off the stack
Node* pop(Stack *stack) {
    Node *node = stack->top;
    stack->top = stack->top->next;
    return node;
}

// Print the stack
void print_stack(Stack *stack) {
    Node *node = stack->top;
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function to demonstrate the stack operations
int main() {
    Stack stack;
    stack.top = NULL;

    // Push some nodes onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Print the stack
    print_stack(&stack);

    // Pop a node off the stack
    Node *popped_node = pop(&stack);
    printf("Popped node: %d\n", popped_node->data);

    // Print the stack again
    print_stack(&stack);

    return 0;
}
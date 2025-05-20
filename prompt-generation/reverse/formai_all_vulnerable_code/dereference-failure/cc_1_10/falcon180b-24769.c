//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for linked lists
typedef struct node {
    void *data;
    struct node *next;
} Node;

// Stack structure using linked lists
typedef struct stack {
    Node *top;
} Stack;

// Function to create a new node
Node *create_node(void *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to push a node onto the stack
void push(Stack *stack, void *data) {
    Node *new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

// Function to pop a node from the stack
void *pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    Node *temp_node = stack->top;
    void *data = temp_node->data;
    stack->top = temp_node->next;
    free(temp_node);
    return data;
}

// Function to print the stack
void print_stack(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    Node *current_node = stack->top;
    while (current_node!= NULL) {
        printf("%p ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function to demonstrate the stack operations
int main() {
    Stack stack;
    stack.top = NULL;

    // Push some nodes onto the stack
    push(&stack, (void *)1);
    push(&stack, (void *)2);
    push(&stack, (void *)3);

    // Print the stack
    print_stack(&stack);

    // Pop a node from the stack
    void *popped_data = pop(&stack);
    printf("Popped data: %d\n", *(int *)popped_data);

    // Print the stack again
    print_stack(&stack);

    return 0;
}
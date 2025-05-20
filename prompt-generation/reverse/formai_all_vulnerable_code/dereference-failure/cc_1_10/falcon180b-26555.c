//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of a stack
typedef struct stack {
    Node* top;
} Stack;

// Create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Create a new empty stack
Stack* create_stack() {
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->top = NULL;
    return new_stack;
}

// Push a new node onto the top of the stack
void push(Stack* stack, int data) {
    Node* new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

// Pop the top node off of the stack and return its data
int pop(Stack* stack) {
    if (stack->top == NULL) {
        return -1;
    }
    int data = stack->top->data;
    Node* temp_node = stack->top;
    stack->top = stack->top->next;
    free(temp_node);
    return data;
}

// Print the current state of the stack
void print_stack(Stack* stack) {
    Node* current_node = stack->top;
    while (current_node!= NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function to test the stack implementation
int main() {
    Stack* my_stack = create_stack();
    push(my_stack, 10);
    push(my_stack, 20);
    push(my_stack, 30);
    push(my_stack, 40);
    print_stack(my_stack);
    printf("Popped: %d\n", pop(my_stack));
    print_stack(my_stack);
    printf("Popped: %d\n", pop(my_stack));
    print_stack(my_stack);
    printf("Popped: %d\n", pop(my_stack));
    print_stack(my_stack);
    printf("Popped: %d\n", pop(my_stack));
    print_stack(my_stack);
    return 0;
}
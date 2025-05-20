//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a stack structure using linked lists
typedef struct stack {
    Node* top;
} Stack;

// Initialize an empty stack
void init(Stack* s) {
    s->top = NULL;
}

// Push an integer onto the stack
void push(Stack* s, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

// Pop an integer off the stack
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty!\n");
        exit(1);
    }
    int data = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

// Print the top element of the stack
void peek(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is %d\n", s->top->data);
    }
}

// Check if the stack is empty
bool is_empty(Stack* s) {
    return s->top == NULL;
}

// Main function to demonstrate stack operations
int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Stack after pushing 10, 20, and 30:\n");
    peek(&s);

    pop(&s);

    printf("\nStack after popping an element:\n");
    peek(&s);

    pop(&s);
    pop(&s);

    if (is_empty(&s)) {
        printf("\nStack is now empty!\n");
    } else {
        printf("\nStack is not empty.\n");
    }

    return 0;
}
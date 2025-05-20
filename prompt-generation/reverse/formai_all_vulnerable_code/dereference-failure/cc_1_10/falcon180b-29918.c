//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define a stack data structure
typedef struct stack {
    Node *top;
    int size;
} Stack;

// Initialize a stack with a given size
void init(Stack *stack, int size) {
    stack->top = NULL;
    stack->size = size;
}

// Check if the stack is empty
int is_empty(Stack *stack) {
    return stack->top == NULL;
}

// Check if the stack is full
int is_full(Stack *stack) {
    return stack->top == NULL? 0 : 1;
}

// Push an element onto the stack
void push(Stack *stack, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

// Pop an element from the stack
int pop(Stack *stack) {
    Node *top = stack->top;
    int data = top->data;
    stack->top = top->next;
    free(top);
    return data;
}

// Peek at the top element in the stack
int peek(Stack *stack) {
    return stack->top->data;
}

// Print the stack
void print_stack(Stack *stack) {
    Node *top = stack->top;
    while (top!= NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    // Initialize a stack with a size of 5
    Stack stack;
    init(&stack, 5);

    // Test pushing elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    // Test popping elements from the stack
    int popped = pop(&stack);
    printf("Popped: %d\n", popped);

    // Test peeking at the top element in the stack
    int top = peek(&stack);
    printf("Top: %d\n", top);

    // Test printing the stack
    print_stack(&stack);

    // Test checking if the stack is empty
    int is_empty_result = is_empty(&stack);
    printf("Is stack empty? %s\n", is_empty_result? "Yes" : "No");

    // Test checking if the stack is full
    int is_full_result = is_full(&stack);
    printf("Is stack full? %s\n", is_full_result? "Yes" : "No");

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Stack structure
typedef struct Stack {
    int *array;     // Dynamic array to hold stack elements
    int top;        // Index of the top element
    int capacity;   // Maximum number of elements stack can hold
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        fprintf(stderr, "Memory allocation failed for stack.\n");
        exit(EXIT_FAILURE);
    }
    stack->capacity = capacity;
    stack->top = -1; // Initialize top index
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    if (!stack->array) {
        fprintf(stderr, "Memory allocation failed for stack array.\n");
        free(stack); // Clean up before exit
        exit(EXIT_FAILURE);
    }
    return stack;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to add an item to the stack
void push(Stack *stack, int item) {
    if (isFull(stack)) {
        fprintf(stderr, "Stack overflow: cannot push %d\n", item);
        return;
    }
    stack->array[++stack->top] = item; // Increment top and add item
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack underflow: cannot pop from empty stack\n");
        return -1; // Indicate failure
    }
    return stack->array[stack->top--]; // Return the top item and decrement top
}

// Function to peek at the top item of the stack without removing it
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack underflow: cannot peek from empty stack\n");
        return -1; // Indicate failure
    }
    return stack->array[stack->top];
}

// Function to free the stack and its resources
void freeStack(Stack *stack) {
    if (stack) {
        free(stack->array); // Free the array
        free(stack);        // Free the stack structure
    }
}

// Main function for testing the stack implementation
int main() {
    int capacity;
    
    // User-defined capacity for the stack
    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);

    Stack *stack = createStack(capacity); // Create a stack

    // Demonstrate stack operations
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d popped from stack\n", pop(stack));
    printf("Top item is %d\n", peek(stack));

    // Push more items
    push(stack, 40);
    push(stack, 50);

    // Try to pop all items
    while (!isEmpty(stack)) {
        printf("%d popped from stack\n", pop(stack));
    }

    // Attempt to pop from an empty stack
    pop(stack);

    // Clean up resources
    freeStack(stack);
    
    return 0;
}
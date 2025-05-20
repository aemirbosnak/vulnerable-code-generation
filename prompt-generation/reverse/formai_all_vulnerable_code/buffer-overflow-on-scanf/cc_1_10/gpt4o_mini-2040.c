//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 4

typedef struct {
    int *array;
    int top;
    int capacity;
} Stack;

// Function to create a stack of given initial size
Stack* createStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = INITIAL_SIZE;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Function to double the stack size when needed
void resizeStack(Stack *stack) {
    stack->capacity *= 2;
    stack->array = (int *)realloc(stack->array, stack->capacity * sizeof(int));
    if (!stack->array) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to add an item to the stack
void push(Stack *stack, int item) {
    if (isFull(stack)) {
        resizeStack(stack);
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to peek at the top item of the stack
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack is empty! Cannot peek.\n");
        return -1;
    }
    return stack->array[stack->top];
}

// Function to print the stack
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to free the stack
void freeStack(Stack *stack) {
    free(stack->array);
    free(stack);
}

int main() {
    Stack *stack = createStack();
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Print Stack\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                value = pop(stack);
                if (value != -1) {
                    printf("%d popped from stack\n", value);
                }
                break;
            case 3:
                value = peek(stack);
                if (value != -1) {
                    printf("Top value: %d\n", value);
                }
                break;
            case 4:
                printStack(stack);
                break;
            case 5:
                freeStack(stack);
                printf("Program exited. Stack memory freed.\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }
    return 0;
}
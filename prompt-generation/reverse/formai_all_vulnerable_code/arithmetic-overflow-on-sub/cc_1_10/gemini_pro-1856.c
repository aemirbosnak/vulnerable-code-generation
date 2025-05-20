//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to push an item to the stack
void push(struct Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full!\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, struct Stack* from, struct Stack* to, struct Stack* aux) {
    if (n == 1) {
        push(to, pop(from));
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    push(to, pop(from));
    towerOfHanoi(n - 1, aux, to, from);
}

// Function to print the contents of the stack
void printStack(struct Stack* stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Main function to test the program
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Create three stacks
    struct Stack* from = createStack(n);
    struct Stack* to = createStack(n);
    struct Stack* aux = createStack(n);

    // Push the disks onto the from stack
    for (int i = n; i >= 1; i--) {
        push(from, i);
    }

    // Print the initial state of the stacks
    printf("Initial state:\n");
    printf("From: ");
    printStack(from);
    printf("To: ");
    printStack(to);
    printf("Aux: ");
    printStack(aux);

    // Solve the Tower of Hanoi problem
    towerOfHanoi(n, from, to, aux);

    // Print the final state of the stacks
    printf("Final state:\n");
    printf("From: ");
    printStack(from);
    printf("To: ");
    printStack(to);
    printf("Aux: ");
    printStack(aux);

    return 0;
}
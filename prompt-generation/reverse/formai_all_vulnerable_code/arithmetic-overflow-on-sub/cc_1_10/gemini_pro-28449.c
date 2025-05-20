//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int *arr;
    int top;
    int capacity;
};

// Function to create a stack of given capacity
struct Stack* createStack(int capacity) {
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->arr = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to push an element into the stack
void push(struct Stack *stack, int data) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to print the stack
void printStack(struct Stack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Function to solve the Tower of Hanoi problem using 3 stacks
void towerOfHanoi(int n, struct Stack *source, struct Stack *destination, struct Stack *auxiliary) {
    // If there is only 1 disk, move it from the source to the destination
    if (n == 1) {
        push(destination, pop(source));
        return;
    }

    // Move n-1 disks from the source to the auxiliary tower
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Move the remaining disk from the source to the destination
    push(destination, pop(source));

    // Move n-1 disks from the auxiliary tower to the destination tower
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Driver code
int main() {
    // Create 3 stacks of capacity n
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    struct Stack *source = createStack(n);
    struct Stack *destination = createStack(n);
    struct Stack *auxiliary = createStack(n);

    // Initialize the source stack with n disks
    for (int i = n; i >= 1; i--) {
        push(source, i);
    }

    // Print the initial state of the stacks
    printf("Initial state of the stacks:\n");
    printf("Source: ");
    printStack(source);
    printf("Destination: ");
    printStack(destination);
    printf("Auxiliary: ");
    printStack(auxiliary);

    // Solve the Tower of Hanoi problem
    towerOfHanoi(n, source, destination, auxiliary);

    // Print the final state of the stacks
    printf("Final state of the stacks:\n");
    printf("Source: ");
    printStack(source);
    printf("Destination: ");
    printStack(destination);
    printf("Auxiliary: ");
    printStack(auxiliary);

    return 0;
}
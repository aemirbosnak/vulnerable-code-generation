//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Data structure to represent a stack
struct Stack {
    int *data;
    int top;
    int capacity;
};

// Function to create a stack of given capacity
struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->data = (int *)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to push an element to the stack
void push(struct Stack *stack, int element) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = element;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Function to move a disk from one stack to another
void moveDisk(struct Stack *from, struct Stack *to) {
    int disk = pop(from);
    push(to, disk);
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, struct Stack *from, struct Stack *to, struct Stack *aux) {
    if (n == 1) {
        moveDisk(from, to);
        return;
    }

    // Move n-1 disks from the source stack to the auxiliary stack
    towerOfHanoi(n - 1, from, aux, to);

    // Move the nth disk from the source stack to the destination stack
    moveDisk(from, to);

    // Move n-1 disks from the auxiliary stack to the destination stack
    towerOfHanoi(n - 1, aux, to, from);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Create three stacks to represent the source, destination, and auxiliary towers
    struct Stack *from = createStack(n);
    struct Stack *to = createStack(n);
    struct Stack *aux = createStack(n);

    // Push the disks onto the source stack
    for (int i = n; i >= 1; i--) {
        push(from, i);
    }

    // Solve the Tower of Hanoi problem
    towerOfHanoi(n, from, to, aux);

    // Print the final configuration of the destination stack
    printf("The final configuration of the destination stack is: ");
    while (to->top != -1) {
        printf("%d ", pop(to));
    }
    printf("\n");

    // Free the memory allocated for the stacks
    free(from->data);
    free(from);
    free(to->data);
    free(to);
    free(aux->data);
    free(aux);

    return 0;
}
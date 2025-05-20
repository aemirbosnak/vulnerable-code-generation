//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: standalone
#include "stdio.h"
#include "stdlib.h"
#define MAX_DISKS 100

// Structure to represent a stack
typedef struct Stack {
    int top;
    int capacity;
    int *array;
} Stack;

// Function to create a new stack
Stack* createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
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

// Function to push an element to the stack
void push(Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Error: Stack is full\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to move the top disk from one stack to another
void moveDisk(Stack *from, Stack *to) {
    int disk = pop(from);
    push(to, disk);
}

// Function to print the contents of the stack
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    int i;
    for (i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to perform the Tower of Hanoi algorithm
void towerOfHanoi(int n, Stack *from, Stack *to, Stack *aux) {
    // Base case: When there is only one disk, move it to the destination stack
    if (n == 1) {
        moveDisk(from, to);
        return;
    }

    // Recursive case:
    // 1. Move the top n-1 disks from the source stack to the auxiliary stack
    towerOfHanoi(n-1, from, aux, to);

    // 2. Move the remaining disk from the source stack to the destination stack
    moveDisk(from, to);

    // 3. Move the n-1 disks from the auxiliary stack to the destination stack
    towerOfHanoi(n-1, aux, to, from);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Create three stacks
    Stack *from = createStack(MAX_DISKS);
    Stack *to = createStack(MAX_DISKS);
    Stack *aux = createStack(MAX_DISKS);

    // Push the disks onto the source stack
    int i;
    for (i = n; i >= 1; i--) {
        push(from, i);
    }

    // Perform the Tower of Hanoi algorithm
    towerOfHanoi(n, from, to, aux);

    // Print the contents of the destination stack
    printf("The disks are now moved to the destination stack:\n");
    printStack(to);

    return 0;
}
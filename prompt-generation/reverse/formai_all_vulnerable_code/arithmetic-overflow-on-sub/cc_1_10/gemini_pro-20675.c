//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a stack
typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

// A utility function to create a stack of given capacity
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// A utility function to push a value onto a stack
void push(Stack* stack, int value) {
    stack->array[++stack->top] = value;
}

// A utility function to pop a value from a stack
int pop(Stack* stack) {
    return stack->array[stack->top--];
}

// A utility function to check if a stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// A utility function to check if a stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// A function to move a disk from the source stack to the destination stack
void moveDisk(Stack* source, Stack* destination) {
    // If the source stack is empty, then we can't move a disk
    if (isEmpty(source)) {
        printf("Cannot move a disk from an empty stack.\n");
        return;
    }

    // If the destination stack is full, then we can't move a disk
    if (isFull(destination)) {
        printf("Cannot move a disk to a full stack.\n");
        return;
    }

    // Move the top disk from the source stack to the destination stack
    int disk = pop(source);
    push(destination, disk);

    printf("Moved disk %d from stack %d to stack %d.\n", disk, source->top + 1, destination->top + 1);
}

// The main function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, Stack* source, Stack* auxiliary, Stack* destination) {
    // If there are no disks, then we are done
    if (n == 0) {
        return;
    }

    // Move the top n-1 disks from the source stack to the auxiliary stack
    towerOfHanoi(n-1, source, destination, auxiliary);

    // Move the remaining largest disk from the source stack to the destination stack
    moveDisk(source, destination);

    // Move the remaining n-1 disks from the auxiliary stack to the destination stack
    towerOfHanoi(n-1, auxiliary, source, destination);
}

// The main function that takes input from the user and solves the Tower of Hanoi problem
int main() {
    // Get the number of disks from the user
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Create three stacks to represent the source, auxiliary, and destination stacks
    Stack* source = createStack(n);
    Stack* auxiliary = createStack(n);
    Stack* destination = createStack(n);

    // Push the disks onto the source stack in order of decreasing size
    for (int i = n; i >= 1; i--) {
        push(source, i);
    }

    // Solve the Tower of Hanoi problem
    towerOfHanoi(n, source, auxiliary, destination);

    // Print the final state of the destination stack
    printf("The final state of the destination stack is:\n");
    while (!isEmpty(destination)) {
        printf("%d\n", pop(destination));
    }

    return 0;
}
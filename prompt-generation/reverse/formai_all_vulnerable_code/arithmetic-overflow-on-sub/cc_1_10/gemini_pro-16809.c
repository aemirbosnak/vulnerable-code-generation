//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
typedef struct Stack {
    int *arr;
    int top;
    int capacity;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to push an element to the stack
void push(Stack *stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to perform the Tower of Hanoi problem
void towerOfHanoi(int n, Stack *src, Stack *aux, Stack *dest) {
    // If there is only one disk, move it from source to destination
    if (n == 1) {
        push(dest, pop(src));
        return;
    }
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, src, dest, aux);
    // Move the largest disk from source to destination
    push(dest, pop(src));
    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, aux, src, dest);
}

// Driver program to test the Tower of Hanoi function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    Stack *src = createStack(n);
    Stack *aux = createStack(n);
    Stack *dest = createStack(n);
    for (int i = n; i >= 1; i--) {
        push(src, i);
    }
    towerOfHanoi(n, src, aux, dest);
    printf("The disks have been moved from source to destination\n");
    return 0;
}
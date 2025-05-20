//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
typedef struct Stack
{
    int top;
    unsigned capacity;
    int* array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(unsigned capacity)
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to push an item to the stack
void push(Stack* stack, int item)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("Stack is full\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(Stack* stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to print the contents of the stack
void printStack(Stack* stack)
{
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to perform the Tower of Hanoi iterative
void towerOfHanoi(int n, Stack* from, Stack* to, Stack* aux)
{
    // Base case: Only one disk
    if (n == 1)
    {
        push(to, pop(from));
        return;
    }

    // Move n-1 disks from 'from' to 'aux'
    towerOfHanoi(n-1, from, aux, to);

    // Move the nth disk from 'from' to 'to'
    push(to, pop(from));

    // Move n-1 disks from 'aux' to 'to'
    towerOfHanoi(n-1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Create three stacks
    Stack* from = createStack(n);
    Stack* to = createStack(n);
    Stack* aux = createStack(n);

    // Push disks onto the 'from' stack
    for (int i = n; i >= 1; i--)
    {
        push(from, i);
    }

    towerOfHanoi(n, from, to, aux);

    // Print the contents of the 'to' stack
    printf("The disks have been moved to the 'to' stack:\n");
    printStack(to);

    return 0;
}
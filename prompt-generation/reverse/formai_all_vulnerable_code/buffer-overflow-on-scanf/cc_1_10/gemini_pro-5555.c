//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of digits in a number
#define MAX_DIGITS 100

// Define the maximum number of elements in a stack
#define MAX_STACK_SIZE 100

// Define the stack data structure
typedef struct Stack {
    int top;
    int size;
    int *array;
} Stack;

// Create a new stack
Stack *createStack(int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->size = size;
    stack->array = (int *)malloc(stack->size * sizeof(int));
    return stack;
}

// Check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack *stack, int element) {
    if (stack->top == stack->size - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->array[++stack->top] = element;
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Peek at the top element of the stack
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->array[stack->top];
}

// Convert a number to its reverse using a stack
int reverseNumber(int number) {
    Stack *stack = createStack(MAX_DIGITS);
    int reversedNumber = 0;

    // Push each digit of the number onto the stack
    while (number > 0) {
        push(stack, number % 10);
        number /= 10;
    }

    // Pop each digit from the stack and append it to the reversed number
    while (!isEmpty(stack)) {
        reversedNumber = reversedNumber * 10 + pop(stack);
    }

    return reversedNumber;
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    int reversedNumber = reverseNumber(number);

    printf("The reverse of %d is %d\n", number, reversedNumber);

    return 0;
}
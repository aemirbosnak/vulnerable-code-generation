//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to push an item to the stack
void push(struct Stack* stack, char item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to convert decimal to binary
char* decimalToBinary(int n) {
    struct Stack* stack = createStack(100);
    int rem;
    while (n != 0) {
        rem = n % 2;
        push(stack, rem + '0');
        n /= 2;
    }
    char* binary = (char*)malloc(stack->top + 1);
    int i = 0;
    while (stack->top != -1) {
        binary[i++] = pop(stack);
    }
    binary[i] = '\0';
    return binary;
}

// Function to test the decimalToBinary function
int main() {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    char* binary = decimalToBinary(n);
    printf("Binary representation of %d is %s\n", n, binary);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the structure for the stack
typedef struct stack {
    int* data;
    int top;
    int size;
} Stack;

// Function to initialize the stack
void init(Stack* s) {
    s->data = (int*) malloc(MAX_SIZE * sizeof(int));
    s->top = -1;
    s->size = 0;
}

// Function to check if the stack is empty
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to check if the stack is full
bool isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack* s, int value) {
    if(isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
    s->size++;
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    int value = s->data[s->top];
    s->top--;
    s->size--;
    return value;
}

// Function to print the stack
void printStack(Stack* s) {
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for(int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// Main function to test the stack
int main() {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    printStack(&s);
    pop(&s);
    pop(&s);
    printStack(&s);
    return 0;
}
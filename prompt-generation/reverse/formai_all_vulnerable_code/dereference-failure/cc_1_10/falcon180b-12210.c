//Falcon-180B DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the structure of the stack
typedef struct {
    int *data;
    int top;
    int size;
} Stack;

// Create a new stack
Stack* create_stack() {
    Stack *s = (Stack*) malloc(sizeof(Stack));
    s->data = (int*) malloc(MAX_SIZE * sizeof(int));
    s->top = -1;
    s->size = MAX_SIZE;
    return s;
}

// Push an integer onto the stack
void push(Stack *s, int value) {
    if (s->top == s->size - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

// Pop an integer from the stack
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

// Print the contents of the stack
void print_stack(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Stack *s = create_stack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    print_stack(s);
    int x = pop(s);
    int y = pop(s);
    print_stack(s);
    push(s, 40);
    push(s, 50);
    print_stack(s);
    return 0;
}
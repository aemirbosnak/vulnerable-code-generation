//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    int capacity;
    int *stack;
} Stack;

// Function to initialize the stack
void init(Stack *s, int capacity) {
    s->top = -1;
    s->capacity = capacity;
    s->stack = (int *) malloc(capacity * sizeof(int));
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return (s->top == -1);
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return (s->top == s->capacity - 1);
}

// Function to push an integer onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d.\n", value);
        return;
    }
    s->stack[++s->top] = value;
}

// Function to pop an integer from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return s->stack[s->top--];
}

// Function to display the contents of the stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

int main() {
    int n, value;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    Stack source, destination, auxiliary;
    init(&source, n);
    init(&destination, n);
    init(&auxiliary, n);

    for (int i = n; i > 0; i--) {
        push(&source, i);
    }

    printf("Initial state:\n");
    display(&source);

    int moves = 0;
    while (!isEmpty(&source)) {
        printf("\nMove %d:\n", ++moves);
        moves += 2; // One move from source to auxiliary and one from auxiliary to destination

        push(&auxiliary, pop(&source));
        display(&auxiliary);

        if (!isEmpty(&destination)) {
            push(&destination, pop(&auxiliary));
            display(&destination);
        } else {
            push(&destination, pop(&auxiliary));
            display(&destination);
        }
    }

    printf("\nFinal state:\n");
    display(&destination);

    return 0;
}
//FormAI DATASET v1.0 Category: Data structures visualization ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// This program visualizes the stack data structure using different ASCII art styles.

#define STACK_SIZE 10 // Maximum size of the stack

int stack[STACK_SIZE]; // Array to hold the stack elements
int top = -1; // Top of the stack

// Function to check if the stack is empty
int is_empty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the stack is full
int is_full() {
    if (top == STACK_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to push an element to the top of the stack
void push(int element) {
    if (is_full()) {
        printf("Stack overflow!\n");
    } else {
        top++;
        stack[top] = element;
    }
}

// Function to pop an element from the top of the stack
int pop() {
    int element;
    if (is_empty()) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        element = stack[top];
        top--;
        return element;
    }
}

// Function to display the stack using an ASCII art style
void display_stack() {
    int i, j;
    printf("        _______\n");
    for (i = STACK_SIZE - 1; i >= 0; i--) {
        printf("%5d |", i);
        if (i <= top) {
            printf("  %3d  |\n", stack[i]);
        } else {
            printf("       |\n");
        }
    }
    printf("       ");
    for (j = 0; j < STACK_SIZE * 7; j++) {
        printf("_");
    }
    printf("\n        ");
    for (j = 0; j < STACK_SIZE; j++) {
        printf("%7d", j);
    }
    printf("\n\n");
}

int main() {
    int choice, element;
    while (1) {
        printf("1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Display stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                element = pop();
                if (element != -1) {
                    printf("Popped element: %d\n", element);
                }
                break;
            case 3:
                display_stack();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
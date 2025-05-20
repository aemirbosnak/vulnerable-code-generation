//FormAI DATASET v1.0 Category: Data structures visualization ; Style: high level of detail
// This program visualizes the working of a stack data structure using a text-based animation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10 // Maximum size of the stack

// Structure of the stack
typedef struct {
    int top;
    int items[MAX_SIZE];
} stack;

// Function to initialize the stack
void initialize_stack(stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
bool is_empty(stack *s) {
    return (s->top == -1);
}

// Function to check if the stack is full
bool is_full(stack *s) {
    return (s->top == MAX_SIZE - 1);
}

// Function to push an item to the stack
void push(stack *s, int value) {
    if (is_full(s)) {
        printf("\nStack Overflow!\n");
        exit(EXIT_FAILURE);
    }
    s->items[++s->top] = value;
    printf("\nPushed %d to the stack\n", value);
}

// Function to pop an item from the stack
void pop(stack *s) {
    if (is_empty(s)) {
        printf("\nStack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    int popped_value = s->items[s->top--];
    printf("\nPopped %d from the stack\n", popped_value);
}

// Function to display the stack
void display(stack *s) {
    if (is_empty(s)) {
        printf("\nThe stack is empty!\n");
        return;
    }
    printf("\nThe stack is:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
}

// Main function to run the program
int main() {
    stack s;
    initialize_stack(&s);

    char choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Push an item to the stack\n");
        printf("2. Pop an item from the stack\n");
        printf("3. Display the stack\n");
        printf("4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("\nEnter the value to push: ");
                int value;
                scanf("%d", &value);
                push(&s, value);
                break;
            case '2':
                pop(&s);
                break;
            case '3':
                display(&s);
                break;
            case '4':
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("\nInvalid choice!\n");
        }
        getchar(); // To clear the newline character in the buffer
    } while (choice != '4');

    return 0;
}
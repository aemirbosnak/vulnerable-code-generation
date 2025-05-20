//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the structure of the stack
typedef struct {
    int top;
    int *stack;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
    s->stack = (int *) malloc(MAX_SIZE * sizeof(int));
}

// Function to push an element onto the stack
void push(Stack *s, int element) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack is full! Cannot push %d\n", element);
        return;
    }
    s->top++;
    s->stack[s->top] = element;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty! Cannot pop\n");
        return -1;
    }
    int element = s->stack[s->top];
    s->top--;
    return element;
}

// Function to display the stack
void display(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice, element;
    Stack s;
    initStack(&s);

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push:\n");
                scanf("%d", &element);
                push(&s, element);
                break;
            case 2:
                element = pop(&s);
                if (element!= -1) {
                    printf("Popped element: %d\n", element);
                }
                break;
            case 3:
                display(&s);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again\n");
        }
    }

    return 0;
}
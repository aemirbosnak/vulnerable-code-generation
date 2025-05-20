//FormAI DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Define the struct for the data structure
typedef struct {
    int array[SIZE];
    int top;
} Stack;

// Function prototypes
void init(Stack *s);
void push(Stack *s, int item);
int pop(Stack *s);
void display(Stack s);

int main() {
    Stack s;
    int choice, item;

    // Initialize the stack
    init(&s);

    do {
        // Display the menu
        printf("\n\nStack Operations:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter item to push: ");
                scanf("%d", &item);
                push(&s, item);
                break;
            case 2:
                item = pop(&s);
                if (item != -1) {
                    printf("\nPopped item: %d", item);
                }
                break;
            case 3:
                display(s);
                break;
            case 4:
                printf("\nExiting the program!");
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while (choice != 4);

    return 0;
}

// Initialize the stack
void init(Stack *s) {
    s->top = -1;
}

// Push an item onto the stack
void push(Stack *s, int item) {
    if (s->top == SIZE - 1) {
        printf("\nStack overflow!");
        return;
    }
    s->top++;
    s->array[s->top] = item;
}

// Pop an item from the stack
int pop(Stack *s) {
    int item;
    if (s->top == -1) {
        printf("\nStack underflow!");
        return -1;
    }
    item = s->array[s->top];
    s->top--;
    return item;
}

// Display the stack
void display(Stack s) {
    int i;
    printf("\nStack contents: ");
    for (i = s.top; i >= 0; i--) {
        printf("\n%d", s.array[i]);
    }
}
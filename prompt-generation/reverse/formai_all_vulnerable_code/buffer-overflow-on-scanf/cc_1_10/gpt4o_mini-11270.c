//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 30
#define MAX_ITEMS 100

typedef struct Item {
    int id;
    char name[MAX_NAME_LEN];
} Item;

typedef struct Stack {
    Item items[MAX_ITEMS];
    int top;
} Stack;

// Function prototypes
void initializeStack(Stack *s);
int push(Stack *s, Item item);
int pop(Stack *s, Item *item);
void displayStack(Stack *s);
void visualizeStack(Stack *s);

int main() {
    Stack myStack;
    Item item;
    int choice;

    initializeStack(&myStack);

    do {
        printf("\n=== Stack Visualization Menu ===\n");
        printf("1. Push Item\n");
        printf("2. Pop Item\n");
        printf("3. Display Stack\n");
        printf("4. Visualize Stack\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &item.id);
                printf("Enter item name: ");
                scanf("%s", item.name);
                if (push(&myStack, item)) {
                    printf("Item pushed: %d, %s\n", item.id, item.name);
                } else {
                    printf("Stack overflow!\n");
                }
                break;

            case 2:
                if (pop(&myStack, &item)) {
                    printf("Item popped: %d, %s\n", item.id, item.name);
                } else {
                    printf("Stack underflow!\n");
                }
                break;

            case 3:
                displayStack(&myStack);
                break;

            case 4:
                visualizeStack(&myStack);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void initializeStack(Stack *s) {
    s->top = -1;
}

int push(Stack *s, Item item) {
    if (s->top < MAX_ITEMS - 1) {
        s->top++;
        s->items[s->top] = item;
        return 1;
    }
    return 0;
}

int pop(Stack *s, Item *item) {
    if (s->top >= 0) {
        *item = s->items[s->top];
        s->top--;
        return 1;
    }
    return 0;
}

void displayStack(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Current stack contents:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("Item ID: %d, Name: %s\n", s->items[i].id, s->items[i].name);
    }
}

void visualizeStack(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty. No visualization available.\n");
        return;
    }

    printf("\nVisualizing Stack:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("  +-----------+\n");
        printf("  | Item ID: %d |\n", s->items[i].id);
        printf("  | Name: %s |\n", s->items[i].name);
        printf("  +-----------+\n");
    }
    printf("       Bottom\n");
}
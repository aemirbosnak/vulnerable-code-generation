//FormAI DATASET v1.0 Category: Data structures visualization ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

typedef struct {
    int arr[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack *s, int value) {
    if (s->top == MAX_STACK_SIZE) {
        printf("Error: Stack overflow\n");
        return;
    }

    s->arr[s->top++] = value;
}

int pop(Stack *s) {
    if (s->top == 0) {
        printf("Error: Stack underflow\n");
        return -1;
    }

    return s->arr[--s->top];
}

void display(Stack s) {
    printf("Stack:\n");
    for (int i = s.top - 1; i >= 0; i--) {
        printf("| %2d |\n", s.arr[i]);
    }
    printf("+---+\n");
}

int main() {
    Stack s = { .top = 0 };
    int choice, value;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to push: ");
                scanf("%d", &value);
                push(&s, value);
                display(s);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                display(s);
                break;
            case 3:
                display(s);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        printf("\n");
    }

    return 0;
}
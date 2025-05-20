//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

void initialize(Stack* s) {
    s->top = -1;
}

bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int item) {
    if (isFull(s)) {
        printf("\033[1;31mStack Overflow: Cannot push %d\033[0m\n", item);
        return;
    }
    s->items[++(s->top)] = item;
    printf("\033[1;32mPushed %d onto the stack\033[0m\n", item);
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("\033[1;31mStack Underflow: Cannot pop from empty stack\033[0m\n");
        return -1; // Return -1 as an indication of error
    }
    int item = s->items[(s->top)--];
    printf("\033[1;34mPopped %d from the stack\033[0m\n", item);
    return item;
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("\033[1;33mThe stack is empty\033[0m\n");
        return;
    }
    printf("\033[1;36mStack contents:\033[0m\n");
    for (int i = s->top; i >= 0; i--) {
        printf("\033[1;37m| %d |\033[0m\n", s->items[i]);
        printf("\033[1;37m------\033[0m\n");
    }
    printf("\033[1;36mEnd of stack\033[0m\n");
}

int main() {
    Stack s;
    initialize(&s);
    int choice, value;

    while (true) {
        printf("\n\033[1;35m--- Stack Operations ---\033[0m\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("\033[1;32mExiting program. Bye!\033[0m\n");
                exit(0);
            default:
                printf("\033[1;31mInvalid choice! Please try again.\033[0m\n");
        }
    }

    return 0;
}
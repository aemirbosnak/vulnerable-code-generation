//Falcon-180B DATASET v1.0 Category: Recursive ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct stack {
    int top;
    int data[MAX_SIZE];
} Stack;

void push(Stack *s, int value) {
    if (s->top >= MAX_SIZE) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (s->top <= 0) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->data[s->top--];
}

int main() {
    Stack s;
    s.top = -1;

    int n, choice, value;

    printf("Enter the size of stack: ");
    scanf("%d", &n);

    printf("Enter 1 to push an element\nEnter 2 to pop an element\nEnter 3 to display the stack\nEnter 4 to exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(&s, value);
            break;

        case 2:
            value = pop(&s);
            if (value!= -1)
                printf("Popped value is %d\n", value);
            break;

        case 3:
            printf("Stack elements are: ");
            for (int i = s.top; i >= 0; i--)
                printf("%d ", s.data[i]);
            printf("\n");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}
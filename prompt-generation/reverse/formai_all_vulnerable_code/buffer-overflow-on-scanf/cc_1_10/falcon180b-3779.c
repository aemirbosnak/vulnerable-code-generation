//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = c;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->data[s->top--];
}

void display(Stack s) {
    if (s.top == -1)
        printf("Empty Stack");
    else
        printf("Stack Elements are: ");
    for (int i = s.top; i >= 0; i--)
        printf("%c", s.data[i]);
    printf("\n");
}

int main() {
    Stack s;
    s.top = -1;
    char choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
        case '1':
            printf("Enter the element to be pushed: ");
            char elem;
            scanf("%c", &elem);
            push(&s, elem);
            break;
        case '2':
            elem = pop(&s);
            if (elem!= '\0')
                printf("The popped element is %c\n", elem);
            break;
        case '3':
            display(s);
            break;
        case '4':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= '4');

    return 0;
}
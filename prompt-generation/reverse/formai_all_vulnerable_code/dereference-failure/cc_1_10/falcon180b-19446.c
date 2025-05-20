//Falcon-180B DATASET v1.0 Category: Educational ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000 // maximum size of the stack

typedef struct {
    int top;
    char *stack;
} Stack;

void init(Stack *s) {
    s->top = -1;
    s->stack = (char *) malloc(MAX_SIZE * sizeof(char));
    if (s->stack == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
}

void push(Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Error: Stack overflow.\n");
        exit(1);
    }
    s->top++;
    s->stack[s->top] = c;
}

void pop(Stack *s) {
    if (s->top == -1) {
        printf("Error: Stack underflow.\n");
        exit(1);
    }
    s->top--;
}

void print(Stack s) {
    printf("Stack: ");
    for (int i = s.top; i >= 0; i--) {
        printf("%c", s.stack[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    init(&s);

    push(&s, 'a');
    push(&s, 'b');
    push(&s, 'c');
    print(s);

    pop(&s);
    pop(&s);
    push(&s, 'd');
    push(&s, 'e');
    print(s);

    return 0;
}
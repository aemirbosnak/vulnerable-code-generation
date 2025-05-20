//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top >= MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

void reverseString(char *str) {
    Stack s;
    initializeStack(&s);
    int length = strlen(str);
    for (int i = 0; i < length; ++i) {
        push(&s, str[i]);
    }
    for (int i = 0; i < length; ++i) {
        str[i] = pop(&s);
    }
}

int main() {
    char input[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", input);
    reverseString(input);
    printf("Reversed string: %s\n", input);
    return 0;
}
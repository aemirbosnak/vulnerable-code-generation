//Falcon-180B DATASET v1.0 Category: Recursive ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    int capacity;
    int *stack;
} Stack;

void init_stack(Stack *s, int capacity) {
    s->top = -1;
    s->capacity = capacity;
    s->stack = (int *)malloc(sizeof(int) * capacity);
}

void push(Stack *s, int value) {
    if (s->top == s->capacity - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->top++;
    s->stack[s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    int value = s->stack[s->top];
    s->top--;
    return value;
}

void print_stack(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

void reverse_string(char *str) {
    int length = strlen(str);
    Stack s;
    init_stack(&s, length);
    for (int i = 0; i < length; i++) {
        push(&s, str[i]);
    }
    char reversed[length + 1];
    reversed[length] = '\0';
    for (int i = 0; i < length; i++) {
        reversed[i] = pop(&s);
    }
    strcpy(str, reversed);
}

int main() {
    char str[MAX_STACK_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Original string: %s\n", str);
    reverse_string(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char* name;
    int size;
    int top;
    int* stack;
} Stack;

void init(Stack* s) {
    s->name = (char*) malloc(sizeof(char) * 10);
    strcpy(s->name, "Stack");
    s->size = MAX_SIZE;
    s->top = -1;
    s->stack = (int*) malloc(sizeof(int) * s->size);
}

void push(Stack* s, int value) {
    if (s->top == s->size - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->stack[s->top] = value;
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    int value = s->stack[s->top];
    s->top--;
    return value;
}

void display(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: %s\n", s->name);
    printf("Top element: %d\n", s->stack[s->top]);
    printf("Stack size: %d\n", s->size);
}

int main() {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);
    pop(&s);
    pop(&s);
    display(&s);
    return 0;
}
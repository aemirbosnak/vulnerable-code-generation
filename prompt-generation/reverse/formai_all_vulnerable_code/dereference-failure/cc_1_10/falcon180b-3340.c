//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
} Stack;

void init(Stack *s) {
    s->top = NULL;
}

int is_empty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        printf("Stack overflow\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    Node *temp = s->top;
    int data = s->top->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

int peek(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->top->data;
}

void print_stack(Stack *s) {
    Node *temp = s->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    print_stack(&s);
    printf("Top element is %d\n", peek(&s));
    pop(&s);
    print_stack(&s);
    return 0;
}
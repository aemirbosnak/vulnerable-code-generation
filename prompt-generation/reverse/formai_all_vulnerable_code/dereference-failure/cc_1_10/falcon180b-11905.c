//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: thoughtful
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
    int size;
} Stack;

void init(Stack *s) {
    s->top = NULL;
    s->size = 0;
}

int is_empty(Stack *s) {
    return s->top == NULL;
}

int is_full(Stack *s) {
    return s->size == MAX_SIZE;
}

void push(Stack *s, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Stack overflow\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    int data = s->top->data;
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
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
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }
    Node *current = s->top;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    print_stack(&s);
    printf("Top element: %d\n", peek(&s));
    printf("Popped element: %d\n", pop(&s));
    print_stack(&s);
    printf("Top element: %d\n", peek(&s));
    printf("Popped element: %d\n", pop(&s));
    print_stack(&s);
    printf("Top element: %d\n", peek(&s));
    return 0;
}
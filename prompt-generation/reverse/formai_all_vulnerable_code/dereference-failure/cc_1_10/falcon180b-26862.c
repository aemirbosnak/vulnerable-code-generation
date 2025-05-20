//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: puzzling
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

void push(Stack *s, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

int pop(Stack *s) {
    int data = s->top->data;
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return data;
}

int main() {
    Stack s;
    s.top = NULL;
    s.size = 0;

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    printf("Stack size: %d\n", s.size);
    printf("Stack elements: ");

    while (s.top!= NULL) {
        printf("%d ", pop(&s));
    }

    printf("\n");
    return 0;
}
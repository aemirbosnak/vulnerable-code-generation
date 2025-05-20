//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
    int size;
} Stack;

void init_stack(Stack *s) {
    s->top = NULL;
    s->size = 0;
}

int is_empty(Stack *s) {
    return s->top == NULL;
}

int push(Stack *s, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    node->data = data;
    node->next = s->top;
    s->top = node;
    s->size++;
    return 1;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    Node *node = s->top;
    s->top = s->top->next;
    s->size--;
    free(node);
    return node->data;
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
        exit(1);
    }
    Node *node = s->top;
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    init_stack(&s);

    int choice, data;
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(&s, data);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                data = peek(&s);
                if (data!= -1) {
                    printf("Top element is %d\n", data);
                }
                break;
            case 4:
                print_stack(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
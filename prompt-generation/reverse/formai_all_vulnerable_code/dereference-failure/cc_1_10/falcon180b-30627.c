//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
} Stack;

void push(Stack* stack, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (stack->top == NULL) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top = newNode;
    }
}

int pop(Stack* stack) {
    int data = -1;

    if (stack->top!= NULL) {
        data = stack->top->data;
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }

    return data;
}

void display(Stack* stack) {
    Node* temp = stack->top;

    printf("Stack: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    printf("Stack after pushing 4 elements: ");
    display(&stack);

    int poppedElement = pop(&stack);
    printf("Popped element: %d\n", poppedElement);

    printf("Stack after popping an element: ");
    display(&stack);

    return 0;
}
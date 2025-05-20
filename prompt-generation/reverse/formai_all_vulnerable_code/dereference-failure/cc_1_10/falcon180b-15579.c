//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

Stack *createStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack *stack, int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    int data = stack->top->data;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

int peek(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->top->data;
}

int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

int isFull(Stack *stack) {
    return stack->size == MAX_SIZE;
}

void printStack(Stack *stack) {
    Node *temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack *stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    printStack(stack);
    printf("Top element is: %d\n", peek(stack));
    pop(stack);
    pop(stack);
    printStack(stack);
    printf("Stack size is: %d\n", stack->size);
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
    free(stack);
    return 0;
}
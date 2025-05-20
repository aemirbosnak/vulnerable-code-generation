//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
    int size;
} Stack;

Stack* create_stack() {
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->top = NULL;
    new_stack->size = 0;
    return new_stack;
}

void push(Stack* stack, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

void print_stack(Stack* stack) {
    Node* temp = stack->top;
    printf("Stack: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = create_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    print_stack(stack);
    printf("Size of stack: %d\n", stack->size);
    printf("Top element: %d\n", peek(stack));
    pop(stack);
    print_stack(stack);
    printf("Size of stack: %d\n", stack->size);
    return 0;
}
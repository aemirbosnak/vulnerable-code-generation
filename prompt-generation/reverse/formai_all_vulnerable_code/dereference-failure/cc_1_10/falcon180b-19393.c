//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

// Stack structure using linked list
typedef struct stack {
    Node* top;
} Stack;

// Stack functions
Stack* createStack() {
    Stack* newStack = (Stack*) malloc(sizeof(Stack));
    if (newStack == NULL) {
        printf("Error: Memory could not be allocated for stack.\n");
        return NULL;
    }
    newStack->top = NULL;
    return newStack;
}

void push(Stack* stack, char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory could not be allocated for node.\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty.\n");
        return '\0';
    }
    char data = stack->top->data;
    Node* tempNode = stack->top;
    stack->top = stack->top->next;
    free(tempNode);
    return data;
}

void display(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    Node* tempNode = stack->top;
    while (tempNode!= NULL) {
        printf("%c ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    Stack* myStack = createStack();
    if (myStack == NULL) {
        return 1;
    }

    push(myStack, 'a');
    push(myStack, 'b');
    push(myStack, 'c');

    display(myStack);

    char poppedElement = pop(myStack);
    printf("Popped element: %c\n", poppedElement);

    display(myStack);

    free(myStack);
    return 0;
}
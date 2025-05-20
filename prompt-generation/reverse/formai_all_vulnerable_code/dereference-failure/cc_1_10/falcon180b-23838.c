//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
    int size;
} Stack;

Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->top = NULL;
    newStack->size = 0;
    return newStack;
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
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
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->top->data;
}

void printStack(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack* myStack = createStack();
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    push(myStack, 40);
    push(myStack, 50);

    printf("Stack after pushing elements:\n");
    printStack(myStack);

    int poppedElement = pop(myStack);
    printf("Popped element: %d\n", poppedElement);

    printf("Stack after popping an element:\n");
    printStack(myStack);

    int peekedElement = peek(myStack);
    printf("Peeked element: %d\n", peekedElement);

    return 0;
}
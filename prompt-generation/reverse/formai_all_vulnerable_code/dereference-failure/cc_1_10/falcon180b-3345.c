//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Node structure definition
typedef struct node {
    char data[50];
    struct node* next;
} Node;

// Stack structure definition using linked list
typedef struct {
    Node* top;
} Stack;

// Function declarations
Stack* createStack(void);
void push(Stack* stack, char* value);
char* pop(Stack* stack);
bool isEmpty(Stack* stack);
void printStack(Stack* stack);

int main() {
    Stack* myStack = createStack();

    push(myStack, "Hello");
    push(myStack, "World");

    printStack(myStack);

    char* value = pop(myStack);
    printf("Popped value: %s\n", value);

    printStack(myStack);

    return 0;
}

// Function to create an empty stack
Stack* createStack(void) {
    Stack* newStack = (Stack*) malloc(sizeof(Stack));
    newStack->top = NULL;
    return newStack;
}

// Function to push a value onto the stack
void push(Stack* stack, char* value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->data, value);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a value off the stack
char* pop(Stack* stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty.\n");
        return NULL;
    }

    char* value = stack->top->data;
    Node* tempNode = stack->top;
    stack->top = stack->top->next;
    free(tempNode);

    return value;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to print the stack
void printStack(Stack* stack) {
    Node* currentNode = stack->top;
    while(currentNode!= NULL) {
        printf("%s ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}
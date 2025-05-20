//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure definition
typedef struct node {
    char data;
    struct node* next;
} Node;

// Stack structure definition
typedef struct {
    Node* top;
} Stack;

// Function to create a new node with given data
Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(Stack* stack, char data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a node from the stack
char pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    char data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to print the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        Node* temp = stack->top;
        while (temp!= NULL) {
            printf("%c ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    stack.top = NULL;

    push(&stack, 'a');
    push(&stack, 'b');
    push(&stack, 'c');

    printStack(&stack);

    char poppedData = pop(&stack);
    printf("Popped data: %c\n", poppedData);

    printStack(&stack);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a node structure for linked lists
typedef struct node {
    char data;
    struct node* next;
} Node;

// Define a stack structure using linked lists
typedef struct stack {
    Node* top;
} Stack;

// Create an empty stack
void createStack(Stack* s) {
    s->top = NULL;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Push a character onto the stack
void push(Stack* s, char c) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = c;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop a character from the stack
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    char c = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return c;
}

// Reverse a string using a stack
void reverseString(char* str) {
    int len = strlen(str);
    Stack stack;
    createStack(&stack);
    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }
    char* reversed = (char*) malloc(sizeof(char) * len);
    int j = 0;
    while (!isEmpty(&stack)) {
        reversed[j++] = pop(&stack);
    }
    reversed[j] = '\0';
    printf("Reversed string: %s\n", reversed);
}

// Main function
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    reverseString(str);
    return 0;
}
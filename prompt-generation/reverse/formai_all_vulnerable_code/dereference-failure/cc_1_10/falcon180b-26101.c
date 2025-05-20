//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for a linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a stack structure
typedef struct {
    Node* top;
} Stack;

// Initialize an empty stack
void init(Stack* s) {
    s->top = NULL;
}

// Push an element onto the stack
void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop an element off the stack
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    int data = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

// Check if the stack is empty
bool isEmpty(Stack* s) {
    return s->top == NULL;
}

// Print the stack
void printStack(Stack* s) {
    Node* temp = s->top;
    printf("Stack: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printStack(&s);
    printf("Popped element: %d\n", pop(&s));
    printStack(&s);
    printf("Popped element: %d\n", pop(&s));
    printStack(&s);
    printf("Popped element: %d\n", pop(&s));
    printf("Is stack empty? %s\n", isEmpty(&s)? "Yes" : "No");
    return 0;
}
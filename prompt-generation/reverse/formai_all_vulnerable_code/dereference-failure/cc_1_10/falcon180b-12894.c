//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the structure of a stack node
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Define the structure of a stack
typedef struct Stack {
    StackNode* top;
    int size;
} Stack;

// Initialize an empty stack
void init(Stack* s) {
    s->top = NULL;
    s->size = 0;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->size == 0;
}

// Push an element onto the stack
void push(Stack* s, int data) {
    StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

// Pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    StackNode* temp = s->top;
    int data = temp->data;
    s->top = temp->next;
    free(temp);
    s->size--;
    return data;
}

// Print the elements of the stack
void print(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    StackNode* temp = s->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the stack operations
int main() {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    print(&s);
    pop(&s);
    pop(&s);
    print(&s);
    return 0;
}
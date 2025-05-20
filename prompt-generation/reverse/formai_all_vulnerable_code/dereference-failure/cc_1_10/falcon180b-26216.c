//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the structure of the stack
typedef struct {
    int data;
    struct stackNode* next;
} stackNode;

// Define the structure of the stack
typedef struct {
    stackNode* top;
    int size;
} stack;

// Initialize the stack
void init(stack* s) {
    s->top = NULL;
    s->size = 0;
}

// Push an element onto the stack
void push(stack* s, int data) {
    stackNode* newNode = (stackNode*) malloc(sizeof(stackNode));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

// Pop an element from the stack
int pop(stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    stackNode* temp = s->top;
    int data = s->top->data;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return data;
}

// Display the stack
void display(stack* s) {
    stackNode* temp = s->top;
    printf("Stack: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);
    int poppedElement = pop(&s);
    printf("Popped element: %d\n", poppedElement);
    display(&s);
    return 0;
}
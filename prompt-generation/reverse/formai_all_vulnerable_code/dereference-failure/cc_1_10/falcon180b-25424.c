//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_STACK_SIZE 100

// Define the structure of a stack node
typedef struct {
    int data;
    struct node* next;
} Node;

// Define the stack structure
typedef struct {
    Node* top;
    int size;
} Stack;

// Initialize the stack
void init(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return data;
}

// Display the stack
void display(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Stack stack;
    init(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    display(&stack);
    pop(&stack);
    display(&stack);
    pop(&stack);
    display(&stack);
    pop(&stack);
    display(&stack);
    pop(&stack);
    display(&stack);
    pop(&stack);
    return 0;
}
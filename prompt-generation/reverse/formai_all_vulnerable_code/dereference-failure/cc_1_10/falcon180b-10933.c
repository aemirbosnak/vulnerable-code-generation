//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the node structure for the linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define the stack structure using linked list
typedef struct stack {
    Node *top;
} Stack;

// Function to create a new node with given data
Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to push a node onto the stack
void push(Stack *stack, int data) {
    Node *new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

// Function to pop a node from the stack
int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to display the stack
void display(Stack stack) {
    Node *temp = stack.top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    // Test the push function
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(stack);

    // Test the pop function
    int popped_data = pop(&stack);
    printf("Popped data: %d\n", popped_data);
    display(stack);

    // Test edge cases
    push(&stack, 40);
    push(&stack, 50);
    display(stack);

    popped_data = pop(&stack);
    printf("Popped data: %d\n", popped_data);
    popped_data = pop(&stack);
    printf("Popped data: %d\n", popped_data);
    popped_data = pop(&stack);
    printf("Popped data: %d\n", popped_data);
    popped_data = pop(&stack);
    printf("Popped data: %d\n", popped_data);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure definition for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure definition using linked list
typedef struct stack {
    Node* top;
} Stack;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to print the stack elements
void print_stack(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse a given string
void reverse_string(char* str) {
    int length = strlen(str);
    char* reversed = (char*) malloc((length + 1) * sizeof(char));
    if (reversed == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    int i, j;
    for (i = length - 1, j = 0; i >= 0; i--, j++) {
        reversed[j] = str[i];
    }
    reversed[length] = '\0';
    printf("Reversed string is: %s\n", reversed);
    free(reversed);
}

// Main function
int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    reverse_string(str);
    Stack stack;
    stack.top = NULL;
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    print_stack(&stack);
    pop(&stack);
    pop(&stack);
    print_stack(&stack);
    return 0;
}
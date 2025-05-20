//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define a node for the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a stack using linked lists
typedef struct stack {
    Node* top;
} Stack;

// Initialize an empty stack
void init(Stack* s) {
    s->top = NULL;
}

// Push an element onto the stack
void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop an element from the stack
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    int data = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Print the stack
void print(Stack* s) {
    Node* temp = s->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse a string using a stack
void reverseString(char* str) {
    int length = strlen(str);
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    init(stack);
    for (int i = 0; i < length; i++) {
        push(stack, str[i]);
    }
    char* reversed = (char*)malloc((length + 1) * sizeof(char));
    int index = 0;
    while (!isEmpty(stack)) {
        reversed[index++] = pop(stack);
    }
    reversed[index] = '\0';
    printf("Reversed string: %s\n", reversed);
    free(reversed);
    free(stack);
}

// Main function
int main() {
    char* input = "Hello, World!";
    printf("Original string: %s\n", input);
    reverseString(input);
    return 0;
}
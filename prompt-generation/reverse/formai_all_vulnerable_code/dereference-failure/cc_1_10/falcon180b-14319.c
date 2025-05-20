//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a node structure for the linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

// Define a stack structure using linked lists
typedef struct stack {
    Node* top;
} Stack;

// Initialize an empty stack
void init(Stack* s) {
    s->top = NULL;
}

// Check if the stack is empty
int is_empty(Stack* s) {
    return s->top == NULL;
}

// Add an element to the top of the stack
void push(Stack* s, char c) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = c;
    new_node->next = s->top;
    s->top = new_node;
}

// Remove and return the top element from the stack
char pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    char c = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return c;
}

// Print the stack elements in reverse order
void print_stack(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = s->top;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse a string using a stack
void reverse_string(char* str) {
    int len = strlen(str);
    Stack s;
    init(&s);
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }
    char* reversed = (char*)malloc(len + 1);
    int j = 0;
    while (!is_empty(&s)) {
        reversed[j++] = pop(&s);
    }
    reversed[j] = '\0';
    strcpy(str, reversed);
    free(reversed);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    reverse_string(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Stack structure using linked list
typedef struct stack {
    Node *top;
} Stack;

// Function to create an empty stack
Stack *create_stack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    s->top = NULL;
    return s;
}

// Function to push an integer onto the stack
void push(Stack *s, int data) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newnode->data = data;
    newnode->next = s->top;
    s->top = newnode;
}

// Function to pop an integer from the stack
int pop(Stack *s) {
    Node *temp = s->top;
    int data;
    if (temp == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}

// Function to display the contents of the stack
void display(Stack *s) {
    Node *temp = s->top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack *s = create_stack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    display(s);
    pop(s);
    pop(s);
    display(s);
    return 0;
}
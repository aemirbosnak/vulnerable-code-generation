//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a stack structure
typedef struct stack {
    Node* top;
    int size;
} Stack;

// Initialize a stack
void init(Stack* s) {
    s->top = NULL;
    s->size = 0;
}

// Push an element onto the stack
void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

// Pop an element from the stack
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return data;
}

// Display the stack
void display(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = s->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse the stack
void reverse(Stack* s) {
    Node* prev = NULL;
    Node* curr = s->top;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    s->top = prev;
}

int main() {
    Stack s;
    init(&s);
    push(&s, 5);
    push(&s, 7);
    push(&s, 9);
    display(&s);
    reverse(&s);
    display(&s);
    int popped = pop(&s);
    printf("Popped element: %d\n", popped);
    display(&s);
    return 0;
}
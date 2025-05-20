//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define stack structure
typedef struct stack {
    Node* top;
    int size;
} Stack;

// Initialize stack
void init(Stack* s) {
    s->top = NULL;
    s->size = 0;
}

// Push element onto stack
void push(Stack* s, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

// Pop element from stack
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    int data = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return data;
}

// Display stack contents
void display(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = s->top;
    printf("Stack elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse stack
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

// Main function
int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(&s);

    reverse(&s);

    display(&s);

    pop(&s);
    pop(&s);

    display(&s);

    return 0;
}
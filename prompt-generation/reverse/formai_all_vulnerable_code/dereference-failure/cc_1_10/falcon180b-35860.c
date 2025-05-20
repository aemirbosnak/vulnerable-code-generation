//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the stack structure
typedef struct stack {
    Node* top;
    int size;
} Stack;

// Initialize the stack
void init(Stack* s) {
    s->top = NULL;
    s->size = 0;
}

// Push an element onto the stack
void push(Stack* s, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

// Pop an element from the stack
int pop(Stack* s) {
    Node* temp_node = s->top;
    int data = temp_node->data;
    s->top = temp_node->next;
    free(temp_node);
    s->size--;
    return data;
}

// Check if the stack is empty
bool is_empty(Stack* s) {
    return s->top == NULL;
}

// Print the stack
void print_stack(Stack* s) {
    Node* current_node = s->top;
    while (current_node!= NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Reverse the stack
void reverse_stack(Stack* s) {
    Node* prev_node = NULL;
    Node* current_node = s->top;
    while (current_node!= NULL) {
        Node* next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    s->top = prev_node;
}

int main() {
    Stack s;
    init(&s);

    printf("Pushing elements onto the stack:\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    print_stack(&s);

    printf("Popping elements from the stack:\n");
    int popped_element = pop(&s);
    printf("Popped element: %d\n", popped_element);
    print_stack(&s);

    printf("Reversing the stack:\n");
    reverse_stack(&s);
    print_stack(&s);

    printf("Popping elements from the reversed stack:\n");
    popped_element = pop(&s);
    printf("Popped element: %d\n", popped_element);
    print_stack(&s);

    return 0;
}
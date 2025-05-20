//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
    int size;
} Stack;

Stack* create_stack() {
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    if (new_stack == NULL) {
        printf("Error: Failed to allocate memory for stack.\n");
        exit(1);
    }
    new_stack->top = NULL;
    new_stack->size = 0;
    return new_stack;
}

void push(Stack* stack, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Failed to allocate memory for node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    int data = stack->top->data;
    Node* temp_node = stack->top;
    stack->top = stack->top->next;
    free(temp_node);
    stack->size--;
    return data;
}

int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    return stack->top->data;
}

int is_empty(Stack* stack) {
    return stack->top == NULL;
}

void print_stack(Stack* stack) {
    Node* curr_node = stack->top;
    while (curr_node!= NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

int main() {
    Stack* my_stack = create_stack();

    push(my_stack, 1);
    push(my_stack, 2);
    push(my_stack, 3);

    print_stack(my_stack);

    int popped_value = pop(my_stack);
    printf("Popped value: %d\n", popped_value);

    print_stack(my_stack);

    int peeked_value = peek(my_stack);
    printf("Peeked value: %d\n", peeked_value);

    return 0;
}
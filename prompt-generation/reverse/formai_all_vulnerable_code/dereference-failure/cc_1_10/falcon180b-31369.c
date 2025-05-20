//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
#include <stdio.h>

// Define a node structure for linked list
struct node {
    int data;
    struct node* next;
};

// Define a stack structure using linked list
struct stack {
    struct node* top;
};

// Function to create a new node with given data
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory error\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to push an element onto the stack
void push(struct stack* stack, int data) {
    struct node* new_node = create_node(data);
    if (new_node == NULL)
        return;
    new_node->next = stack->top;
    stack->top = new_node;
}

// Function to pop an element from the stack
int pop(struct stack* stack) {
    if (stack->top == NULL)
        return -1;
    int data = stack->top->data;
    struct node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to print the elements in the stack
void print_stack(struct stack* stack) {
    struct node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate the usage of stack data structure
int main() {
    struct stack stack;
    stack.top = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Stack elements:\n");
    print_stack(&stack);

    int popped_element = pop(&stack);
    printf("Popped element: %d\n", popped_element);

    printf("Stack elements after popping:\n");
    print_stack(&stack);

    return 0;
}
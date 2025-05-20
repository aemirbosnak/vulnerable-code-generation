//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/* Define a node structure for our linked list */
typedef struct node {
    void* data;
    struct node* next;
} Node;

/* Define a stack structure using linked lists */
typedef struct stack {
    Node* top;
} Stack;

/* Initialize an empty stack */
void stack_init(Stack* s) {
    s->top = NULL;
}

/* Push an item onto the stack */
void stack_push(Stack* s, void* data) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Out of memory!\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

/* Pop an item off the stack */
void* stack_pop(Stack* s) {
    if (s->top == NULL) {
        printf("Error: Stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    void* data = s->top->data;
    Node* temp_node = s->top;
    s->top = s->top->next;
    free(temp_node);
    return data;
}

/* Print the contents of the stack */
void stack_print(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents:\n");
    Node* curr_node = s->top;
    while (curr_node!= NULL) {
        printf("%p -> ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("NULL\n");
}

/* Main function */
int main() {
    // Initialize an empty stack
    Stack s;
    stack_init(&s);

    // Push some items onto the stack
    stack_push(&s, (void*)1);
    stack_push(&s, (void*)2);
    stack_push(&s, (void*)3);

    // Print the contents of the stack
    stack_print(&s);

    // Pop an item off the stack
    void* popped_item = stack_pop(&s);
    printf("Popped item: %p\n", popped_item);

    // Print the contents of the stack again
    stack_print(&s);

    // Clear the stack
    while (s.top!= NULL) {
        void* data = stack_pop(&s);
        printf("Popped item: %p\n", data);
    }

    return 0;
}
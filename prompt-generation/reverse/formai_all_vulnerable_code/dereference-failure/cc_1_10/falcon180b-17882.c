//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int next;
} Node;

void push(Node **top_ref, int new_data);
int pop(Node **top_ref);
int is_empty(Node *top);
void print_stack(Node *top);

int main() {
    Node *stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    printf("Stack elements are: ");
    print_stack(stack);

    int popped_element = pop(&stack);
    printf("\nPopped element is: %d", popped_element);

    printf("\nStack elements after popping an element are: ");
    print_stack(stack);

    return 0;
}

void push(Node **top_ref, int new_data) {
    Node *new_node = (Node *) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Stack overflow ");
        exit(0);
    }

    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(Node **top_ref) {
    char res;
    Node *top = *top_ref;

    if (top == NULL) {
        printf("Stack underflow ");
        exit(0);
    }

    res = top->data;
    top = top->next;
    free(top);
    (*top_ref) = top;

    return res;
}

int is_empty(Node *top) {
    if (top == NULL)
        return 1;
    else
        return 0;
}

void print_stack(Node *top) {
    while (top!= NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
}
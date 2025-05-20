//Falcon-180B DATASET v1.0 Category: Text processing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

// Function prototypes
void push(Node** top_ref, char new_data);
char pop(Node** top_ref);
void printList(Node* node);
int isEmpty(Node* top);

// Main function
int main() {
    Node* top = NULL;

    push(&top, 'A');
    push(&top, 'B');
    push(&top, 'C');

    printf("Original list: ");
    printList(top);

    char popped_data = pop(&top);
    printf("\nPopped item: %c\n", popped_data);

    printf("List after popping: ");
    printList(top);

    return 0;
}

// Push function to add a new element to the stack
void push(Node** top_ref, char new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

// Pop function to remove and return the top element from the stack
char pop(Node** top_ref) {
    Node* top = *top_ref;
    char popped_data;

    if (isEmpty(top)) {
        printf("Stack is empty\n");
        exit(0);
    }

    popped_data = top->data;
    Node* temp = top;
    top = top->next;
    free(temp);

    (*top_ref) = top;

    return popped_data;
}

// Print the elements in the linked list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
}

// Check if the stack is empty
int isEmpty(Node* top) {
    if (top == NULL)
        return 1;
    else
        return 0;
}
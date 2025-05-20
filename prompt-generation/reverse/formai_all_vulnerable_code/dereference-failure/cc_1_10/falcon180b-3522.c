//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void push(struct Node** top_ref, int new_data);
int pop(struct Node** top_ref);
int peek(struct Node* top);
void printList(struct Node* node);

int main() {
    struct Node* top = NULL;

    // Test push function
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);

    // Test printList function
    printf("Stack elements are: ");
    printList(top);

    // Test pop function
    printf("\nPopped element from stack: %d\n", pop(&top));

    // Test printList function again
    printf("Stack elements after popping an element are: ");
    printList(top);

    return 0;
}

// Function to push an integer onto the stack
void push(struct Node** top_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;

    printf("\n%d pushed to stack\n", new_data);
}

// Function to pop an integer from the stack
int pop(struct Node** top_ref) {
    char res;
    struct Node* top = *top_ref;

    if (top == NULL) {
        printf("\nStack Underflow");
        res = -1;
    } else {
        printf("\n%d popped from stack\n", top->data);
        res = top->data;
        top = top->next;
        (*top_ref) = top;
    }

    return res;
}

// Function to return the top element of the stack
int peek(struct Node* top) {
    if (top == NULL) {
        printf("\nStack is Empty");
        return -1;
    } else {
        printf("\nTop element is %d\n", top->data);
        return top->data;
    }
}

// Function to print all elements in the linked list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
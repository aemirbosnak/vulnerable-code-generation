//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to push a node onto the stack
void push(struct Node** top_ref, int data) {
    struct Node* node = newNode(data);
    node->next = *top_ref;
    *top_ref = node;
    printf("%d pushed to stack\n", data);
}

// Function to pop a node from the stack
int pop(struct Node** top_ref) {
    struct Node* node = *top_ref;
    int data = node->data;
    *top_ref = node->next;
    free(node);
    return data;
}

// Function to display the elements in the stack
void display(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    display(top);
    printf("\n");
    int popped_data = pop(&top);
    printf("Popped element: %d\n", popped_data);
    display(top);
    return 0;
}
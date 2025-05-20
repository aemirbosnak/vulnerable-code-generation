//Falcon-180B DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void push(Node** top_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

void pop(Node** top_ref) {
    Node* top = *top_ref;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = top;
    *top_ref = top->next;
    free(temp);
}

void printStack(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);
    push(&top, 50);
    printStack(top);
    pop(&top);
    printStack(top);
    pop(&top);
    printStack(top);
    pop(&top);
    printStack(top);
    pop(&top);
    printStack(top);
    return 0;
}
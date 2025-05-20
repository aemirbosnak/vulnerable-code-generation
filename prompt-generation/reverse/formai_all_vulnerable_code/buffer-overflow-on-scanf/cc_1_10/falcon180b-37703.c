//Falcon-180B DATASET v1.0 Category: Recursive ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

void push(Node** top_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (!new_node) {
        printf("Stack overflow \n");
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(Node** top_ref) {
    char res;
    Node* top = *top_ref;
    if (top == NULL) {
        printf("Stack underflow \n");
        exit(0);
    }
    res = top->data;
    Node* temp = top;
    *top_ref = top->next;
    free(temp);
    return res;
}

void printStack(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* top = NULL;
    int choice, element;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &element);
            push(&top, element);
            break;
        case 2:
            element = pop(&top);
            if (element!= -1)
                printf("%d popped from the stack\n", element);
            break;
        case 3:
            printStack(top);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
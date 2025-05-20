//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top_ref, int new_data) {
    Node* new_node = createNode(new_data);
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(Node** top_ref) {
    Node* top = *top_ref;
    int data = top->data;
    Node* next = top->next;
    free(top);
    *top_ref = next;
    return data;
}

void printStack(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* stack = NULL;
    int choice, data;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                data = pop(&stack);
                printf("Popped element is: %d\n", data);
                break;
            case 3:
                printf("Stack elements are: ");
                printStack(stack);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (true);

    return 0;
}
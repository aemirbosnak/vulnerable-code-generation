//Falcon-180B DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error!");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top_ref, int new_data) {
    Node* new_node = createNode(new_data);
    new_node->next = *top_ref;
    *top_ref = new_node;
}

int pop(Node** top_ref) {
    Node* top = *top_ref;
    int data = top->data;
    Node* next = top->next;
    free(top);
    *top_ref = next;
    return data;
}

int peek(Node* top) {
    return top->data;
}

int isEmpty(Node* top) {
    return top == NULL;
}

void printStack(Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty!");
        return;
    }
    printf("Stack: ");
    Node* curr = top;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Node* stack = NULL;
    int choice, data;

    do {
        printf("1. Push\n2. Pop\n3. Peek\n4. Print stack\n5. Exit\n");
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
                data = peek(stack);
                printf("Top element is: %d\n", data);
                break;
            case 4:
                printStack(stack);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!");
        }
    } while (choice!= 5);

    return 0;
}
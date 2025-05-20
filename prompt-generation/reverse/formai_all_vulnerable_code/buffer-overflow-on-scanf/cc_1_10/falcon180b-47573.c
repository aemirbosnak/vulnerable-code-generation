//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

void push(Node** top_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(Node** top_ref) {
    char res;
    res = (*top_ref)->data;
    Node* temp = *top_ref;
    *top_ref = (*top_ref)->next;
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
    Node* stack = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Print Stack\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                data = pop(&stack);
                if (data == -1)
                    printf("Stack is empty\n");
                else
                    printf("Popped element is %d\n", data);
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
    }

    return 0;
}
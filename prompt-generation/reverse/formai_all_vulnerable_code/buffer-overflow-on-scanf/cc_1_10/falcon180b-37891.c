//Falcon-180B DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node *next;
};

void push(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void pop(struct node **head_ref) {
    struct node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void printList(struct node *node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node *head = NULL;
    int choice, data;
    do {
        printf("Enter your choice:\n1. Push\n2. Pop\n3. Print\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be pushed:\n");
                scanf("%d", &data);
                push(&head, data);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
    return 0;
}
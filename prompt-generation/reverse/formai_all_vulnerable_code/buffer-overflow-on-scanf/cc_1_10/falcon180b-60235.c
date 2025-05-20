//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node *next;
} node;

node *create_node(int data) {
    node *new_node = (node *) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(node **head, int data) {
    node *new_node = create_node(data);
    node *temp = *head;
    if (temp == NULL) {
        *head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

int search_node(node *head, int data) {
    node *temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    node *head = NULL;
    int choice, data;

    do {
        printf("Enter 1 to add node\n");
        printf("Enter 2 to search node\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data for node: ");
            scanf("%d", &data);
            add_node(&head, data);
            break;
        case 2:
            printf("Enter data to search: ");
            scanf("%d", &data);
            if (search_node(head, data)) {
                printf("Node found\n");
            } else {
                printf("Node not found\n");
            }
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char *data;
    struct node *next;
} Node;

Node *create_node(char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node **head, char *data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void search_node(Node *head, char *data) {
    Node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            printf("Node found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Node not found\n");
}

int main() {
    Node *head = NULL;
    char data[MAX_SIZE];

    int choice, i;
    do {
        printf("\n1. Add node\n2. Search node\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%s", data);
            add_node(&head, data);
            break;
        case 2:
            printf("Enter data to search: ");
            scanf("%s", data);
            search_node(head, data);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}
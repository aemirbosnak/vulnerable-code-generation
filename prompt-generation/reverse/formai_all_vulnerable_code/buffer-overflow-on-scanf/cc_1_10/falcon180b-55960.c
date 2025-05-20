//Falcon-180B DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void insert_node(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("Node with data %d inserted\n", data);
}

void delete_node(int data) {
    Node *temp = head;
    Node *prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
    } else {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        printf("Node with data %d deleted\n", data);
    }
}

void display_list() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Insert node\n2. Delete node\n3. Display list\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_node(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                delete_node(data);
                break;
            case 3:
                display_list();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
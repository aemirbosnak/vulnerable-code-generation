//Falcon-180B DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void createNode(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Node created with data %d\n", data);
}

void deleteNode(Node** head, int data) {
    Node* temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        printf("Node deleted with data %d\n", data);
    } else {
        while (temp!= NULL && temp->data!= data) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Node not found with data %d\n", data);
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
            printf("Node deleted with data %d\n", data);
        }
    }
}

void traverseList(Node* head) {
    while (head!= NULL) {
        printf("Data: %d\n", head->data);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Create node\n");
        printf("2. Delete node\n");
        printf("3. Traverse list\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for new node: ");
                scanf("%d", &data);
                createNode(&head, data);
                break;
            case 2:
                printf("Enter data for node to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                traverseList(head);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}
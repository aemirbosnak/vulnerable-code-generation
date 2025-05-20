//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[50];
    struct node* next;
} Node;

Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, char* data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void deleteNode(Node** head, char* data) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp!= NULL && strcmp(temp->data, data) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
    return;
}

void searchNode(Node* head, char* data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            printf("Node found!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Node not found.\n");
    return;
}

int main() {
    Node* head = NULL;
    char data[50];
    int choice, pos;

    do {
        printf("1. Insert node\n2. Delete node\n3. Search node\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%s", data);
                insertNode(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%s", data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%s", data);
                searchNode(head, data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}
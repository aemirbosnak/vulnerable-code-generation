//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node added successfully!\n");
}

void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        printf("Node deleted successfully!\n");
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully!\n");
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add node\n");
        printf("2. Delete node\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to add: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteAtBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node *temp = *head;
        *head = temp->next;
        free(temp);
    }
}

void deleteAtEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        struct Node *temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        printf("List: ");
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

int main() {
    struct Node *head = NULL;
    int choice, data;
    do {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                deleteAtBeginning(&head);
                break;
            case 4:
                deleteAtEnd(&head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (1);
    return 0;
}
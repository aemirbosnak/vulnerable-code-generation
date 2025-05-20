//FormAI DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
// A Cyberpunk Style Linked List Operations Example Program

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

void addNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void deleteNode(int data) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found in the list!\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    printf("Element %d deleted successfully!\n", data);
    free(temp);
}

void displayList() {
    Node* temp = head;

    if (temp == NULL) {
        printf("The list is empty!\n");
        return;
    }

    printf("========================\n");
    printf("|  Cyberpunk Linked List  |\n");
    printf("========================\n");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice, data;

    do {
        printf("================\n");
        printf("|   Operations   |\n");
        printf("================\n");
        printf("1. Add element\n");
        printf("2. Delete element\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &data);
                addNode(data);
                printf("Element %d added successfully!\n", data);
                break;

            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;

            case 3:
                displayList();
                break;

            case 4:
                printf("Exiting program... Bye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
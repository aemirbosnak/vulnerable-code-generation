//FormAI DATASET v1.0 Category: Linked list operations ; Style: active
#include <stdlib.h>
#include <stdio.h>

// Create a struct for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Initialize the head of the linked list
struct Node* head = NULL;

// Insert a new node at the beginning of the linked list
void insertAtBeginning(int data) {
    struct Node* newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning\n", data);
}

// Insert a new node at the end of the linked list
void insertAtEnd(int data) {
    struct Node* newNode = NULL;
    struct Node* temp = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        printf("%d inserted at the end\n", data);
        return;
    }
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("%d inserted at the end\n", data);
}

// Delete a node from the linked list
void delete(int data) {
    struct Node* temp = NULL;
    struct Node* prev = NULL;
    temp = head;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found\n", data);
        return;
    }
    else if (prev == NULL) {
        head = head->next;
    }
    else {
        prev->next = temp->next;
    }
    printf("%d deleted from the list\n", data);
    free(temp);
}

// Print the linked list
void printList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty\n");
        return;
    }
    printf("The list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete\n");
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 4:
                printList();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    }
    return 0;
}
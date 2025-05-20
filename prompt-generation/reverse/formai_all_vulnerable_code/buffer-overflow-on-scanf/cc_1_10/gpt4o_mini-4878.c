//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node by value
void deleteNode(int data) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == data) {
        head = temp->next; // Change head
        free(temp); // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to display linked list
void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList() {
    struct Node* temp = head;
    struct Node* nextNode;
    while (temp != NULL) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    head = NULL;
}

// Main function to interact with the user
int main() {
    int choice, data;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at end\n");
        printf("2. Delete by value\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 3:
                displayList();
                break;
            case 4:
                freeList();
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
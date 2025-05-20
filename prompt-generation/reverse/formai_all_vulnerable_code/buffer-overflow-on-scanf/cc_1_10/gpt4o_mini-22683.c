//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a single node in the linked list
struct Node {
    int id;
    char name[50];
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int id, const char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    strncpy(newNode->name, name, sizeof(newNode->name) - 1);
    newNode->name[sizeof(newNode->name) - 1] = '\0'; // Ensure null-termination
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int id, const char* name) {
    struct Node* newNode = createNode(id, name);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** headRef, int id, const char* name) {
    struct Node* newNode = createNode(id, name);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct Node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to delete a node by id
void deleteNode(struct Node** headRef, int id) {
    struct Node* temp = *headRef;
    struct Node* prev = NULL;

    if (temp != NULL && temp->id == id) {
        *headRef = temp->next; // Changed head
        free(temp); // Free old head
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // ID not found

    prev->next = temp->next; // Unlink the node from linked list
    free(temp); // Free memory
}

// Function to display the linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("ID: %d, Name: %s\n", node->id, node->name);
        node = node->next;
    }
}

// Function to clean up the linked list and free memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL;
    int choice, id;
    char name[50];

    do {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Node by ID\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID and Name: ");
                scanf("%d %s", &id, name);
                insertAtBeginning(&head, id, name);
                break;
            case 2:
                printf("Enter ID and Name: ");
                scanf("%d %s", &id, name);
                insertAtEnd(&head, id, name);
                break;
            case 3:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteNode(&head, id);
                break;
            case 4:
                printf("Current Linked List:\n");
                displayList(head);
                break;
            case 5:
                freeList(head);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
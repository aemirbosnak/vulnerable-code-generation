//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Define the structure for a linked list node
typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->name, name, MAX_NAME_LENGTH - 1);
    newNode->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, const char* name) {
    Node* newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node by name
void deleteNode(Node** head, const char* name) {
    if (*head == NULL) return;

    Node* temp = *head;
    Node* prev = NULL;

    // If the node to be deleted is the head node
    if (strcmp(temp->name, name) == 0) {
        *head = temp->next; // Change head
        free(temp);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If the name was not found
    if (temp == NULL) {
        fprintf(stderr, "Node with name '%s' not found\n", name);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        temp = temp->next;
    }
}

// Function to free the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to demonstrate linked list operations
int main() {
    Node* head = NULL;
    int choice;
    char name[MAX_NAME_LENGTH];

    do {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert a name at the end\n");
        printf("2. Delete a name\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf
        
        switch (choice) {
            case 1:
                printf("Enter the name to insert: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                insertAtEnd(&head, name);
                break;
            case 2:
                printf("Enter the name to delete: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                deleteNode(&head, name);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting the program.\n");
                freeList(head);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
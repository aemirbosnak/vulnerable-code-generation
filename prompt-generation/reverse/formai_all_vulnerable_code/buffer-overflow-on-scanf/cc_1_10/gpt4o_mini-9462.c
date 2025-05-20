//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a single node in the linked list
typedef struct Node {
    char data[100]; // Data to be stored in the node
    struct Node* next; // Pointer to the next node
} Node;

// Function prototypes
Node* createNode(const char* data);
void insertAtEnd(Node** head, const char* data);
void displayList(Node* head);
void deleteNode(Node** head, const char* data);
void freeList(Node** head);

int main() {
    // Create a pointer for the head of the list
    Node* head = NULL; 
    int choice;
    char data[100];

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert an element\n");
        printf("2. Display elements\n");
        printf("3. Delete an element\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the new line after the integer input

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                fgets(data, sizeof(data), stdin);
                strtok(data, "\n"); // Remove the newline character
                insertAtEnd(&head, data);
                break;
            case 2:
                printf("Linked List Elements:\n");
                displayList(head);
                break;
            case 3:
                printf("Enter data to delete: ");
                fgets(data, sizeof(data), stdin);
                strtok(data, "\n"); // Remove the newline character
                deleteNode(&head, data);
                break;
            case 4:
                freeList(&head);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to create a new node
Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(Node** head, const char* data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode; // List is empty, new node becomes head
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end
        }
        temp->next = newNode; // Link new node at the end
    }
    printf("Inserted: %s\n", data);
}

// Function to display linked list elements
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node by data
void deleteNode(Node** head, const char* data) {
    if (*head == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return;
    }

    Node *temp = *head, *prev = NULL;

    // Check if the head node itself holds the key to be deleted
    if (temp != NULL && strcmp(temp->data, data) == 0) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        printf("Deleted: %s\n", data);
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && strcmp(temp->data, data) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Element not found: %s\n", data);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free the memory
    printf("Deleted: %s\n", data);
}

// Function to free the linked list
void freeList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next; // Store next node
        free(current); // Free current node
        current = next; // Move to next node
    }

    *head = NULL; // Reset the head to NULL
}
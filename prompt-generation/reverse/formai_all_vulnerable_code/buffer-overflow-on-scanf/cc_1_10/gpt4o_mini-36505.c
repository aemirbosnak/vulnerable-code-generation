//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the linked list
struct Node {
    char data[100];
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(const char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->data, data, sizeof(newNode->data));
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head_ref, const char* data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to print the linked list
void printList(struct Node* node) {
    if (!node) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List:\n");
    while (node != NULL) {
        printf(" -> %s", node->data);
        node = node->next;
    }
    printf(" -> NULL\n");
}

// Function to delete a node by value
void deleteNode(struct Node** head_ref, const char* key) {
    struct Node* temp = *head_ref, *prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && strcmp(temp->data, key) == 0) {
        *head_ref = temp->next; // Changed head
        free(temp);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && strcmp(temp->data, key) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Node with value \"%s\" not found.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
}

// Function to clear the entire list
void clearList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head_ref = NULL;
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL;
    char input[100];

    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Delete a node\n");
        printf("3. Print list\n");
        printf("4. Clear list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the integer input

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                insertEnd(&head, input);
                break;
            case 2:
                printf("Enter data of node to delete: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                deleteNode(&head, input);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                clearList(&head);
                printf("List cleared.\n");
                break;
            case 0:
                printf("Exiting...\n");
                clearList(&head); // Clear list before exiting
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
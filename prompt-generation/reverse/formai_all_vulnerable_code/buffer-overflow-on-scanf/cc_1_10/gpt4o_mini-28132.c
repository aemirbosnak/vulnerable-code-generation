//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for the linked list
struct Node {
    char data[30];
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, char* data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with a specific value
void deleteNode(struct Node** head, char* key) {
    struct Node* temp = *head, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && strcmp(temp->data, key) == 0) {
        *head = temp->next;
        free(temp);
        printf("Node with data '%s' deleted.\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && strcmp(temp->data, key) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Node with data '%s' not found.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
    printf("Node with data '%s' deleted.\n", key);
}

// Function to display the linked list
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (node != NULL) {
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to search for a node in the linked list
int searchNode(struct Node* head, char* key) {
    struct Node* current = head;
    while (current != NULL) {
        if (strcmp(current->data, key) == 0) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not Found
}

// Function to clear the entire linked list
void clearList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    printf("Linked list cleared.\n");
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL;
    char input[30];
    int choice;

    printf("Welcome to our Linked List Program!\n");
    do {
        printf("\nMenu:\n");
        printf("1. Insert at End\n");
        printf("2. Delete a Node\n");
        printf("3. Display List\n");
        printf("4. Search for a Node\n");
        printf("5. Clear the List\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                fgets(input, 30, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                insertEnd(&head, input);
                break;
            case 2:
                printf("Enter data to delete: ");
                fgets(input, 30, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                deleteNode(&head, input);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Enter data to search: ");
                fgets(input, 30, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                if (searchNode(head, input)) {
                    printf("Node with data '%s' found!\n", input);
                } else {
                    printf("Node with data '%s' not found.\n", input);
                }
                break;
            case 5:
                clearList(&head);
                break;
            case 6:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    // Clean up memory (final clear)
    clearList(&head);
    return 0;
}
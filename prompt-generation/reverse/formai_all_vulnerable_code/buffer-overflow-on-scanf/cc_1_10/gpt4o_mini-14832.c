//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to delete a node
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* previous = NULL;

    // Check if the head needs to be deleted
    if (current != NULL && current->data == key) {
        head = current->next;  
        free(current);        
        return head;
    }

    // Traverse the list to find the key
    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }

    // If key was not found
    if (current == NULL) {
        printf("Node with value %d not found.\n", key);
        return head;
    }

    // Unlink the node from the list
    previous->next = current->next;
    free(current);
    return head;
}

// Function to search for a node
struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Search for a Node\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter the value to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 4:
                printf("Enter the value to search for: ");
                scanf("%d", &data);
                struct Node* result = searchNode(head, data);
                if (result) {
                    printf("Node with value %d found.\n", result->data);
                } else {
                    printf("Node with value %d not found.\n", data);
                }
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node of the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node by value
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == data) {
        *head = temp->next;  // Changed head
        free(temp);  // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", data);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);  // Free memory
}

// Function to search for a node in the linked list
int searchNode(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;  // Found
        }
        current = current->next;
    }
    return 0;  // Not found
}

// Function to display the linked list
void displayList(Node* node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to interactively manipulate the linked list
int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert at End\n");
        printf("2. Delete by Value\n");
        printf("3. Search by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the integer to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                printf("Inserted %d at the end of the list.\n", data);
                break;
            case 2:
                printf("Enter the integer to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter the integer to search: ");
                scanf("%d", &data);
                if (searchNode(head, data)) {
                    printf("Element %d found in the list.\n", data);
                } else {
                    printf("Element %d not found in the list.\n", data);
                }
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    // Free the linked list
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
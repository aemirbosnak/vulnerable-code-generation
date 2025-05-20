//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the linked list node
typedef struct Node {
    int data;
    char name[50];
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    strncpy(newNode->name, name, sizeof(newNode->name) - 1);
    newNode->name[sizeof(newNode->name) - 1] = '\0'; // Ensure null-termination
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void appendNode(Node** head, int data, const char* name) {
    Node* newNode = createNode(data, name);
    if (!newNode) return;

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

// Function to print the linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("Node Data: %d, Name: %s\n", temp->data, temp->name);
        temp = temp->next;
    }
}

// Function to free the entire list
void freeList(Node** head) {
    Node* temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Function to delete a node by value
void deleteNode(Node** head, int data) {
    if (*head == NULL) return;

    Node* temp = *head;
    Node* prev = NULL;

    // If the node to be deleted is the head
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the node to delete
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // Node not found
    if (temp == NULL) return;

    // Unlink the node
    prev->next = temp->next;
    free(temp);
}

// Function to search for a node by value
Node* searchNode(Node* head, int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp; // Node found
        }
        temp = temp->next;
    }
    return NULL; // Node not found
}

// Main function to demonstrate linked list operations
int main() {
    Node* head = NULL;
    int choice, value;
    char name[50];

    do {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Append Node\n");
        printf("2. Delete Node\n");
        printf("3. Search Node\n");
        printf("4. Print List\n");
        printf("5. Free List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer value: ");
                scanf("%d", &value);
                printf("Enter name: ");
                scanf("%s", name);
                appendNode(&head, value, name);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                Node* foundNode = searchNode(head, value);
                if (foundNode) {
                    printf("Node found - Data: %d, Name: %s\n", foundNode->data, foundNode->name);
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 4:
                printf("Current List:\n");
                printList(head);
                break;
            case 5:
                freeList(&head);
                printf("List has been freed.\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    freeList(&head); // Free the list before exit
    return 0;
}
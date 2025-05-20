//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d into the list\n", data);
}

// Function to delete a node by value
void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty, cannot delete %d\n", data);
        return;
    }
    
    Node* temp = head;
    Node* prev = NULL;

    // If the node to delete is the head node
    if (temp != NULL && temp->data == data) {
        head = temp->next; // Change head
        free(temp); // Free old head
        printf("Deleted %d from the list\n", data);
        return;
    }

    // Search for the node to delete
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the node was not found
    if (temp == NULL) {
        printf("%d not found in the list\n", data);
        return;
    }

    prev->next = temp->next; // Unlink the node from the list
    free(temp); // Free memory
    printf("Deleted %d from the list\n", data);
}

// Function to display the linked list
void displayList() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the memory used by the list
void freeList() {
    Node* current = head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    head = NULL;
    printf("All nodes have been deleted and memory freed.\n");
}

// Main function to demonstrate the linked list operations
int main() {
    int choice, value;

    do {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Free List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertNode(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                displayList();
                break;
            case 4:
                freeList();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Free remaining nodes before exit
    freeList();
    return 0;
}
//FormAI DATASET v1.0 Category: Linked list operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Creating the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Initializing the head of the linked list
Node* head = NULL;

// Function to add a node to the head of the linked list
void addNodeAtHead(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Added node with data %d at the head of the linked list.\n", data);
}

// Function to add a node to the tail of the linked list
void addNodeAtTail(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        printf("Added node with data %d at the tail of the linked list.\n", data);
        return;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    printf("Added node with data %d at the tail of the linked list.\n", data);
}

// Function to delete a node with a specific data value from the linked list
void deleteNode(int data) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    Node* current = head;
    Node* previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found in the linked list.\n", data);
        return;
    }
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    printf("Deleted node with data %d from the linked list.\n", data);
}

// Function to print the linked list
void printList() {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    Node* current = head;
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    printf("--------------- Linked List Operations ---------------\n");
    int choice, data;
    while (1) {
        printf("\n1. Add node at head.\n2. Add node at tail.\n3. Delete node.\n4. Print linked list.\n5. Exit program.\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to add at the head: ");
                scanf("%d", &data);
                addNodeAtHead(data);
                break;
            case 2:
                printf("Enter data to add at the tail: ");
                scanf("%d", &data);
                addNodeAtTail(data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 4:
                printList();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
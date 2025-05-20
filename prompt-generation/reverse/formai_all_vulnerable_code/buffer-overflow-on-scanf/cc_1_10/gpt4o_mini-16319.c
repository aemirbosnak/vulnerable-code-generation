//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning
void insertAtBeginning(int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning\n", data);
}

// Function to insert a new node at the end
void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        printf("Inserted %d at the end\n", data);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end\n", data);
}

// Function to delete a node by value
void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty, can't delete %d\n", data);
        return;
    }
    Node* temp = head;
    Node* prev = NULL;

    // If head needs to be removed
    if (temp->data == data) {
        head = temp->next;
        free(temp);
        printf("Deleted %d from the list\n", data);
        return;
    }

    // Searching for the node to delete
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // Node not found
    if (temp == NULL) {
        printf("%d not found in the list\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list\n", data);
}

// Function to search for a node by value
void searchNode(int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("%d found in the list\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found in the list\n", data);
}

// Function to display the linked list
void displayList() {
    Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete a node\n");
        printf("4. Search for a node\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                searchNode(data);
                break;
            case 5:
                displayList();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
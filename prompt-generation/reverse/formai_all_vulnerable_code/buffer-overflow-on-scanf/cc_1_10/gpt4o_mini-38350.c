//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
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
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) return;
    struct Node* temp = *head, *prev = NULL;
    
    // If the head node itself holds the value to be deleted
    if (temp != NULL && temp->data == data) {
        *head = temp->next; // Changed head
        free(temp);         // Free the old head
        return;
    }
    
    // Search for the value to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    
    // If the value was not found in the list
    if (temp == NULL) return;
    
    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to display the linked list
void displayList(struct Node* node) {
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

// Function to search for a specific value in the list
struct Node* searchNode(struct Node* head, int data) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current; // Value found
        }
        current = current->next;
    }
    return NULL; // Value not found
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Node\n");
        printf("4. Display List\n");
        printf("5. Search Node\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (searchNode(head, value) != NULL) {
                    printf("Value %d found in the list.\n", value);
                } else {
                    printf("Value %d not found in the list.\n", value);
                }
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 0);

    // Freeing all nodes
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
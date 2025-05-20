//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a linked list node
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

// Function to insert a node at the end of the list
void insertEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = *head_ref;
    
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = newNode;
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head_ref, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head_ref;
        *head_ref = newNode;
        return;
    }

    struct Node* current = *head_ref;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a node by value
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the list
    if (temp == NULL) {
        printf("Value %d not found in the list\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list in forward order
void displayForward(struct Node* node) {
    if (node == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Forward List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to display the linked list in reverse order
void displayReverse(struct Node* node) {
    if (node == NULL) return;
    displayReverse(node->next);
    printf("%d -> ", node->data);
}

// Function to free the linked list
void freeList(struct Node** head_ref) {
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
    int choice, data, position;

    do {
        printf("\nLinked List Menu:\n");
        printf("1. Insert at end\n");
        printf("2. Insert at position\n");
        printf("3. Delete node\n");
        printf("4. Display forward\n");
        printf("5. Display reverse\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;

            case 4:
                displayForward(head);
                break;

            case 5:
                printf("Reverse List: ");
                displayReverse(head);
                printf("NULL\n");
                break;

            case 6:
                freeList(&head);
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
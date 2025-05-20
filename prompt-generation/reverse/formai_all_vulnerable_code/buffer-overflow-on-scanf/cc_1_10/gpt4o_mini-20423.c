//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a single node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node and return its pointer
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to display the linked list
void displayList(struct Node *node) {
    if (node == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to delete a specific node by value
void deleteNode(struct Node **head, int key) {
    struct Node *temp = *head, *prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Changed head
        free(temp);         // Free old head
        printf("Deleted node with value %d\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the list
    if (temp == NULL) {
        printf("Value %d not found in the list!\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
    printf("Deleted node with value %d\n", key);
}

// Function to search for a node with a specific value
void searchList(struct Node *head, int key) {
    struct Node *current = head;
    while (current != NULL) {
        if (current->data == key) {
            printf("Value %d found in the list!\n", key);
            return;
        }
        current = current->next;
    }
    printf("Value %d not found in the list!\n", key);
}

// Main function to drive the linked list operations
int main() {
    struct Node *head = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert a number\n");
        printf("2. Display the list\n");
        printf("3. Delete a number\n");
        printf("4. Search for a number\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                printf("Inserted %d into the list!\n", value);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter a number to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                printf("Enter a number to search for: ");
                scanf("%d", &value);
                searchList(head, value);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
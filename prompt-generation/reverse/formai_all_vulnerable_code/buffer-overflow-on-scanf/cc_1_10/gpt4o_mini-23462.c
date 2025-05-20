//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtEnd(struct Node** head_ref, int new_data);
void deleteNode(struct Node** head_ref, int key);
struct Node* searchNode(struct Node* head, int key);
void displayList(struct Node* node);
void freeList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert at End\n");
        printf("2. Delete Node\n");
        printf("3. Search Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* foundNode = searchNode(head, value);
                if (foundNode) {
                    printf("Node with value %d found.\n", foundNode->data);
                } else {
                    printf("Node with value %d not found.\n", value);
                }
                break;
            case 4:
                printf("Linked List: ");
                displayList(head);
                break;
            case 5:
                freeList(head);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    printf("Node with value %d inserted.\n", new_data);
}

// Function to delete a node with a given key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // Free old head
        printf("Node with value %d deleted.\n", key);
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
    printf("Node with value %d deleted.\n", key);
}

// Function to search for a node with a given key
struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head; // Initialize current
    while (current != NULL) {
        if (current->data == key) {
            return current; // Return node if found
        }
        current = current->next; // Move to next node
    }
    return NULL; // Return NULL if not found
}

// Function to display the linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free the entire linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
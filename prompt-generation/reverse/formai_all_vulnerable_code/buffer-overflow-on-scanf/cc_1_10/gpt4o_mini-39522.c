//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the Linked List
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void append(struct Node** head_ref, int data);
void displayList(struct Node* node);
int deleteNode(struct Node** head_ref, int key);
struct Node* searchNode(struct Node* head, int key);
void freeList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Append node\n");
        printf("2. Display list\n");
        printf("3. Delete node\n");
        printf("4. Search node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to append: ");
                scanf("%d", &data);
                append(&head, data);
                break;
            case 2:
                printf("The linked list is: ");
                displayList(head);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                if (deleteNode(&head, key)) {
                    printf("Node with data %d deleted.\n", key);
                } else {
                    printf("Node with data %d not found.\n", key);
                }
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &key);
                struct Node* foundNode = searchNode(head, key);
                if (foundNode) {
                    printf("Node with data %d found.\n", foundNode->data);
                } else {
                    printf("Node with data %d not found.\n", key);
                }
                break;
            case 5:
                freeList(head);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append a new node at the end of the list
void append(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next) {
        last = last->next;
    }
    last->next = newNode;
}

// Display the linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Delete a node from the linked list
int deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // Free old head
        return 1; // Node deleted
    }
    
    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    // If key was not present in linked list
    if (temp == NULL) return 0;

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
    return 1; // Node deleted
}

// Search for a node with a given key
struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head; // Initialize current
    while (current != NULL) {
        if (current->data == key) return current;
        current = current->next;
    }
    return NULL; // Not found
}

// Free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
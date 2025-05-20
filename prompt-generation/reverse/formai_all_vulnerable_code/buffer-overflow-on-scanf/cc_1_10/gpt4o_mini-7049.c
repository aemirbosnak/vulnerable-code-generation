//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to delete a node by key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // Free old head
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in linked list
    if (temp == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to free the entire list
void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL; // Mark head as NULL after freeing
}

// Function to find a node by key
struct Node* findNode(struct Node* head, int key) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }

    return NULL; // If not found
}

// Main function to demonstrate the linked list operations
int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert at End\n");
        printf("2. Delete by Key\n");
        printf("3. Print List\n");
        printf("4. Find Node by Key\n");
        printf("5. Free List\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;

            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;

            case 3:
                printf("Current List: ");
                printList(head);
                break;

            case 4:
                printf("Enter key to find: ");
                scanf("%d", &data);
                struct Node* foundNode = findNode(head, data);
                if (foundNode != NULL) {
                    printf("Node with key %d found!\n", foundNode->data);
                } else {
                    printf("Node with key %d not found in the list.\n", data);
                }
                break;

            case 5:
                freeList(&head);
                printf("List freed.\n");
                break;

            case 6:
                freeList(&head);
                printf("Exiting program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
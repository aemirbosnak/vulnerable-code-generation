//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node and return it
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void appendNode(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
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

// Function to delete a node by value
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the linked list
    if (temp == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to print linked list
void printList(struct Node* node) {
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

// Function to free the entire Linked List
void freeList(struct Node* node) {
    struct Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

// Function to find a node in the linked list
struct Node* findNode(struct Node* head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            return head; // Key found
        }
        head = head->next;
    }
    return NULL; // Key not found
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Append Node\n");
        printf("2. Delete Node\n");
        printf("3. Print List\n");
        printf("4. Find Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to append: ");
                scanf("%d", &value);
                appendNode(&head, value);
                printf("Node with value %d appended.\n", value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("Enter value to find: ");
                scanf("%d", &value);
                struct Node* foundNode = findNode(head, value);
                if (foundNode)
                    printf("Node with value %d found.\n", foundNode->data);
                else
                    printf("Node with value %d not found.\n", value);
                break;
            case 5:
                freeList(head);
                printf("Exiting the program and freeing memory.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
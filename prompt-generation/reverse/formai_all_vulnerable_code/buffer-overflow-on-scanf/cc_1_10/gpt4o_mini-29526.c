//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

/* Define the structure for a linked list node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to create a new node */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Function to insert a node at the end of the linked list */
void insertEnd(struct Node** head, int data) {
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

/* Function to delete a node by value */
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        free(temp);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Node with the key not found
    if (temp == NULL) return;

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

/* Function to display the linked list */
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

/* Function to search for a node in the linked list */
struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL; // Not found
}

/* Main function to demonstrate linked list operations */
int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("Linked List Operations:\n");
        printf("1. Insert at end\n");
        printf("2. Delete by value\n");
        printf("3. Display list\n");
        printf("4. Search for value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                printf("Current Linked List: ");
                displayList(head);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* result = searchNode(head, value);
                if (result != NULL) {
                    printf("Value %d found in the list.\n", value);
                } else {
                    printf("Value %d not found in the list.\n", value);
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
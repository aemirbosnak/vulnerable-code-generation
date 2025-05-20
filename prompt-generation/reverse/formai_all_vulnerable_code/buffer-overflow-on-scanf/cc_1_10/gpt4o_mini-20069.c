//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in the linked list
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

// Function to insert a new node at the end
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

// Function to display the linked list
void displayList(struct Node* node) {
    printf("<==== Linked List ====>\n");
    while (node != NULL) {
        printf("| %d ", node->data);
        node = node->next;
    }
    printf("|\n<====================>\n");
}

// Function to delete a node by key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; 
        free(temp); 
        printf("Node with value %d deleted.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", key);
}

// Function to search for a node by key
void searchNode(struct Node* head, int key) {
    struct Node* current = head;
    int position = 0;

    while (current != NULL) {
        if (current->data == key) {
            printf("Node with value %d found at position %d.\n", key, position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("Node with value %d not found.\n", key);
}

// Main function to run the linked list operations
int main() {
    struct Node* head = NULL;
    int choice, value;

    printf("Welcome to the Retro Linked List Program!\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Insert Node at End\n");
        printf("2. Display List\n");
        printf("3. Delete Node\n");
        printf("4. Search Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                printf("Node with value %d inserted.\n", value);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchNode(head, value);
                break;
            case 5:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Free the linked list memory before exiting
    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}
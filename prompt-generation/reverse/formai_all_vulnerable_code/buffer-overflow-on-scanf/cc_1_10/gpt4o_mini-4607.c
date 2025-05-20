//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insertAtEnd(struct Node* head, int data);
struct Node* deleteNode(struct Node* head, int data);
struct Node* searchNode(struct Node* head, int data);
void displayList(struct Node* head);
int menu();

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Recursive function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    if (head == NULL) {
        return createNode(data); // Base case: create new node
    }
    head->next = insertAtEnd(head->next, data); // Recur for next node
    return head; // Return the unchanged head
}

// Recursive function to delete a node from the list
struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        return NULL; // Base case: list is empty
    }
    if (head->data == data) {
        struct Node* temp = head->next; // Node to be deleted found
        free(head); // Free memory
        return temp; // Return next node as new head
    }
    head->next = deleteNode(head->next, data); // Recur for next node
    return head; // Return unchanged head
}

// Recursive function to search for a node in the list
struct Node* searchNode(struct Node* head, int data) {
    if (head == NULL || head->data == data) {
        return head; // Base case: found or end of list
    }
    return searchNode(head->next, data); // Recur for next node
}

// Recursive function to display the elements of the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return; // Base case: end of list
    }
    printf("%d -> ", head->data); // Display current node data
    displayList(head->next); // Recur for next node
}

// Menu for user interaction
int menu() {
    int choice;
    printf("\nLinked List Operations:\n");
    printf("1. Insert at End\n");
    printf("2. Delete a Node\n");
    printf("3. Search a Node\n");
    printf("4. Display List\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    struct Node* head = NULL; // Initialize head of the list
    int value;
    struct Node* result;

    while (1) {
        switch (menu()) {
            case 1: // Insert at End
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;

            case 2: // Delete a Node
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;

            case 3: // Search a Node
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = searchNode(head, value);
                if (result != NULL) {
                    printf("Value %d found in the list.\n", value);
                } else {
                    printf("Value %d not found in the list.\n", value);
                }
                break;

            case 4: // Display List
                printf("Linked List: ");
                displayList(head);
                break;

            case 5: // Exit
                printf("Exiting program.\n");
                while (head != NULL) { // Free allocated memory
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0; // Program should never reach here
}
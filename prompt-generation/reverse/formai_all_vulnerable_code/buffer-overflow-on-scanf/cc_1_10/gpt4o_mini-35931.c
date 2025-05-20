//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertAtEnd(Node** head_ref, int new_data);
void deleteNode(Node** head_ref, int key);
void displayList(Node* node);
void puzzleOperation(Node* node);

int main() {
    Node* head = NULL; // Initially, the list is empty
    int choice, data;

    // A colorful journey begins!
    printf("Welcome to the Mystical Linked List Adventure!\n");

    while (1) {
        printf("\nChoose your path:\n");
        printf("1. Insert node\n");
        printf("2. Delete node\n");
        printf("3. Display list\n");
        printf("4. Puzzle operation\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("Node with data %d has been added to the magic list!\n", data);
                break;
            case 2:
                printf("Enter data of node to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Here is the mystical list:\n");
                displayList(head);
                break;
            case 4:
                printf("Engaging the puzzle operation...\n");
                puzzleOperation(head);
                break;
            case 5:
                printf("Thank you for your adventure, see you next time!\n");
                exit(0);
            default:
                printf("Invalid choice, seek another path!\n");
                break;
        }
    }
    return 0;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node** head_ref, int new_data) {
    Node* newNode = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    Node* last = *head_ref;
    while (last->next) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to delete a node by key
void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref, *prev = NULL;

    // If the head node itself is to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // Free old head
        printf("Node with data %d removed from the mystical list!\n", key);
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not found in the list
    if (temp == NULL) {
        printf("Node with data %d not found in the mystical list!\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free memory
    printf("Node with data %d removed from the mystical list!\n", key);
}

// Function to display the linked list
void displayList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Puzzle operation that reverses the linked list and displays it
void puzzleOperation(Node* node) {
    Node* prev = NULL;
    Node* current = node;
    Node* next = NULL;

    // Reverse the linked list
    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's link
        prev = current;       // Move pointers one position ahead
        current = next;
    }

    // Display the reversed list
    printf("The mystical list has been reversed!\n");
    displayList(prev);
}
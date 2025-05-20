//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a list node
typedef struct Node {
    char name[50];
    int id;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(char* name, int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(Node** head, char* name, int id) {
    Node* newNode = createNode(name, id);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = head;
    printf("List of Nodes:\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

// Function to delete a node by ID
void deleteNode(Node** head, int id) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;

    // If the head node is to be deleted
    if (temp != NULL && temp->id == id) {
        *head = temp->next; // Change head
        free(temp);         // Free old head
        printf("Node with ID %d deleted.\n", id);
        return;
    }

    // Traverse the list to find the node to delete
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    // If the ID was not present in the list
    if (temp == NULL) {
        printf("Node with ID %d not found.\n", id);
        return;
    }

    prev->next = temp->next; // Unlink the node from the list
    free(temp);              // Free the memory
    printf("Node with ID %d deleted.\n", id);
}

// Function to free the entire list
void freeList(Node** head) {
    Node* temp = *head;
    Node* nextNode;

    while (temp != NULL) {
        nextNode = temp->next; // Store next node
        free(temp);            // Free current node
        temp = nextNode;       // Move to the next node
    }
    *head = NULL;              // Set head to NULL
    printf("All nodes deleted. List is now empty.\n");
}

int main() {
    Node* head = NULL; // Initialize head as NULL
    int choice, id;
    char name[50];

    do {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Delete Node by ID\n");
        printf("4. Free List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                insertEnd(&head, name, id);
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteNode(&head, id);
                break;

            case 4:
                freeList(&head);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Free the memory before exiting
    freeList(&head);
    return 0;
}
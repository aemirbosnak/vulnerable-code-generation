//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void appendNode(Node** head, int data);
void displayList(Node* head);
void deleteNode(Node** head, int key);
void freeList(Node** head);

int main() {
    Node* head = NULL; // Initialize head of the list
    int choice, data;

    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Append Node\n");
        printf("2. Display List\n");
        printf("3. Delete Node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to append: ");
                scanf("%d", &data);
                appendNode(&head, data);
                printf("Node with data %d appended.\n", data);
                break;

            case 2:
                printf("Current Linked List: ");
                displayList(head);
                break;

            case 3:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;

            case 4:
                freeList(&head);
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the list
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
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

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node by value
void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        printf("Node with data %d deleted.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted.\n", key);
}

// Function to free the linked list
void freeList(Node** head) {
    Node* current = *head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    *head = NULL; // Update head to be NULL
}
//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a linked list node
typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(const char* data);
void insertAtEnd(Node** head, const char* data);
void deleteNode(Node** head, const char* data);
void displayList(Node* head);
void freeList(Node** head);

// Main function
int main() {
    Node* head = NULL; // Initialize the linked list as empty
    int choice;
    char data[100];

    while (1) {
        printf("\n--- Linked List Operations Menu ---\n");
        printf("1. Insert Node at End\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = 0; // Remove the newline character
                insertAtEnd(&head, data);
                printf("Node inserted successfully.\n");
                break;

            case 2:
                printf("Enter data to delete: ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = 0; // Remove the newline character
                deleteNode(&head, data);
                break;

            case 3:
                printf("Current linked list:\n");
                displayList(head);
                break;

            case 4:
                freeList(&head);
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}

// Function to create a new node
Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    strncpy(newNode->data, data, sizeof(newNode->data));
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, const char* data) {
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

// Function to delete a node by data
void deleteNode(Node** head, const char* data) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && strcmp(temp->data, data) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Data '%s' not found in list.\n", data);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Node with data '%s' deleted successfully.\n", data);
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    *head = NULL;
}
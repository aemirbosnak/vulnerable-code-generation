//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Node Structure Definition
typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

// Function Prototypes
Node* createNode(const char* name);
void insertNode(Node** head, const char* name);
void deleteNode(Node** head, const char* name);
void displayList(Node* head);
Node* searchNode(Node* head, const char* name);
void freeList(Node** head);

// Main Function
int main() {
    Node* head = NULL;
    int choice;
    char name[MAX_NAME_LENGTH];

    do {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert a Node\n");
        printf("2. Delete a Node\n");
        printf("3. Display List\n");
        printf("4. Search Node\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // Clear newline after scanf

        switch (choice) {
            case 1:
                printf("Enter name to insert: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                insertNode(&head, name);
                break;
            case 2:
                printf("Enter name to delete: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                deleteNode(&head, name);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Enter name to search: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                Node* searchResult = searchNode(head, name);
                if (searchResult) {
                    printf("Node Found: %s\n", searchResult->name);
                } else {
                    printf("Node Not Found\n");
                }
                break;
            case 5:
                freeList(&head);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to create a new node
Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(Node** head, const char* name) {
    Node* newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node '%s' inserted successfully.\n", name);
}

// Function to delete a node by name
void deleteNode(Node** head, const char* name) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node '%s' not found!\n", name);
        return;
    }

    if (prev == NULL) {
        *head = temp->next; // Node is head
    } else {
        prev->next = temp->next; // Bypass the node to delete
    }
    free(temp);
    printf("Node '%s' deleted successfully.\n", name);
}

// Function to display the entire linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    printf("Current List:\n");
    Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for a node by name
Node* searchNode(Node* head, const char* name) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to free the linked list memory
void freeList(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}
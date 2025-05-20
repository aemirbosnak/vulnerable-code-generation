//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[50];
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(Node** head, const char* data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node at the beginning of the list
void insertBeginning(Node** head, const char* data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node by its value
void deleteNode(Node** head, const char* data) {
    if (*head == NULL) return;
    
    Node* temp = *head;
    Node* prev = NULL;

    if (strcmp(temp->data, data) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->data, data) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty!\n");
    } else {
        printf("The linked list contains:\n");
        while (temp != NULL) {
            printf("%s -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to search for a node by its value
int searchNode(Node* head, const char* data) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data, data) == 0) {
            return 1; // Found
        }
        temp = temp->next;
    }
    return 0; // Not found
}

// Function to free the whole list
void freeList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
}

// Puzzling main function
int main(void) {
    Node* myList = NULL;
    int choice;
    char value[50];

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at the End\n");
        printf("2. Insert at the Beginning\n");
        printf("3. Delete a Node\n");
        printf("4. Display List\n");
        printf("5. Search for a Node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // capture the newline character
        
        switch (choice) {
            case 1:
                printf("Enter a value to insert at the end: ");
                fgets(value, sizeof(value), stdin);
                value[strcspn(value, "\n")] = 0; // Remove trailing newline
                insertEnd(&myList, value);
                break;
            case 2:
                printf("Enter a value to insert at the beginning: ");
                fgets(value, sizeof(value), stdin);
                value[strcspn(value, "\n")] = 0; // Remove trailing newline
                insertBeginning(&myList, value);
                break;
            case 3:
                printf("Enter a value to delete: ");
                fgets(value, sizeof(value), stdin);
                value[strcspn(value, "\n")] = 0; // Remove trailing newline
                deleteNode(&myList, value);
                printf("%s has been deleted if it existed in the list.\n", value);
                break;
            case 4:
                displayList(myList);
                break;
            case 5:
                printf("Enter a value to search for: ");
                fgets(value, sizeof(value), stdin);
                value[strcspn(value, "\n")] = 0; // Remove trailing newline
                if (searchNode(myList, value)) {
                    printf("%s found in the list!\n", value);
                } else {
                    printf("%s not found in the list.\n", value);
                }
                break;
            case 6:
                freeList(myList);
                printf("Exiting the program. Memory cleared. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
}
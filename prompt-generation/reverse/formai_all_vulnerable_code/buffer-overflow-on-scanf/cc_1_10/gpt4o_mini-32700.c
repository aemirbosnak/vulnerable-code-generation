//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(Node** head, int data) {
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

// Function to display the list
void displayList(Node* head) {
    Node* temp = head;
    if (!temp) {
        printf("List is empty!\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node by value
void deleteNode(Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    
    Node* temp = *head;
    Node* prev = NULL;
    
    // Check for the head node
    if (temp != NULL && temp->data == value) {
        *head = temp->next;  // Change the head
        free(temp);          // Free old head
        printf("Deleted %d from the list\n", value);
        return;
    }

    // Search for the value to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Value was not found
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp); // Free the memory
    printf("Deleted %d from the list\n", value);
}

// Function to free the entire list
void freeList(Node** head) {
    Node* current = *head;
    Node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    *head = NULL; // Reset head to NULL
    printf("Freed the entire list.\n");
}

// Interactive menu
void menu() {
    printf("Linked List Operations:\n");
    printf("1. Insert at End\n");
    printf("2. Display List\n");
    printf("3. Delete Node by Value\n");
    printf("4. Free List\n");
    printf("5. Exit\n");
}

int main() {
    Node* head = NULL;
    int choice, value;

    while (1) {
        menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) == 1) {
                    insertAtEnd(&head, value);
                    printf("Inserted %d into the list.\n", value);
                } else {
                    fprintf(stderr, "Invalid input. Please enter a number.\n");
                    while(getchar() != '\n'); // Clear invalid input
                }
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) == 1) {
                    deleteNode(&head, value);
                } else {
                    fprintf(stderr, "Invalid input. Please enter a number.\n");
                    while(getchar() != '\n'); // Clear invalid input
                }
                break;

            case 4:
                freeList(&head);
                break;

            case 5:
                freeList(&head); // Free memory before exit
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
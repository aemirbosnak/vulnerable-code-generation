//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

Node* head = NULL; // Head of the linked list

// Function to create a new node with given data
Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->data, data, sizeof(newNode->data) - 1);
    newNode->data[sizeof(newNode->data) - 1] = '\0';
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(const char* data) {
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node with data '%s' inserted at the end.\n", data);
}

// Function to show the contents of the linked list
void displayList() {
    if (!head) {
        printf("The linked list is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Current contents of the linked list:\n");
    while (temp) {
        printf("- %s\n", temp->data);
        temp = temp->next;
    }
}

// Function to delete a node by its data value
void deleteNode(const char* data) {
    if (!head) {
        printf("The linked list is empty. Nothing to delete.\n");
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    
    while (temp && strcmp(temp->data, data) != 0) {
        prev = temp;
        temp = temp->next;
    }
    
    if (!temp) {
        printf("Node with data '%s' not found.\n", data);
        return;
    }
    
    if (prev) {
        prev->next = temp->next;
    } else {
        head = temp->next; // Node to be deleted was the head
    }
    
    free(temp);
    printf("Node with data '%s' deleted.\n", data);
}

// Function to search for a node by its data value
void searchNode(const char* data) {
    Node* temp = head;
    int found = 0;
    
    while (temp) {
        if (strcmp(temp->data, data) == 0) {
            found = 1;
            break;
        }
        temp = temp->next;
    }
    
    if (found) {
        printf("Node with data '%s' found in the linked list.\n", data);
    } else {
        printf("Node with data '%s' not found.\n", data);
    }
}

// Function to clear the linked list and free memory
void clearList() {
    Node* temp = head;
    while (temp) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
    printf("The linked list has been cleared.\n");
}

// Function to get the count of nodes in the list
int countNodes() {
    int count = 0;
    Node* temp = head;
    
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int choice;
    char data[100];

    printf("Welcome to the Intergalactic Linked List Manager!\n");
    printf("Use this utility to manage your linked list in the year 3023.\n");

    do {
        printf("\nChoose an operation:\n");
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Delete Node\n");
        printf("4. Search Node\n");
        printf("5. Count Nodes\n");
        printf("6. Clear List\n");
        printf("7. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // Clearing newline character from buffer
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                fgets(data, sizeof(data), stdin);
                strtok(data, "\n"); // Remove newline character
                insertAtEnd(data);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter data to delete: ");
                fgets(data, sizeof(data), stdin);
                strtok(data, "\n");
                deleteNode(data);
                break;
            case 4:
                printf("Enter data to search: ");
                fgets(data, sizeof(data), stdin);
                strtok(data, "\n");
                searchNode(data);
                break;
            case 5:
                printf("Total nodes in the list: %d\n", countNodes());
                break;
            case 6:
                clearList();
                break;
            case 7:
                printf("Exiting the Intergalactic Linked List Manager. Goodbye!\n");
                clearList(); // Cleanup before exit
                break;
            default:
                printf("Invalid choice! Please select a valid operation.\n");
        }
    } while (choice != 7);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for each node in the linked list
struct Node {
    char data[256];
    struct Node* next;
};

// Function to create a new node and return its pointer
struct Node* createNode(char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertEnd(struct Node** head_ref, char* new_data) {
    struct Node* newNode = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to display the linked list
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty!\n");
        return;
    }
    printf("Here are the elements in our magical linked list:\n");
    while (node != NULL) {
        printf("-> %s ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to delete a node by its value
void deleteNode(struct Node** head_ref, char* key) {
    struct Node* temp = *head_ref, *prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && strcmp(temp->data, key) == 0) {
        *head_ref = temp->next; // Changed head
        free(temp); // Free old head
        printf("The element '%s' was successfully deleted!\n", key);
        return;
    }
    
    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && strcmp(temp->data, key) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the linked list
    if (temp == NULL) {
        printf("The element '%s' was not found in the list!\n", key);
        return;
    }
    
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
    printf("The element '%s' was successfully deleted!\n", key);
}

// Function to search for a specific value in the linked list
void searchList(struct Node* node, char* key) {
    int position = 0;
    while (node != NULL) {
        if (strcmp(node->data, key) == 0) {
            printf("Element '%s' found at position %d!\n", key, position);
            return;
        }
        position++;
        node = node->next;
    }
    printf("Element '%s' not found in the list!\n", key);
}

// Main function to demonstrate the linked list operations
int main() {
    struct Node* head = NULL;
    char input[256];
    int choice;

    printf("Welcome to the enchanted Linked List Adventure!\n");
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Delete an Element\n");
        printf("4. Search for an Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after integer input

        switch (choice) {
            case 1:
                printf("Enter a magical string to insert: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                insertEnd(&head, input);
                printf("Element '%s' inserted!\n", input);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter the magical string to delete: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                deleteNode(&head, input);
                break;
            case 4:
                printf("Enter the magical string to search: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                searchList(head, input);
                break;
            case 5:
                printf("Farewell, brave adventurer!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
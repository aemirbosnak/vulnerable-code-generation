//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a single node in the linked list
typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of the linked list
void append(Node** head_ref, const char* new_data) {
    Node* new_node = createNode(new_data);
    Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    while (last->next != NULL)
        last = last->next;
    
    last->next = new_node;
}

// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to delete the first node with the specified value
void deleteNode(Node** head_ref, const char* key) {
    Node* temp = *head_ref, *prev = NULL;

    if (temp != NULL && strcmp(temp->data, key) == 0) {
        *head_ref = temp->next; 
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->data, key) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;
    
    prev->next = temp->next;
    free(temp);
}

// Function to free the entire linked list
void freeList(Node* head) {
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Main function to demonstrate linked list operations
int main() {
    Node* head = NULL;
    char input[100];
    int choice;
    
    printf("Linked List Operations Menu\n");
    printf("1. Append a node\n");
    printf("2. Print the list\n");
    printf("3. Delete a node\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // To handle newline after integer input

        switch (choice) {
            case 1:
                printf("Enter data to append: ");
                fgets(input, sizeof(input), stdin);
                strtok(input, "\n"); // Remove the newline character
                append(&head, input);
                printf("Node appended: %s\n", input);
                break;

            case 2:
                printf("Linked List: ");
                printList(head);
                break;

            case 3:
                printf("Enter data to delete: ");
                fgets(input, sizeof(input), stdin);
                strtok(input, "\n");
                deleteNode(&head, input);
                printf("Node deleted: %s\n", input);
                break;

            case 4:
                freeList(head);
                printf("Exiting the program...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
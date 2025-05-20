//FormAI DATASET v1.0 Category: Mailing list manager ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Linked list structure for storing email addresses
typedef struct node {
    char email[100];
    struct node* next;
} Node;

// Function to add a new email address to the list
void addEmail(Node** head, char* email) {
    // Create new node
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->email, email);
    new_node->next = NULL;
    
    // Add new node to end of list
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print all email addresses in the list
void printEmails(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

// Function to delete a specific email address from the list
void deleteEmail(Node** head, char* email) {
    Node* current = *head;
    Node* previous = NULL;
    
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            // Found email address to delete
            if (previous == NULL) {
                // Deleting first node
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    int choice;
    
    while (1) {
        printf("Mailing List Manager\n");
        printf("--------------------\n");
        printf("1. Add email address\n");
        printf("2. Remove email address\n");
        printf("3. Print all email addresses\n");
        printf("0. Quit\n");
        
        // Get user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Add email address
                printf("Enter email address to add: ");
                char email[100];
                scanf("%s", email);
                addEmail(&head, email);
                printf("Email address added!\n");
                break;
            case 2:
                // Remove email address
                printf("Enter email address to remove: ");
                char email_to_remove[100];
                scanf("%s", email_to_remove);
                deleteEmail(&head, email_to_remove);
                printf("Email address removed!\n");
                break;
            case 3:
                // Print all email addresses
                printEmails(head);
                break;
            case 0:
                // Quit
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        
        printf("\n");
    }
    
    return 0;
}
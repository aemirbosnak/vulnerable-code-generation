//FormAI DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define struct for each email in mailing list
typedef struct email {
    char name[50];
    char address[50];
    struct email *next;
} Email;

// Function to add a new email to the end of the mailing list
void addEmail(Email **head, char *name, char* address) {
    Email *newEmail = (Email*) malloc(sizeof(Email));
    if (newEmail == NULL) { // Check if memory allocation failed
        printf("Memory allocation failed");
        exit(1);
    }
    // Assign name and address to the new email
    strcpy(newEmail->name, name);
    strcpy(newEmail->address, address);

    // If head is null, then this email is the first in the list
    if (*head == NULL) {
        *head = newEmail;
        return;
    }

    // Otherwise, traverse the list to find the last email and insert new email after it
    Email *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newEmail;
}

// Function to remove an email from the mailing list
void removeEmail(Email **head, char* address) {
    // Check if the list is empty
    if (*head == NULL) {
        printf("Mailing list is empty\n");
        return;
    }

    // If the email to remove is the head email
    if (strcmp((*head)->address, address) == 0) {
        Email *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Traverse the list to find the email to remove
    Email *current = *head;
    while (current->next != NULL) {
        if (strcmp(current->next->address, address) == 0) {
            Email *temp = current->next;
            current->next = temp->next;
            free(temp);
            return;
        }
        current = current->next;
    }
    printf("Email not found in mailing list\n");
}

// Function to print all emails in the mailing list
void printList(Email *head) {
    if (head == NULL) {
        printf("Mailing list is empty\n");
        return;
    }
    Email *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->address);
        current = current->next;
    }
}

// Main function to test the mailing list manager
int main() {
    Email *head = NULL; // Initialize the mailing list to be empty
    int choice;
    char name[50], address[50];

    printf("Welcome to the mailing list manager!\n");

    // Main menu loop
    do {
        printf("\n---Main Menu---\n");
        printf("1. Add new email\n");
        printf("2. Remove an email\n");
        printf("3. Print mailing list\n");
        printf("4. Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add new email
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email address: ");
                scanf("%s", address);
                addEmail(&head, name, address);
                printf("Email added to mailing list.\n");
                break;

            case 2: // Remove an email
                printf("Enter email address to remove: ");
                scanf("%s", address);
                removeEmail(&head, address);
                break;

            case 3: // Print mailing list
                printf("\n---Mailing List---\n");
                printList(head);
                break;

            case 4: // Exit
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
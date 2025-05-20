//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold email data
typedef struct email {
    char* name;
    char* address;
    struct email* next;
} Email;

// Declare helper functions
void addEmail(Email** head, char* name, char* address);

int main() {
    // Declare variables
    char input[100];
    char* name;
    char* address;
    Email* head = NULL;

    // Prompt user for input
    printf("Enter 'add' to add an email or 'quit' to exit.\n");

    // Loop until user enters 'quit'
    while (strcmp(input, "quit") != 0) {
        // Get user input
        printf("> ");
        scanf("%s", input);

        // Handle 'add' command
        if (strcmp(input, "add") == 0) {
            // Prompt user for name and address
            printf("Name: ");
            scanf("%s", input);
            name = (char*) malloc(strlen(input) + 1);
            strcpy(name, input);

            printf("Email Address: ");
            scanf("%s", input);
            address = (char*) malloc(strlen(input) + 1);
            strcpy(address, input);

            // Add email to mailing list
            addEmail(&head, name, address);
        }
    }

    // Print out all email data and free memory
    Email* current = head;
    while (current != NULL) {
        printf("%s - %s\n", current->name, current->address);
        Email* temp = current;
        current = current->next;
        free(temp->name);
        free(temp->address);
        free(temp);
    }

    return 0;
}

// Add a new email to the mailing list
void addEmail(Email** head, char* name, char* address) {
    // Create a new email struct
    Email* newEmail = (Email*) malloc(sizeof(Email));
    newEmail->name = name;
    newEmail->address = address;
    newEmail->next = NULL;

    // Add new email to the end of the list
    if (*head == NULL) {
        *head = newEmail;
    } else {
        Email* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEmail;
    }
}
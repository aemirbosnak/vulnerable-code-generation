//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
/*
 * C Mailing List Manager Example Program
 *
 * This program stores a mailing list in memory and provides
 * functionality for adding, searching, and deleting emails.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 50
#define MAX_LIST_SIZE 100

// Define struct for email entry
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} EmailEntry;

// Declare global variables
EmailEntry mailing_list[MAX_LIST_SIZE];
int list_size = 0;

// Function prototypes
void add_email();
void search_email();
void delete_email();
void print_list();

int main() {
    int choice;

    // Main menu loop
    while (1) {
        printf("Main Menu\n");
        printf("1. Add Email\n");
        printf("2. Search Email\n");
        printf("3. Delete Email\n");
        printf("4. Print Mailing List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        // Switch statement for menu choice
        switch (choice) {
            case 1:
                add_email();
                break;

            case 2:
                search_email();
                break;

            case 3:
                delete_email();
                break;

            case 4:
                print_list();
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to add a new email to the mailing list
void add_email() {
    EmailEntry new_email;

    // Get user input for name and email
    printf("Enter name: ");
    fgets(new_email.name, MAX_NAME_LENGTH, stdin);
    printf("Enter email: ");
    fgets(new_email.email, MAX_EMAIL_LENGTH, stdin);

    // Check if email already exists in list
    for (int i = 0; i < list_size; i++) {
        if (strcmp(mailing_list[i].email, new_email.email) == 0) {
            printf("Email already exists in list.\n");
            return;
        }
    }

    // Add new email to end of mailing list
    mailing_list[list_size] = new_email;
    list_size++;

    printf("Email added to list.\n");
}

// Function to search for an email in the mailing list
void search_email() {
    char search_term[MAX_EMAIL_LENGTH];

    // Get search term from user input
    printf("Enter email to search for: ");
    fgets(search_term, MAX_EMAIL_LENGTH, stdin);

    // Loop through mailing list to find email
    for (int i = 0; i < list_size; i++) {
        if (strcmp(mailing_list[i].email, search_term) == 0) {
            printf("Name: %sEmail: %s", mailing_list[i].name, mailing_list[i].email);
            return;
        }
    }

    printf("Email not found.\n");
}

// Function to delete an email from the mailing list
void delete_email() {
    char search_term[MAX_EMAIL_LENGTH];

    // Get search term from user input
    printf("Enter email to delete: ");
    fgets(search_term, MAX_EMAIL_LENGTH, stdin);

    // Loop through mailing list to find email
    for (int i = 0; i < list_size; i++) {
        if (strcmp(mailing_list[i].email, search_term) == 0) {
            // Shift all entries after the deleted entry to the left
            for (int j = i; j < list_size - 1; j++) {
                strcpy(mailing_list[j].name, mailing_list[j+1].name);
                strcpy(mailing_list[j].email, mailing_list[j+1].email);
            }

            // Decrement list size and exit function
            list_size--;
            printf("Email deleted from list.\n");
            return;
        }
    }

    printf("Email not found.\n");
}

// Function to print the entire mailing list
void print_list() {
    if (list_size == 0) {
        printf("Mailing list is empty.\n");
        return;
    }

    printf("Mailing List:\n");
    printf("---------------------------------------\n");

    for (int i = 0; i < list_size; i++) {
        printf("Name: %sEmail: %s", mailing_list[i].name, mailing_list[i].email);
        printf("---------------------------------------\n");
    }
}
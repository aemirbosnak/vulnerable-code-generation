//FormAI DATASET v1.0 Category: Mailing list manager ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100 // Maximum number of emails that can be stored
#define MAX_NAME_LENGTH 50 // Maximum length for name
#define MAX_EMAIL_LENGTH 100 // Maximum length for email address

// Structure to store information for each email
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Email;

// Function to add a new email to the mailing list
void add_email(Email *mail_list, int *num_emails) {
    // Check if maximum number of emails has been reached
    if (*num_emails >= MAX_EMAILS) {
        printf("Maximum number of emails reached. Cannot add more.\n");
        return;
    }

    // Prompt user for name and email
    printf("Enter name: ");
    fgets(mail_list[*num_emails].name, MAX_NAME_LENGTH, stdin);
    printf("Enter email address: ");
    fgets(mail_list[*num_emails].email, MAX_EMAIL_LENGTH, stdin);

    // Remove newline character from input
    mail_list[*num_emails].name[strcspn(mail_list[*num_emails].name, "\n")] = '\0';
    mail_list[*num_emails].email[strcspn(mail_list[*num_emails].email, "\n")] = '\0';

    // Increment number of emails
    (*num_emails)++;
}

// Function to print all emails in the mailing list
void print_emails(Email *mail_list, int num_emails) {
    // Check if there are any emails
    if (num_emails == 0) {
        printf("No emails in the list.\n");
        return;
    }

    // Print header for email list
    printf("Name\t\tEmail\n");
    printf("----\t\t-----\n");

    // Loop through all emails and print information
    for (int i = 0; i < num_emails; i++) {
        printf("%s\t\t%s\n", mail_list[i].name, mail_list[i].email);
    }
}

int main() {
    Email mail_list[MAX_EMAILS]; // Array to store all emails
    int num_emails = 0; // Number of emails currently in the list
    int choice; // User's choice from menu

    // Loop to display menu until user chooses to exit
    while (1) {
        // Display menu to user
        printf("\nMenu\n----\n");
        printf("1. Add email\n");
        printf("2. Print all emails\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left in input buffer

        // Perform action based on user's choice
        switch (choice) {
            case 1:
                add_email(mail_list, &num_emails);
                break;
            case 2:
                print_emails(mail_list, num_emails);
                break;
            case 3:
                // Exit program
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
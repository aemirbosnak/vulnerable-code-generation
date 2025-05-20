//FormAI DATASET v1.0 Category: Mailing list manager ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000     // Maximum number of emails permitted in the list

int main() {
    char emails[MAX_EMAILS][50];     // Create a list of emails
    int num_emails = 0;              // Keep track of number of emails in the list

    // Menu options
    printf("Welcome to the Mailing List Manager\n");
    printf("------------------------------------\n");
    printf("1. Add an email address\n");
    printf("2. Delete an email address\n");
    printf("3. Display all email addresses\n");
    printf("4. Exit program\n\n");

    int option;
    do {
        printf("Enter your option (1-4): ");
        scanf("%d", &option);

        switch(option) {
            case 1: // Add an email
                if(num_emails >= MAX_EMAILS) {
                    printf("Error: Maximum number of emails reached.\n");
                    break;
                }

                printf("Enter the email address: ");
                scanf("%s", emails[num_emails]);
                num_emails++;
                printf("Email added successfully.\n");
                break;

            case 2: // Delete an email
                if(num_emails == 0) {
                    printf("Error: No emails found.\n");
                    break;
                }

                printf("Enter the email address to delete: ");
                char email_to_delete[50];
                scanf("%s", email_to_delete);

                int index_to_delete = -1; // Assume email doesn't exist
                for(int i = 0; i < num_emails; i++) {
                    if(strcmp(emails[i], email_to_delete) == 0) {
                        index_to_delete = i;
                        break;
                    }
                }

                if(index_to_delete == -1)
                    printf("Error: Email not found.\n");
                else {
                    for(int i = index_to_delete; i < num_emails-1; i++)
                        strcpy(emails[i], emails[i+1]);
                    num_emails--;
                    printf("Email deleted successfully.\n");
                }

                break;

            case 3: // Display all emails
                if(num_emails == 0) {
                    printf("No emails found.\n");
                    break;
                }

                printf("Email addresses:\n");
                for(int i = 0; i < num_emails; i++)
                    printf("%d. %s\n", i+1, emails[i]);

                break;

            case 4: // Exit program
                printf("Exiting program...\n");
                break;

            default:
                printf("Error: Invalid option selected. Please enter a number between 1 and 4.\n");
                break;
        }

        printf("\n");
    } while(option != 4);

    return 0;
}
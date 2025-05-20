//FormAI DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LEN 50

int main()
{
    int num_emails = 0;
    char emails[MAX_EMAILS][MAX_EMAIL_LEN];

    printf("Welcome to the mailing list manager!\n");

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Add email\n");
        printf("2. View all emails\n");
        printf("3. Delete email\n");
        printf("4. Exit\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1: // add email
                if (num_emails == MAX_EMAILS) {
                    printf("Sorry, the mailing list is full.\n");
                    break;
                }
                
                printf("Enter email address: ");
                char new_email[MAX_EMAIL_LEN];
                scanf("%s", new_email);

                // check if email already exists in list
                int i;
                for (i = 0; i < num_emails; i++) {
                    if (strcmp(emails[i], new_email) == 0) {
                        printf("Email already exists in the list.\n");
                        break;
                    }
                }

                // add new email to list
                if (i == num_emails) {
                    strcpy(emails[num_emails], new_email);
                    num_emails++;
                    printf("Email added to the list.\n");
                }
                break;

            case 2: // view all emails
                if (num_emails == 0) {
                    printf("No emails in list.\n");
                    break;
                }
                
                printf("Current emails in list:\n");
                for (int i = 0; i < num_emails; i++) {
                    printf("%s\n", emails[i]);
                }
                break;

            case 3: // delete email
                if (num_emails == 0) {
                    printf("No emails in list.\n");
                    break;
                }
                
                printf("Enter the email address to be deleted: ");
                char del_email[MAX_EMAIL_LEN];
                scanf("%s", del_email);

                int del_index = -1;
                for (int i = 0; i < num_emails; i++) {
                    if (strcmp(emails[i], del_email) == 0) {
                        del_index = i;
                        break;
                    }
                }

                if (del_index != -1) {
                    printf("Email %s deleted from the list.\n", emails[del_index]);

                    // remove email from list by shifting rest of emails to left
                    for (int i = del_index; i < num_emails-1; i++) {
                        strcpy(emails[i], emails[i+1]);
                    }
                    num_emails--;
                }
                else {
                    printf("Email not found in list.\n");
                }
                break;

            case 4: // exit
                printf("Goodbye!\n");
                exit(0);

            default: // invalid option
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}
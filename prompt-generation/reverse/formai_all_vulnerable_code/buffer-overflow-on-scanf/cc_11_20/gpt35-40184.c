//FormAI DATASET v1.0 Category: Mailing list manager ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50
#define MAX_EMAILS 10

int main() {
    char emails[MAX_EMAILS][MAX_LEN];
    int num_emails = 0;
    char user_input[MAX_LEN];
    int choice = 0;

    printf("Welcome to the mailing list manager!\n");

    while(1) {
        printf("\nPlease select an option:\n");
        printf("1. Add email address\n");
        printf("2. Remove email address\n");
        printf("3. Show all email addresses\n");
        printf("4. Quit\n");

        // get user choice
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_emails >= MAX_EMAILS) {
                    printf("Maximum number of emails reached.\n");
                    break;
                }

                printf("Please enter email address to add: ");
                scanf("%s", user_input);

                // check if email already exists
                for(int i = 0; i < num_emails; i++) {
                    if(strcmp(user_input, emails[i]) == 0) {
                        printf("Email already exists in the list.\n");
                        break;
                    }
                }

                // add email to list
                strcpy(emails[num_emails], user_input);
                num_emails++;

                printf("Email added successfully.\n");
                break;

            case 2:
                if(num_emails == 0) {
                    printf("No emails in the list.\n");
                    break;
                }

                printf("Please enter email address to remove: ");
                scanf("%s", user_input);

                // find and remove email from list
                int index = -1;
                for(int i = 0; i < num_emails; i++) {
                    if(strcmp(user_input, emails[i]) == 0) {
                        index = i;
                        break;
                    }
                }

                if(index == -1) {
                    printf("Email not found in the list.\n");
                } else {
                    // shift emails to fill the gap
                    for(int i = index; i < num_emails - 1; i++) {
                        strcpy(emails[i], emails[i+1]);
                    }

                    num_emails--;

                    printf("Email removed successfully.\n");
                }

                break;

            case 3:
                if(num_emails == 0) {
                    printf("No emails in the list.\n");
                    break;
                }

                printf("Emails in the list:\n");

                for(int i = 0; i < num_emails; i++) {
                    printf("%s\n", emails[i]);
                }

                break;

            case 4:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
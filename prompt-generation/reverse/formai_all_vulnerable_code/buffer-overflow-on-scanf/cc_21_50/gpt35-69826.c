//FormAI DATASET v1.0 Category: Mailing list manager ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000

struct Email {
    char recipient[50];
    char subject[100];
    char message[500];
};

struct MailingList {
    char name[50];
    struct Email emails[MAX_EMAILS];
    int num_emails;
};

struct MailingList mailing_lists[10];
int num_lists;

int main() {
    printf("Welcome to the Mailing List Manager!\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Create a new mailing list\n");
        printf("2. Add an email to a mailing list\n");
        printf("3. Remove an email from a mailing list\n");
        printf("4. List all emails in a mailing list\n");
        printf("5. Quit\n");

        int selection;
        scanf("%d", &selection);

        if (selection == 1) {
            printf("Enter the name of the new mailing list: ");
            char name[50];
            scanf("%s", name);

            strcpy(mailing_lists[num_lists].name, name);
            mailing_lists[num_lists].num_emails = 0;
            num_lists++;

            printf("Mailing list '%s' created successfully.\n", name);
        } else if (selection == 2) {
            printf("Enter the name of the mailing list to add the email to: ");
            char name[50];
            scanf("%s", name);

            int list_index = -1;
            for (int i = 0; i < num_lists; i++) {
                if (strcmp(mailing_lists[i].name, name) == 0) {
                    list_index = i;
                    break;
                }
            }

            if (list_index == -1) {
                printf("Mailing list '%s' not found.\n", name);
                continue;
            }

            printf("Enter the recipient's email address: ");
            char recipient[50];
            scanf("%s", recipient);

            printf("Enter the email subject: ");
            char subject[100];
            scanf("%s", subject);

            printf("Enter the email message: ");
            char message[500];
            scanf("%s", message);

            struct Email new_email;
            strcpy(new_email.recipient, recipient);
            strcpy(new_email.subject, subject);
            strcpy(new_email.message, message);

            mailing_lists[list_index].emails[mailing_lists[list_index].num_emails] = new_email;
            mailing_lists[list_index].num_emails++;

            printf("Email added to mailing list '%s' successfully.\n", name);
        } else if (selection == 3) {
            printf("Enter the name of the mailing list to remove the email from: ");
            char name[50];
            scanf("%s", name);

            int list_index = -1;
            for (int i = 0; i < num_lists; i++) {
                if (strcmp(mailing_lists[i].name, name) == 0) {
                    list_index = i;
                    break;
                }
            }

            if (list_index == -1) {
                printf("Mailing list '%s' not found.\n", name);
                continue;
            }

            printf("Enter the recipient's email address to remove: ");
            char recipient[50];
            scanf("%s", recipient);

            int email_index = -1;
            for (int i = 0; i < mailing_lists[list_index].num_emails; i++) {
                if (strcmp(mailing_lists[list_index].emails[i].recipient, recipient) == 0) {
                    email_index = i;
                    break;
                }
            }

            if (email_index == -1) {
                printf("Email for recipient '%s' not found in mailing list '%s'.\n", recipient, name);
                continue;
            }

            for (int i = email_index; i < mailing_lists[list_index].num_emails - 1; i++) {
                mailing_lists[list_index].emails[i] = mailing_lists[list_index].emails[i+1];
            }
            mailing_lists[list_index].num_emails--;

            printf("Email for recipient '%s' removed from mailing list '%s' successfully.\n", recipient, name);
        } else if (selection == 4) {
            printf("Enter the name of the mailing list to list the emails for: ");
            char name[50];
            scanf("%s", name);

            int list_index = -1;
            for (int i = 0; i < num_lists; i++) {
                if (strcmp(mailing_lists[i].name, name) == 0) {
                    list_index = i;
                    break;
                }
            }

            if (list_index == -1) {
                printf("Mailing list '%s' not found.\n", name);
                continue;
            }

            printf("Emails in mailing list '%s':\n", name);
            for (int i = 0; i < mailing_lists[list_index].num_emails; i++) {
                printf("Recipient: %s\nSubject: %s\nMessage: %s\n\n",
                    mailing_lists[list_index].emails[i].recipient,
                    mailing_lists[list_index].emails[i].subject,
                    mailing_lists[list_index].emails[i].message);
            }
        } else if (selection == 5) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    }

    return 0;
}
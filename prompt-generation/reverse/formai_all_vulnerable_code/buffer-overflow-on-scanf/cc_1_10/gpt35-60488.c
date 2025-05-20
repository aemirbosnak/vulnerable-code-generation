//FormAI DATASET v1.0 Category: Email Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LEN 500
#define MAX_SUBJECT_LEN 50

typedef struct {
    char sender[MAX_EMAIL_LEN];
    char receiver[MAX_EMAIL_LEN];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_EMAIL_LEN];
} Email;

Email emails[MAX_EMAILS];
int email_count = 0;

int main(void)
{
    int choice;

    while (1) {
        printf("Welcome to the C Email Client\n");
        printf("----------------------------\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Compose Email\n");
                printf("-------------\n");
                getchar(); // Clear input buffer

                printf("Sender: ");
                fgets(emails[email_count].sender, MAX_EMAIL_LEN, stdin);
                strtok(emails[email_count].sender, "\n"); // Remove newline character

                printf("Receiver: ");
                fgets(emails[email_count].receiver, MAX_EMAIL_LEN, stdin);
                strtok(emails[email_count].receiver, "\n"); // Remove newline character

                printf("Subject: ");
                fgets(emails[email_count].subject, MAX_SUBJECT_LEN, stdin);
                strtok(emails[email_count].subject, "\n"); // Remove newline character

                printf("Body: ");
                fgets(emails[email_count].body, MAX_EMAIL_LEN, stdin);
                strtok(emails[email_count].body, "\n"); // Remove newline character

                printf("Email Sent.\n");
                email_count++;
                break;

            case 2:
                printf("Inbox\n");
                printf("-----\n");

                if (email_count == 0) {
                    printf("No emails to display.\n");
                } else {
                    for (int i = 0; i < email_count; i++) {
                        printf("From: %s\n", emails[i].sender);
                        printf("To: %s\n", emails[i].receiver);
                        printf("Subject: %s\n", emails[i].subject);
                        printf("Body: %s\n", emails[i].body);
                        printf("\n");
                    }
                }

                break;

            case 3:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n"); // Add blank line for readability
    }

    return 0;
}
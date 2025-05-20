//Falcon-180B DATASET v1.0 Category: Email Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_RECIPIENTS 10
#define MAX_SUBJECT_LENGTH 80
#define MAX_BODY_LENGTH 1024

struct Email {
    char sender[MAX_EMAILS];
    char recipient[MAX_RECIPIENTS][MAX_EMAILS];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
};

void sendEmail(struct Email* email) {
    printf("Sending an email to %s with subject '%s'...\n", email->recipient[0], email->subject);
}

void readEmail(struct Email* email) {
    printf("Reading an email from %s with subject '%s'...\n", email->sender, email->subject);
    printf("Body:\n%s\n", email->body);
}

int main() {
    struct Email emails[MAX_EMAILS];
    int numEmails = 0;

    while (1) {
        printf("\n1. Send an email\n2. Read an email\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numEmails >= MAX_EMAILS) {
                    printf("Sorry, you have reached the maximum number of emails.\n");
                    break;
                }

                printf("Enter the sender's email address: ");
                scanf("%s", emails[numEmails].sender);

                printf("Enter the recipient's email address: ");
                scanf("%s", emails[numEmails].recipient[0]);

                printf("Enter the subject of the email: ");
                scanf("%s", emails[numEmails].subject);

                printf("Enter the body of the email: ");
                fgets(emails[numEmails].body, MAX_BODY_LENGTH, stdin);

                time(&emails[numEmails].timestamp);
                numEmails++;

                printf("Email sent successfully!\n");
                break;

            case 2:
                if (numEmails == 0) {
                    printf("No emails to read.\n");
                    break;
                }

                int emailIndex;
                printf("Enter the index of the email you want to read: ");
                scanf("%d", &emailIndex);

                if (emailIndex >= numEmails) {
                    printf("Invalid email index.\n");
                    break;
                }

                readEmail(&emails[emailIndex]);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
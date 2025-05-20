//Falcon-180B DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256

typedef struct {
    char sender[MAX_EMAIL_LENGTH];
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_EMAIL_LENGTH];
} Email;

int main() {
    Email emails[MAX_EMAILS];
    int num_emails = 0;

    while (1) {
        printf("Enter's' to send an email, 'r' to read emails, or 'q' to quit: ");
        char choice;
        scanf("%c", &choice);

        if (choice =='s') {
            if (num_emails >= MAX_EMAILS) {
                printf("Error: Too many emails.\n");
                continue;
            }

            printf("Enter sender email address: ");
            scanf("%s", emails[num_emails].sender);

            printf("Enter recipient email address: ");
            scanf("%s", emails[num_emails].recipient);

            printf("Enter subject: ");
            scanf("%s", emails[num_emails].subject);

            printf("Enter body: ");
            scanf("%s", emails[num_emails].body);

            num_emails++;
        } else if (choice == 'r') {
            if (num_emails == 0) {
                printf("No emails to read.\n");
                continue;
            }

            printf("Email #%d:\n", num_emails - 1);
            printf("Sender: %s\n", emails[num_emails - 1].sender);
            printf("Recipient: %s\n", emails[num_emails - 1].recipient);
            printf("Subject: %s\n", emails[num_emails - 1].subject);
            printf("Body: %s\n", emails[num_emails - 1].body);
        } else if (choice == 'q') {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
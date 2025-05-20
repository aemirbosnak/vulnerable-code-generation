//Falcon-180B DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 80
#define MAX_BODY_LENGTH 1024
#define MAX_RECIPIENTS 10
#define MAX_ATTACHMENTS 5

typedef struct {
    char *subject;
    char *body;
    char *recipients[MAX_RECIPIENTS];
    char *attachments[MAX_ATTACHMENTS];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Email limit reached.\n");
        return;
    }

    Email *new_email = &emails[num_emails];

    printf("Subject: ");
    scanf("%s", new_email->subject);

    printf("Body: ");
    scanf("%[^\n]", new_email->body);

    int num_recipients = 0;
    printf("Recipients (comma-separated): ");
    scanf("%s", new_email->recipients[num_recipients]);
    while (num_recipients < MAX_RECIPIENTS - 1 && new_email->recipients[num_recipients][0]!= '\0') {
        num_recipients++;
        printf("Recipient %d: ", num_recipients);
        scanf("%s", new_email->recipients[num_recipients]);
    }

    int num_attachments = 0;
    printf("Attachments (comma-separated): ");
    scanf("%s", new_email->attachments[num_attachments]);
    while (num_attachments < MAX_ATTACHMENTS - 1 && new_email->attachments[num_attachments][0]!= '\0') {
        num_attachments++;
        printf("Attachment %d: ", num_attachments);
        scanf("%s", new_email->attachments[num_attachments]);
    }

    new_email->timestamp = time(NULL);
    num_emails++;
}

void view_emails() {
    printf("Subject\tBody\tRecipients\tAttachments\tTimestamp\n");
    for (int i = 0; i < num_emails; i++) {
        Email *email = &emails[i];
        printf("%s\t%s\t", email->subject, email->body);
        for (int j = 0; j < MAX_RECIPIENTS && email->recipients[j][0]!= '\0'; j++) {
            printf("%s ", email->recipients[j]);
        }
        for (int j = 0; j < MAX_ATTACHMENTS && email->attachments[j][0]!= '\0'; j++) {
            printf("%s ", email->attachments[j]);
        }
        printf("%ld\n", email->timestamp);
    }
}

int main() {
    printf("Welcome to the Email Client!\n");

    while (1) {
        printf("\n1. Add email\n2. View emails\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                view_emails();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
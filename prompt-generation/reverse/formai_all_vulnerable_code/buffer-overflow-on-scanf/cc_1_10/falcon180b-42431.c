//Falcon-180B DATASET v1.0 Category: Email Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_BODY_LENGTH 4096
#define MAX_ATTACHMENTS 10
#define MAX_ATTACHMENT_LENGTH 1024

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int attachments_count;
    char attachments[MAX_ATTACHMENTS][MAX_ATTACHMENT_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int email_count = 0;

void add_email() {
    if (email_count >= MAX_EMAILS) {
        printf("Email limit reached!\n");
        return;
    }

    Email new_email;
    printf("Enter the sender's email address: ");
    scanf("%s", new_email.from);
    printf("Enter the recipient's email address: ");
    scanf("%s", new_email.to);
    printf("Enter the subject: ");
    scanf("%s", new_email.subject);
    printf("Enter the body: ");
    scanf("%s", new_email.body);
    printf("Enter the number of attachments: ");
    scanf("%d", &new_email.attachments_count);

    for (int i = 0; i < new_email.attachments_count; i++) {
        printf("Enter attachment %d: ", i + 1);
        scanf("%s", new_email.attachments[i]);
    }

    new_email.timestamp = time(NULL);
    emails[email_count++] = new_email;
    printf("Email added successfully!\n");
}

void view_emails() {
    if (email_count == 0) {
        printf("No emails found!\n");
        return;
    }

    for (int i = 0; i < email_count; i++) {
        printf("Email %d:\n", i + 1);
        printf("From: %s\n", emails[i].from);
        printf("To: %s\n", emails[i].to);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n", emails[i].body);
        printf("Attachments:\n");

        for (int j = 0; j < emails[i].attachments_count; j++) {
            printf("- %s\n", emails[i].attachments[j]);
        }

        printf("Timestamp: %s\n\n", ctime(&emails[i].timestamp));
    }
}

int main() {
    int choice;
    do {
        printf("1. Add email\n2. View emails\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_email();
            break;
        case 2:
            view_emails();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}
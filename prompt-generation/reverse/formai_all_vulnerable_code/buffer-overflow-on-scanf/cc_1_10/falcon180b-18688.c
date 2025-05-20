//Falcon-180B DATASET v1.0 Category: Email Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_SENDER_LENGTH 100
#define MAX_RECIPIENT_LENGTH 100

typedef struct {
    char sender[MAX_SENDER_LENGTH];
    char recipient[MAX_RECIPIENT_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Email limit reached.\n");
        return;
    }

    Email new_email;
    printf("Enter sender email address: ");
    scanf("%s", new_email.sender);
    printf("Enter recipient email address: ");
    scanf("%s", new_email.recipient);
    printf("Enter subject: ");
    scanf("%s", new_email.subject);
    printf("Enter body: ");
    scanf("%s", new_email.body);
    new_email.timestamp = time(NULL);

    emails[num_emails++] = new_email;
    printf("Email added successfully.\n");
}

void view_emails() {
    if (num_emails == 0) {
        printf("No emails found.\n");
        return;
    }

    printf("Email list:\n");
    for (int i = 0; i < num_emails; i++) {
        Email email = emails[i];
        printf("%d. %s -> %s\n%s\n%s\n", i + 1, email.sender, email.recipient, email.subject, email.body);
    }
}

int main() {
    while (1) {
        printf("Email client:\n");
        printf("1. Add email\n2. View emails\n3. Exit\n");
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
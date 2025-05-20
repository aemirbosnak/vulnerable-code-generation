//Falcon-180B DATASET v1.0 Category: Email Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1024
#define MAX_RECIPIENTS 10

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_EMAIL_LENGTH];
    char message[MAX_EMAIL_LENGTH];
} email_t;

int num_emails = 0;
email_t emails[MAX_EMAILS];

void add_email() {
    if (num_emails == MAX_EMAILS) {
        printf("Error: Too many emails.\n");
        return;
    }

    email_t *e = &emails[num_emails];

    printf("Enter sender email: ");
    scanf("%s", e->from);

    printf("Enter recipient email: ");
    scanf("%s", e->to);

    printf("Enter subject: ");
    scanf("%s", e->subject);

    printf("Enter message: ");
    scanf("%[^\n]", e->message);

    num_emails++;
}

void send_emails() {
    for (int i = 0; i < num_emails; i++) {
        email_t *e = &emails[i];

        printf("Sending email from %s to %s with subject '%s'...\n", e->from, e->to, e->subject);

        // Simulate sending the email
        sleep(1);
    }
}

int main() {
    printf("Welcome to the Mind-Bending Email Client!\n");

    while (1) {
        printf("\n");
        printf("1. Add Email\n");
        printf("2. Send Emails\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_email();
            break;
        case 2:
            send_emails();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
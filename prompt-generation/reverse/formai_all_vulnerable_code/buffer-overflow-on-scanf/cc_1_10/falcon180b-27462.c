//Falcon-180B DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_EMAILS 1000

typedef struct {
    char* subject;
    char* body;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_LINE_LENGTH];

    printf("Enter email subject: ");
    fgets(subject, MAX_SUBJECT_LENGTH, stdin);
    subject[strcspn(subject, "\n")] = '\0';

    printf("Enter email body: ");
    fgets(body, MAX_LINE_LENGTH, stdin);
    body[strcspn(body, "\n")] = '\0';

    emails[num_emails].subject = strdup(subject);
    emails[num_emails].body = strdup(body);

    num_emails++;
}

void send_email(int index) {
    printf("Sending email with subject: %s\n", emails[index].subject);
    printf("Email body:\n%s\n", emails[index].body);
}

void main() {
    printf("Welcome to the surrealist email client.\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an email\n2. Send an email\n3. Exit\n");

        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_email();
                break;
            case '2':
                printf("Enter email index: ");
                int index;
                scanf("%d", &index);

                if (index >= 0 && index < num_emails) {
                    send_email(index);
                } else {
                    printf("Invalid email index.\n");
                }
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
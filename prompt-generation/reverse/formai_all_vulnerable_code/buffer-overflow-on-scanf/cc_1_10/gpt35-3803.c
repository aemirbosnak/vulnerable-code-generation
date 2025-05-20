//FormAI DATASET v1.0 Category: Email Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LEN 50 /* Maximum length of email subject */
#define MAX_BODY_LEN 500 /* Maximum length of email body */
#define MAX_EMAILS 100 /* Maximum number of emails in inbox */
#define MAX_SENDERS 50 /* Maximum number of unique senders */

/* Define structure for email message */
typedef struct email {
    char subject[MAX_SUBJECT_LEN];
    char sender[MAX_SENDERS];
    char body[MAX_BODY_LEN];
} Email;

/* Define structure for email inbox */
typedef struct inbox {
    Email emails[MAX_EMAILS];
    int count;
} Inbox;

/* Function to compose and send email */
void compose_email() {
    char subject[MAX_SUBJECT_LEN];
    char recipient[MAX_SENDERS];
    char body[MAX_BODY_LEN];

    printf("Enter the subject of the email: ");
    fgets(subject, MAX_SUBJECT_LEN, stdin);
    printf("Enter the recipient of the email: ");
    fgets(recipient, MAX_SENDERS, stdin);
    printf("Compose your email:\n");
    fgets(body, MAX_BODY_LEN, stdin);

    /* Code to send email would go here */
    printf("Email sent!\n");
}

/* Function to display email inbox */
void display_inbox(Inbox* inbox) {
    printf("You have %d emails in your inbox.\n", inbox->count);
    for (int i = 0; i < inbox->count; i++) {
        printf("From: %s\n", inbox->emails[i].sender);
        printf("Subject: %s\n", inbox->emails[i].subject);
        printf("Body: %s\n", inbox->emails[i].body);
        printf("----------------------------\n");
    }
}

int main() {
    Inbox inbox;
    inbox.count = 0;

    printf("Welcome to BraveMail!\n");

    while (1) {
        printf("Please choose an action:\n");
        printf("1. Compose and send email\n");
        printf("2. Check inbox\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);
        getchar(); /* consume newline character left in input buffer */

        switch (choice) {
            case 1:
                compose_email();
                break;
            case 2:
                display_inbox(&inbox);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
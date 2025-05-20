//FormAI DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 1000
#define MAX_SENDER_LENGTH 50
#define MAX_RECIPIENT_LENGTH 50

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char sender[MAX_SENDER_LENGTH];
    char recipient[MAX_RECIPIENT_LENGTH];
} email_t;

void display_inbox(email_t inbox[], int num_emails);
void display_email(email_t email);
void compose_email(email_t *email);
void send_email(email_t email);
void receive_email(email_t *email);

int main() {

    email_t inbox[MAX_EMAILS];
    int num_emails = 0;
    char choice;

    printf("Welcome to the Cyberpunk Email Client.\n");

    while (true) {
        printf("Enter 'c' to compose an email, 'r' to receive new emails, 'i' to display inbox, or 'q' to quit: ");
        scanf(" %c", &choice);

        switch(choice) {
            case 'c':
                compose_email(&inbox[num_emails++]);
                break;

            case 'r':
                receive_email(&inbox[num_emails++]);
                break;

            case 'i':
                display_inbox(inbox, num_emails);
                break;

            case 'q':
                printf("Goodbye.\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}

void display_inbox(email_t inbox[], int num_emails) {
    if (num_emails == 0) {
        printf("Inbox is empty.\n");
        return;
    }

    printf("Inbox:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%d. %s (from %s)\n", i + 1, inbox[i].subject, inbox[i].sender);
    }
}

void display_email(email_t email) {
    printf("Subject: %s\n", email.subject);
    printf("From: %s\n", email.sender);
    printf("To: %s\n", email.recipient);
    printf("Body: %s\n", email.body);
}

void compose_email(email_t *email) {
    printf("Compose an Email\n");
    printf("To: ");
    scanf(" %[^\n]s", email->recipient);
    printf("Subject: ");
    scanf(" %[^\n]s", email->subject);
    printf("Body: ");
    scanf(" %[^\n]s", email->body);

    // Set the sender to the user's email address
    strcpy(email->sender, "you@cyberpunk.com");

    printf("\nEmail sent!\n\n");
    send_email(*email);
}

void send_email(email_t email) {
    sleep(2); // Simulate sending email
}

void receive_email(email_t *email) {
    printf("Receiving new email...\n");

    // Simulate receiving email
    strcpy(email->sender, "someone@cybercorp.com");
    strcpy(email->recipient, "you@cyberpunk.com");
    strcpy(email->subject, "Important Message");
    strcpy(email->body, "Your password has been compromised. Please change it immediately.");

    printf("New email received:\n");
    display_email(*email);
}
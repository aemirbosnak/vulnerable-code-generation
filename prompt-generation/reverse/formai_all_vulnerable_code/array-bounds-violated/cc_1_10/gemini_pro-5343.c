//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LEN 30
#define MAX_EMAIL_LEN 50
#define MAX_SUBJECT_LEN 50
#define MAX_MESSAGE_LEN 1000

typedef struct email {
    char sender[MAX_NAME_LEN];
    char recipient[MAX_NAME_LEN];
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
} email;

void print_email(email *e) {
    printf("From: %s\n", e->sender);
    printf("To: %s\n", e->recipient);
    printf("Subject: %s\n", e->subject);
    printf("Message:\n%s\n", e->message);
}

int main() {
    email e;

    // Get the sender's name from the user.
    printf("Enter your name: ");
    fgets(e.sender, MAX_NAME_LEN, stdin);
    // Remove the newline character from the sender's name.
    e.sender[strlen(e.sender) - 1] = '\0';

    // Get the recipient's name from the user.
    printf("Enter the recipient's name: ");
    fgets(e.recipient, MAX_NAME_LEN, stdin);
    // Remove the newline character from the recipient's name.
    e.recipient[strlen(e.recipient) - 1] = '\0';

    // Get the subject of the email from the user.
    printf("Enter the subject of the email: ");
    fgets(e.subject, MAX_SUBJECT_LEN, stdin);
    // Remove the newline character from the subject of the email.
    e.subject[strlen(e.subject) - 1] = '\0';

    // Get the body of the email from the user.
    printf("Enter the body of the email: ");
    fgets(e.message, MAX_MESSAGE_LEN, stdin);
    // Remove the newline character from the body of the email.
    e.message[strlen(e.message) - 1] = '\0';

    // Print the email to the user.
    print_email(&e);

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EMAIL_LENGTH 512
#define MAX_SUBJECT_LENGTH 256
#define MAX_NAME_LENGTH 64

typedef struct {
    char *name;
    char *email;
    char *subject;
    char *message;
} email_t;

void init_email(email_t *email) {
    email->name = "";
    email->email = "";
    email->subject = "";
    email->message = "";
}

void print_email(email_t *email) {
    printf("From: %s (%s)\n", email->name, email->email);
    printf("Subject: %s\n", email->subject);
    printf("Message:\n%s\n", email->message);
}

void send_email(email_t *email) {
    // Simulate sending an email by printing a success message
    printf("Email sent!\n");
}

int main() {
    email_t email;
    init_email(&email);

    // Funny menu options
    printf("Email Client v1.0\n");
    printf("Choose an option:\n");
    printf("1. Send an email\n");
    printf("2. View your inbox\n");
    printf("3. Reply to an email\n");
    printf("4. Forward an email\n");
    printf("5. Spam your boss\n");
    printf("Enter your choice: ");

    int choice = getchar();

    switch (choice) {
        case '1':
            printf("Enter the recipient's email: ");
            scanf("%s", email.email);
            printf("Enter the subject: ");
            scanf("%s", email.subject);
            printf("Enter the message: ");
            scanf("%s", email.message);
            send_email(&email);
            break;
        case '2':
            printf("Your inbox is empty...\n");
            break;
        case '3':
            printf("Enter the email to reply to: ");
            scanf("%s", email.email);
            printf("Enter your reply: ");
            scanf("%s", email.message);
            send_email(&email);
            break;
        case '4':
            printf("Enter the email to forward: ");
            scanf("%s", email.email);
            printf("Enter the forward message: ");
            scanf("%s", email.message);
            send_email(&email);
            break;
        case '5':
            printf("Don't do that! Your boss is a nice person...\n");
            break;
        default:
            printf("Invalid input. Try again...\n");
            break;
    }

    return 0;
}
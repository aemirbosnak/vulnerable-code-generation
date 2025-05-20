//FormAI DATASET v1.0 Category: Email Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct email {
    char to[50];
    char from[50];
    char subject[100];
    char message[500];
} Email;

int main() {
    Email email;

    printf("Welcome to the unique C Email Client! \n");
    printf("Please enter the recipient's email address: ");
    fgets(email.to, 50, stdin);
    email.to[strcspn(email.to, "\n")] = '\0';

    printf("\nPlease enter your email address: ");
    fgets(email.from, 50, stdin);
    email.from[strcspn(email.from, "\n")] = '\0';

    printf("\nPlease enter the email subject: ");
    fgets(email.subject, 100, stdin);
    email.subject[strcspn(email.subject, "\n")] = '\0';

    printf("\nPlease enter the message (500 characters max): ");
    fgets(email.message, 500, stdin);
    email.message[strcspn(email.message, "\n")] = '\0';

    printf("\n------------------ Email Preview ------------------\n");
    printf("To: %s\n", email.to);
    printf("From: %s\n", email.from);
    printf("Subject: %s\n", email.subject);
    printf("Message: %s\n", email.message);
    printf("\n----------------------------------------------------\n");

    char response;
    printf("Would you like to send this email? (y/n): ");
    scanf(" %c", &response);

    if (tolower(response) == 'y') {
        printf("Email sent successfully to %s!\n", email.to);
    } else {
        printf("Email not sent. Exiting program...\n");
    }

    return 0;
}
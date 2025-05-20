//FormAI DATASET v1.0 Category: Email Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CHAR 50

typedef struct email {
    char recipient[MAX_CHAR];
    char subject[MAX_CHAR];
    char message[MAX_CHAR];
} Email;

int main() {
    Email email;
    char choice[MAX_CHAR];

    // Get recipient's email address
    printf("Enter recipient's email address: ");
    scanf("%s", email.recipient);

    // Get subject of email
    printf("Enter the subject of the email: ");
    scanf("%s", email.subject);

    // Get message for email
    printf("Enter the message for the email: ");
    scanf("%s", email.message);

    // Display entered information
    printf("\nYou have entered the following information:\n");
    printf("Recipient: %s\n", email.recipient);
    printf("Subject: %s\n", email.subject);
    printf("Message: %s\n", email.message);

    // Prompt user to confirm sending of email
    printf("\nWould you like to send this email? (y/n): ");
    scanf("%s", choice);

    // Check user's answer
    if (strcmp(choice, "y") == 0) {
        printf("\nSending email...\n");
        sleep(2);
        printf("Email sent successfully to %s!\n", email.recipient);
    } else {
        printf("\nEmail not sent. Exiting program...\n");
        exit(0);
    }

    return 0;
}
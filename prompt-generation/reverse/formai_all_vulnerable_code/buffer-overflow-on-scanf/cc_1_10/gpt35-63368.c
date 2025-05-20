//FormAI DATASET v1.0 Category: Email Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure to store the email details
typedef struct email {
    char sender[50];
    char recipient[50];
    char subject[100];
    char message[1000];
} Email;

// Define function to send email
void sendEmail(Email e) {
    printf("\nSending email...\n");
    printf("From: %s\nTo: %s\nSubject: %s\nMessage: %s\n", e.sender, e.recipient, e.subject, e.message);
}

int main() {
    // Declare variables to store user input
    char sender[50], recipient[50], subject[100], message[1000];
    
    // Welcome message
    printf("Welcome to MyEmail! \n");

    // Loop to get user input
    while (1) {
        // Get user input for sender
        printf("Enter sender email (max 50 characters): ");
        fflush(stdout);
        scanf("%s", sender);

        // Validate sender email
        if (strlen(sender) > 50) {
            printf("Error: Sender email is too long. Please try again.\n");
            continue;
        }

        // Get user input for recipient
        printf("Enter recipient email (max 50 characters): ");
        fflush(stdout);
        scanf("%s", recipient);

        // Validate recipient email
        if (strlen(recipient) > 50) {
            printf("Error: Recipient email is too long. Please try again.\n");
            continue;
        }

        // Get user input for subject
        printf("Enter email subject (max 100 characters): ");
        fflush(stdout);
        scanf("%s", subject);

        // Validate subject
        if (strlen(subject) > 100) {
            printf("Error: Email subject is too long. Please try again.\n");
            continue;
        }

        // Get user input for message
        printf("Enter email message (max 1000 characters): ");
        fflush(stdout);
        scanf("%s", message);

        // Validate message
        if (strlen(message) > 1000) {
            printf("Error: Email message is too long. Please try again.\n");
            continue;
        }

        // Create email object with user input
        Email e = {sender, recipient, subject, message};

        // Call sendEmail function
        sendEmail(e);

        // Ask user if they want to send another email
        char choice;
        printf("Do you want to send another email? (y/n): ");
        fflush(stdout);
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    // Exit program
    printf("\nThank you for using MyEmail!\n");
    return 0;
}
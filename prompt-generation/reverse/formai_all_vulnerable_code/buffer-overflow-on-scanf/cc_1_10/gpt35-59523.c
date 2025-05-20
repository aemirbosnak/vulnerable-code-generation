//FormAI DATASET v1.0 Category: Email Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Email struct to hold email data
typedef struct {
    char sender[50];
    char recipient[50];
    char subject[50];
    char message[200];
} Email;

// Function to print email information
void printEmail(Email email) {
    printf("\nFrom: %s\nTo: %s\nSubject: %s\nMessage: %s\n", email.sender, email.recipient, email.subject, email.message);
}

// Main function
int main() {
    // Declare variables
    char choice;
    bool isLoggedIn = false;
    Email email;

    // Loop until user quits
    while (1) {
        // Main Menu
        if (!isLoggedIn) {
            printf("\nWelcome to C Email Client!\n1. Log In\n2. Quit\nEnter choice: ");
            scanf(" %c", &choice);

            switch (choice) {
                case '1':
                    printf("\nEnter your email address: ");
                    scanf("%s", email.sender);
                    isLoggedIn = true;
                    break;
                case '2':
                    printf("\nThank you for using C Email Client!\n");
                    return 0;
                default:
                    printf("\nInvalid choice. Please try again.\n");
                    break;
            }
        } else {
            // Email Menu
            printf("\n1. Compose Email\n2. Inbox\n3. Sent\n4. Log Out\nEnter choice: ");
            scanf(" %c", &choice);

            switch (choice) {
                case '1':
                    printf("\nEnter recipient's email address: ");
                    scanf("%s", email.recipient);
                    printf("Enter subject: ");
                    scanf("%s", email.subject);
                    printf("Enter message: ");
                    scanf("%s", email.message);
                    printEmail(email);
                    break;
                case '2':
                    printf("\nInbox functionality will be added soon.\n");
                    break;
                case '3':
                    printf("\nSent functionality will be added soon.\n");
                    break;
                case '4':
                    isLoggedIn = false;
                    memset(&email, 0, sizeof(email));
                    printf("\nYou have been logged out successfully.\n");
                    break;
                default:
                    printf("\nInvalid choice. Please try again.\n");
                    break;
            }
        }
    }

    return 0;
}
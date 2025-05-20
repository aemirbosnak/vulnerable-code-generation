//FormAI DATASET v1.0 Category: Email Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for Email messages
typedef struct Email {
    char sender[50];
    char recipient[50];
    char subject[100];
    char body[1000];
} Email;

// Function to send email
void sendEmail() {
    // Create new Email instance
    Email newEmail;
    printf("Sender Email: ");
    scanf("%s", newEmail.sender);
    printf("Recipient Email: ");
    scanf("%s", newEmail.recipient);
    printf("Subject: ");
    scanf("%s", newEmail.subject);
    printf("Body: ");
    scanf("%s", newEmail.body);

    // Send email code and email sent confirmation message
    printf("\nEmail sent successfully!\n");
}

// Function to receive email
void receiveEmail() {
    // Code to retrieve email messages
    printf("Inbox:\n");
}

int main() {
    // Variable to hold user input
    int userInput;
    // Welcome message
    printf("Welcome to MyEmail!\n");

    // Do while loop for user input and functionality
    do {
        // Options prompt
        printf("\nWhat would you like to do?\n");
        printf("1. Send Email\n");
        printf("2. Receive Email\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &userInput);

        // Switch statement for user input options
        switch(userInput) {
            case 1:
                sendEmail(); // Call sendEmail function
                break;
            case 2:
                receiveEmail(); // Call receiveEmail function
                break;
            case 3:
                printf("\nThank you for using MyEmail!\n");
                break;
            default:
                printf("\nInvalid input!\n"); // Error message if invalid input
                break;
        }
    } while (userInput != 3); // Loop until user enters 3 to quit

    return 0; // End of program
}
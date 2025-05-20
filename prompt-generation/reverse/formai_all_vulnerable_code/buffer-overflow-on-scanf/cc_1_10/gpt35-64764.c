//FormAI DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Post-apocalyptic email client struct
typedef struct {
    char* recipient;
    char* sender;
    char* subject;
    char* message;
} Email;

// Function to send an email
void sendEmail(Email* email) {
    printf("\nSending email...");
    // Code to actually send the email would go here in a real program
    printf("\nEmail sent!");
}

int main() {
    // Create an email to send
    Email* email = malloc(sizeof(Email));
    email->recipient = "survivor1@outpost.com";
    email->sender = "humanity@resurrection.com";
    email->subject = "Information about the new world";
    
    // Prompt the user to enter a message
    char* message = malloc(500 * sizeof(char));
    printf("Enter your message for survivor1@outpost.com:\n");
    scanf("%[^\n]s", message);
    email->message = message;

    // Confirm the email details with the user
    printf("\nConfirm email details:\n");
    printf("Recipient: %s\n", email->recipient);
    printf("Sender: %s\n", email->sender);
    printf("Subject: %s\n", email->subject);
    printf("Message: %s\n", email->message);

    // Prompt the user to send the email or cancel
    printf("\nWould you like to send the email? (Y/N): ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        sendEmail(email);
    } else {
        printf("\nEmail cancelled.");
    }

    // Free dynamically allocated memory
    free(email->message);
    free(email);

    return 0;
}
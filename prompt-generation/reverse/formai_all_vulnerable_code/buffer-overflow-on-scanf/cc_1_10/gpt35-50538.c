//FormAI DATASET v1.0 Category: Email Client ; Style: futuristic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Structure to store email details
struct Email {
    char* sender;
    char* receiver;
    char* subject;
    char* body;
};

// Function to send email
void sendEmail(struct Email email) {
    printf("Email sent from %s to %s with subject '%s'\n", email.sender, email.receiver, email.subject);
}

// Function to display user's inbox
void displayInbox(char* username) {
    printf("\nWelcome to your inbox, %s!\n", username);
    printf("You have no new emails.\n");
}

int main() { 
    char username[20];
    printf("Welcome to the futuristic email client! Please enter your username: ");
    scanf("%s", username);

    int choice = 0;
    while (choice != 3) {
        printf("\nWhat would you like to do, %s? Choose an option:\n", username);
        printf("1. Compose an email\n");
        printf("2. Check your inbox\n");
        printf("3. Exit\n");

        // Get user's choice
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        // Compose email
        if (choice == 1) {
            struct Email email;
            // Get email details from user
            email.sender = (char*) malloc(20 * sizeof(char));
            email.receiver = (char*) malloc(20 * sizeof(char));
            email.subject = (char*) malloc(50 * sizeof(char));
            email.body = (char*) malloc(500 * sizeof(char));
            printf("\nCompose an email:\n");
            printf("From: ");
            scanf("%s", email.sender);
            printf("To: ");
            scanf("%s", email.receiver);
            printf("Subject: ");
            scanf(" %[^\n]s", email.subject);
            printf("Body: ");
            scanf(" %[^\n]s", email.body);
            sendEmail(email);
            free(email.sender);
            free(email.receiver);
            free(email.subject);
            free(email.body);
        } 
        // Check inbox
        else if (choice == 2) {
            displayInbox(username);
        }
        // Exit
        else if (choice == 3) {
            printf("Thank you for using the futuristic email client!\n");
        }
        // Invalid choice
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0; 
}
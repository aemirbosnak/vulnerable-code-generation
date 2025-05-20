//FormAI DATASET v1.0 Category: Email Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Structure for email message
typedef struct {
    char subject[MAX_SIZE];
    char sender[MAX_SIZE];
    char recipient[MAX_SIZE];
    char message[MAX_SIZE];
} Email;

// Function to prompt user for email input
void inputEmail(Email *email) {
    printf("\nEnter the subject line: ");
    fgets(email->subject, MAX_SIZE, stdin);
    printf("Enter your email address: ");
    fgets(email->sender, MAX_SIZE, stdin);
    printf("Enter the recipient's email address: ");
    fgets(email->recipient, MAX_SIZE, stdin);
    printf("Enter the message: ");
    fgets(email->message, MAX_SIZE, stdin);
}

// Function to send email
void sendEmail(Email *email) {
    printf("\n---Sending email---\n");
    printf("To: %s\n", email->recipient);
    printf("From: %s\n", email->sender);
    printf("Subject: %s", email->subject);
    printf("Message: %s", email->message);
    printf("---Email sent---\n");
}

// Function to receive email
void receiveEmail(Email *email) {
    printf("\n---Receiving email---\n");
    printf("From: %s\n", email->sender);
    printf("Subject: %s", email->subject);
    printf("Message: %s", email->message);
    printf("---Email received---\n");
}

int main() {
    Email email;
    int choice;

    do {
        printf("\nEmail Client Menu\n");
        printf("-----------------\n");
        printf("1. Compose email\n");
        printf("2. Send email\n");
        printf("3. Receive email\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch(choice) {
            case 1:
                inputEmail(&email);
                break;
            case 2:
                sendEmail(&email);
                break;
            case 3:
                receiveEmail(&email);
                break;
            case 4:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nInvalid choice. Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}
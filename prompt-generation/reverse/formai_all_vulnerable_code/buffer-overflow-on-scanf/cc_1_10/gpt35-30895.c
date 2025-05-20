//FormAI DATASET v1.0 Category: Email Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_EMAILS 100
#define MAX_EMAIL_SIZE 1024

// Define email struct
typedef struct {
    char sender[256];
    char receiver[256];
    char subject[256];
    char message[MAX_EMAIL_SIZE];
} Email;

// Define global variables
Email emails[MAX_EMAILS];
int numEmails = 0;

// Declare functions
void displayMenu();
void displayEmails();
void addEmail();
void removeEmail();

int main() {
    // Initialize variables
    int choice;

    // Display menu
    do {
        displayMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1:
                displayEmails();
                break;
            case 2:
                addEmail();
                break;
            case 3:
                removeEmail();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n");
    printf("------ C EMAIL CLIENT ------\n");
    printf("1. View emails\n");
    printf("2. Compose email\n");
    printf("3. Remove email\n");
    printf("4. Quit\n");
}

void displayEmails() {
    // Check if there are any emails to display
    if (numEmails == 0) {
        printf("No emails to display.\n");
        return;
    }

    // Iterate through emails and display them
    printf("\n");
    printf("------ VIEW EMAILS ------\n");
    for (int i = 0; i < numEmails; i++) {
        printf("Email %d:\n", i+1);
        printf("  Sender: %s\n", emails[i].sender);
        printf("  Receiver: %s\n", emails[i].receiver);
        printf("  Subject: %s\n", emails[i].subject);
        printf("  Message: %s\n", emails[i].message);
        printf("\n");
    }
}

void addEmail() {
    // Check if there is space to add an email
    if (numEmails == MAX_EMAILS) {
        printf("Maximum number of emails reached.\n");
        return;
    }

    // Get user input for new email
    char sender[256];
    char receiver[256];
    char subject[256];
    char message[MAX_EMAIL_SIZE];

    printf("\n");
    printf("------ COMPOSE EMAIL ------\n");
    printf("Enter sender email address: ");
    scanf("%s", sender);
    printf("Enter receiver email address: ");
    scanf("%s", receiver);
    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter message: ");
    scanf("%s", message);

    // Add new email to list
    strcpy(emails[numEmails].sender, sender);
    strcpy(emails[numEmails].receiver, receiver);
    strcpy(emails[numEmails].subject, subject);
    strcpy(emails[numEmails].message, message);

    printf("Email sent successfully.\n");
    numEmails++;
}

void removeEmail() {
    // Check if there are any emails to remove
    if (numEmails == 0) {
        printf("No emails to remove.\n");
        return;
    }

    // Get user input for email index to remove
    int emailIndex;

    printf("\n");
    printf("------ REMOVE EMAIL ------\n");
    printf("Enter index of email to remove: ");
    scanf("%d", &emailIndex);

    // Check if email index is valid
    if (emailIndex < 1 || emailIndex > numEmails) {
        printf("Invalid email index. Please try again.\n");
        return;
    }

    // Remove email from list
    for (int i = emailIndex - 1; i < numEmails - 1; i++) {
        emails[i] = emails[i+1];
    }

    printf("Email removed successfully.\n");
    numEmails--;
}
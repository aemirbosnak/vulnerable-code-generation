//FormAI DATASET v1.0 Category: Email Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct Email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Email;

Email inbox[MAX_EMAILS];
int numEmails = 0;

// Function to add an email to the inbox
void addEmail(Email newEmail) {
    if (numEmails < MAX_EMAILS) {
        inbox[numEmails++] = newEmail;
        printf("Email added to inbox.\n");
    } else {
        printf("Inbox is full. Cannot add email.\n");
    }
}

// Function to display all emails in the inbox
void displayEmails() {
    if (numEmails == 0) {
        printf("Inbox is empty.\n");
    } else {
        printf("List of Emails:\n");
        printf("%-20s %-20s %-30s\n", "Sender", "Recipient", "Subject");
        for (int i = 0; i < numEmails; i++) {
            printf("%-20s %-20s %-30s\n", inbox[i].sender, inbox[i].recipient, inbox[i].subject);
        }
    }
}

// Main function to run the email client
int main() {
    int choice;
    Email newEmail;

    do {
        // Display menu options
        printf("\nEmail Client Menu\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Compose Email
                printf("\nCompose Email\n");
                printf("Enter sender: ");
                scanf("%s", newEmail.sender);
                printf("Enter recipient: ");
                scanf("%s", newEmail.recipient);
                printf("Enter subject: ");
                scanf("%s", newEmail.subject);
                printf("Enter message: ");
                getchar(); // clear buffer
                fgets(newEmail.message, MAX_MESSAGE_LENGTH, stdin);
                addEmail(newEmail);
                break;
            case 2:
                // Display Inbox
                printf("\nInbox\n");
                displayEmails();
                break;
            case 3:
                // Exit program
                printf("\nExiting Email Client. Have a nice day!\n");
                break;
            default:
                // Invalid choice
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
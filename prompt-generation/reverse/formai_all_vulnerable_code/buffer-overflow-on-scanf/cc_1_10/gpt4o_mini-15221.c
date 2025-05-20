//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function prototypes
void displayMenu();
void composeEmail();
void viewInbox();
void deleteEmail(int index);
void listEmails();
void readEmail(int index);
void addRandomEmail();
void cleanInbox();

// Email struct to hold email data
typedef struct Email {
    int id;
    char sender[50];
    char subject[100];
    char body[500];
} Email;

#define MAX_EMAILS 100
Email inbox[MAX_EMAILS];
int emailCount = 0;

// Main function
int main() {
    int choice;

    // Sample data for demonstration purposes
    addRandomEmail();
    addRandomEmail();
    addRandomEmail();

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to capture the newline

        switch (choice) {
            case 1:
                composeEmail();
                break;
            case 2:
                viewInbox();
                break;
            case 3:
                cleanInbox();
                break;
            case 4:
                printf("Exiting email client.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Display the menu
void displayMenu() {
    printf("\n=== Email Client Menu ===\n");
    printf("1. Compose Email\n");
    printf("2. View Inbox\n");
    printf("3. Clean Inbox\n");
    printf("4. Exit\n");
}

// Compose a new email
void composeEmail() {
    if (emailCount >= MAX_EMAILS) {
        printf("Inbox is full. Cannot compose new email.\n");
        return;
    }

    Email newEmail;
    newEmail.id = emailCount + 1;

    printf("Enter sender: ");
    fgets(newEmail.sender, sizeof(newEmail.sender), stdin);
    newEmail.sender[strcspn(newEmail.sender, "\n")] = 0; // Remove newline

    printf("Enter subject: ");
    fgets(newEmail.subject, sizeof(newEmail.subject), stdin);
    newEmail.subject[strcspn(newEmail.subject, "\n")] = 0;

    printf("Enter body: ");
    fgets(newEmail.body, sizeof(newEmail.body), stdin);
    newEmail.body[strcspn(newEmail.body, "\n")] = 0;

    inbox[emailCount++] = newEmail;
    printf("Email composed successfully.\n");
}

// View the inbox
void viewInbox() {
    if (emailCount == 0) {
        printf("Inbox is empty.\n");
        return;
    }

    listEmails();
    int readIndex;

    printf("Enter the email number to read (0 to go back): ");
    scanf("%d", &readIndex);
    if (readIndex > 0 && readIndex <= emailCount) {
        readEmail(readIndex - 1);
    }
}

// List all emails in the inbox
void listEmails() {
    printf("\n--- Inbox Emails ---\n");
    for (int i = 0; i < emailCount; ++i) {
        printf("%d. From: %s | Subject: %s\n", 
               inbox[i].id, inbox[i].sender, inbox[i].subject);
    }
}

// Read a specific email
void readEmail(int index) {
    printf("\n--- Reading Email ---\n");
    printf("From: %s\n", inbox[index].sender);
    printf("Subject: %s\n", inbox[index].subject);
    printf("Body:\n%s\n", inbox[index].body);
}

// Add sample emails for demonstration
void addRandomEmail() {
    if (emailCount >= MAX_EMAILS) return;

    Email sample;
    sample.id = emailCount + 1;
    snprintf(sample.sender, sizeof(sample.sender), "sender%d@example.com", emailCount);
    snprintf(sample.subject, sizeof(sample.subject), "Subject %d", emailCount);
    snprintf(sample.body, sizeof(sample.body), "This is the body of email %d.", emailCount);

    inbox[emailCount++] = sample;
}

// Clean the inbox
void cleanInbox() {
    emailCount = 0;
    printf("Inbox cleaned successfully.\n");
}
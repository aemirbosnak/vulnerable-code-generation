//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_MESSAGE_LENGTH 256
#define MAX_EMAIL_LENGTH 30

typedef struct {
    char sender[MAX_EMAIL_LENGTH];
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Email;

Email inbox[MAX_EMAILS];
int emailCount = 0;

void sendEmail();
void viewEmails();
void mainMenu();
void clearBuffer();

void mainMenu() {
    int choice;
    printf("\n--- Email Client Menu ---\n");
    printf("1. Send Email\n");
    printf("2. View Emails\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
    clearBuffer();
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            sendEmail();
            break;
        case 2:
            viewEmails();
            break;
        case 3:
            printf("Exiting the Email Client. Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            mainMenu();
    }
}

void sendEmail() {
    if (emailCount >= MAX_EMAILS) {
        printf("Email inbox is full! Cannot send more emails.\n");
        mainMenu();
        return;
    }

    Email newEmail;

    printf("Enter sender email: ");
    clearBuffer();
    fgets(newEmail.sender, MAX_EMAIL_LENGTH, stdin);
    strtok(newEmail.sender, "\n"); // Remove newline character
    
    printf("Enter recipient email: ");
    fgets(newEmail.recipient, MAX_EMAIL_LENGTH, stdin);
    strtok(newEmail.recipient, "\n");

    printf("Enter subject: ");
    fgets(newEmail.subject, MAX_SUBJECT_LENGTH, stdin);
    strtok(newEmail.subject, "\n");

    printf("Enter message: ");
    fgets(newEmail.message, MAX_MESSAGE_LENGTH, stdin);
    strtok(newEmail.message, "\n");

    inbox[emailCount++] = newEmail;
    printf("Email sent successfully!\n");
    mainMenu();
}

void viewEmails() {
    if (emailCount == 0) {
        printf("No emails in the inbox.\n");
        mainMenu();
        return;
    }

    printf("\n--- Inbox ---\n");
    for (int i = 0; i < emailCount; i++) {
        printf("Email %d:\n", i + 1);
        printf("Sender: %s\n", inbox[i].sender);
        printf("Recipient: %s\n", inbox[i].recipient);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Message: %s\n", inbox[i].message);
        printf("\n");
    }
    
    printf("--- End of Inbox ---\n");
    mainMenu();
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}

int main() {
    printf("Welcome to the Email Client!\n");
    mainMenu();
    return 0;
}
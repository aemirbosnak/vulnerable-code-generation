//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 256

typedef struct {
    char sender[EMAIL_LENGTH];
    char recipient[EMAIL_LENGTH];
    char subject[EMAIL_LENGTH];
    char body[EMAIL_LENGTH * 2];
} Email;

Email inbox[MAX_EMAILS];
int inbox_count = 0;

// Function Prototypes
void displayMenu();
void sendEmail();
void receiveEmail();
void listInbox();
void viewEmail(int index);
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear any extra newline from input buffer
        
        switch (choice) {
            case 1:
                sendEmail();
                break;
            case 2:
                receiveEmail();
                break;
            case 3:
                listInbox();
                break;
            case 4:
                printf("Exiting the email client. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=== Simple Email Client ===\n");
    printf("1. Send Email\n");
    printf("2. Receive Email\n");
    printf("3. List Inbox\n");
    printf("4. Exit\n");
}

void sendEmail() {
    Email email;
    printf("Sending email...\n");
    
    printf("Enter recipient email address: ");
    fgets(email.recipient, EMAIL_LENGTH, stdin);
    email.recipient[strcspn(email.recipient, "\n")] = 0; // Remove newline
    
    printf("Enter your email address: ");
    fgets(email.sender, EMAIL_LENGTH, stdin);
    email.sender[strcspn(email.sender, "\n")] = 0; // Remove newline
    
    printf("Enter email subject: ");
    fgets(email.subject, EMAIL_LENGTH, stdin);
    email.subject[strcspn(email.subject, "\n")] = 0; // Remove newline
    
    printf("Enter email body: ");
    fgets(email.body, sizeof(email.body), stdin);
    email.body[strcspn(email.body, "\n")] = 0; // Remove newline

    // For demonstration, we are just adding it to the inbox
    if (inbox_count < MAX_EMAILS) {
        inbox[inbox_count++] = email;
        printf("Email sent to %s.\n", email.recipient);
    } else {
        printf("Inbox is full! Cannot send more emails.\n");
    }
}

void receiveEmail() {
    printf("Receiving email...\n");
    // In real scenario, here we would fetch emails from a server.

    // Simulating a received email for demonstration
    Email demoEmail = {
        .sender = "example@domain.com",
        .recipient = "user@domain.com",
        .subject = "Welcome!",
        .body = "Thank you for joining our service."
    };

    if (inbox_count < MAX_EMAILS) {
        inbox[inbox_count++] = demoEmail;
        printf("Email received from %s.\n", demoEmail.sender);
    } else {
        printf("Inbox is full! Cannot receive more emails.\n");
    }
}

void listInbox() {
    printf("=== Inbox ===\n");
    if (inbox_count == 0) {
        printf("No emails in inbox.\n");
        return;
    }
    for (int i = 0; i < inbox_count; i++) {
        printf("%d: %s - %s\n", i + 1, inbox[i].sender, inbox[i].subject);
    }
}

void viewEmail(int index) {
    if (index < 0 || index >= inbox_count) {
        printf("Invalid email index.\n");
        return;
    }
    
    Email email = inbox[index];
    printf("From: %s\n", email.sender);
    printf("To: %s\n", email.recipient);
    printf("Subject: %s\n", email.subject);
    printf("Body: %s\n", email.body);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
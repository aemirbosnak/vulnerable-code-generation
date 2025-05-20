//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold an email
typedef struct Email {
    int id;
    char sender[50];
    char recipient[50];
    char subject[100];
    char body[500];
    time_t timestamp;
} Email;

#define MAX_EMAILS 100

// Email storage
Email inbox[MAX_EMAILS];
int email_count = 0;

// Function to send an email
void send_email() {
    if (email_count >= MAX_EMAILS) {
        printf("The inbox is full, cannot send more emails.\n");
        return;
    }

    Email new_email;

    printf("Enter sender address: ");
    scanf(" %49[^\n]", new_email.sender);
    
    printf("Enter recipient address: ");
    scanf(" %49[^\n]", new_email.recipient);
    
    printf("Enter email subject: ");
    scanf(" %99[^\n]", new_email.subject);
    
    printf("Enter email body: ");
    getchar(); // Clear newline from buffer
    scanf(" %499[^\n]", new_email.body);
    
    new_email.id = email_count + 1;
    new_email.timestamp = time(NULL);
    
    inbox[email_count++] = new_email;
    
    printf("Email sent!\n");
}

// Function to display received emails
void receive_email() {
    if (email_count == 0) {
        printf("No new messages.\n");
        return;
    }

    printf("\n=== Inbox ===\n");
    for (int i = 0; i < email_count; i++) {
        Email *email = &inbox[i];
        printf("Email ID: %d\n", email->id);
        printf("From: %s\n", email->sender);
        printf("To: %s\n", email->recipient);
        printf("Subject: %s\n", email->subject);
        printf("Body: %s\n", email->body);
        printf("Received: %s", ctime(&email->timestamp));
        printf("-------------------------\n");
    }
}

// Function to delete an email
void delete_email() {
    int id;
    printf("Enter the Email ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > email_count) {
        printf("Invalid Email ID.\n");
        return;
    }
    
    for (int i = id - 1; i < email_count - 1; i++) {
        inbox[i] = inbox[i + 1];
    }
    email_count--;
    printf("Email ID %d deleted.\n", id);
}

// Main function
int main() {
    int choice;
    printf("Welcome to the Post-Apocalyptic Email Client.\n");
    printf("Not much left in the world, but you still have emails!\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Send Email\n");
        printf("2. Receive Email\n");
        printf("3. Delete Email\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                send_email();
                break;
            case 2:
                receive_email();
                break;
            case 3:
                delete_email();
                break;
            case 4:
                printf("Shutting down the email client.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500
#define MAX_SENDER_LENGTH 50
#define MAX_RECEIVER_LENGTH 50

typedef struct Email {
    char sender[MAX_SENDER_LENGTH];
    char receiver[MAX_RECEIVER_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email inbox[MAX_EMAILS];
int inbox_count = 0;

void send_email() {
    if (inbox_count >= MAX_EMAILS) {
        printf("Inbox is full. Cannot send more emails.\n");
        return;
    }
    
    Email email;
    printf("Enter sender's email: ");
    scanf(" %[^\n]", email.sender);
    printf("Enter receiver's email: ");
    scanf(" %[^\n]", email.receiver);
    printf("Enter subject: ");
    scanf(" %[^\n]", email.subject);
    printf("Enter body: ");
    scanf(" %[^\n]", email.body);
    
    inbox[inbox_count++] = email;
    printf("Email sent successfully!\n\n");
}

void read_emails() {
    if (inbox_count == 0) {
        printf("No emails in inbox.\n");
        return;
    }
    
    for (int i = 0; i < inbox_count; i++) {
        Email email = inbox[i];
        printf("Email %d:\n", i + 1);
        printf("From: %s\n", email.sender);
        printf("To: %s\n", email.receiver);
        printf("Subject: %s\n", email.subject);
        printf("Body:\n%s\n", email.body);
        printf("--------------------------------------------------\n");
    }
}

void display_menu() {
    printf("Email Client Menu:\n");
    printf("1. Send Email\n");
    printf("2. Read Emails\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                send_email();
                break;
            case 2:
                read_emails();
                break;
            case 3:
                printf("Exiting the email client. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
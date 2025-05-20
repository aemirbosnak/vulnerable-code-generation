//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500

typedef struct {
    char sender[50];
    char recipient[50];
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
    
    Email new_email;
    
    printf("Enter sender's email: ");
    scanf("%s", new_email.sender);
    
    printf("Enter recipient's email: ");
    scanf("%s", new_email.recipient);
    
    printf("Enter subject: ");
    getchar();  // Clear newline from the buffer
    fgets(new_email.subject, MAX_SUBJECT_LENGTH, stdin);
    new_email.subject[strcspn(new_email.subject, "\n")] = 0;  // Remove newline

    printf("Enter body (max 500 characters): ");
    fgets(new_email.body, MAX_BODY_LENGTH, stdin);
    new_email.body[strcspn(new_email.body, "\n")] = 0;  // Remove newline

    inbox[inbox_count++] = new_email;

    printf("Email sent successfully!\n");
}

void read_emails() {
    if (inbox_count == 0) {
        printf("No emails in the inbox.\n");
        return;
    }

    for (int i = 0; i < inbox_count; i++) {
        printf("Email %d:\n", i + 1);
        printf("From: %s\n", inbox[i].sender);
        printf("To: %s\n", inbox[i].recipient);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Body: %s\n", inbox[i].body);
        printf("------------------------------\n");
    }
}

void display_menu() {
    printf("Welcome to the Simple Email Client\n");
    printf("1. Send Email\n");
    printf("2. Read Emails\n");
    printf("3. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                send_email();
                break;
            case 2:
                read_emails();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
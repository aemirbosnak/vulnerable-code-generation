//FormAI DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_HEADER_SIZE 100
#define MAX_BUFFER_SIZE 100000  
#define MAX_EMAILS 100
#define MAX_EMAIL_SUBJECT_SIZE 100
#define MAX_EMAIL_BODY_SIZE 1000
#define MAX_EMAIL_SENDER_SIZE 50
#define MAX_EMAIL_RECIPIENT_SIZE 50

typedef struct email {
    char subject[MAX_EMAIL_SUBJECT_SIZE];
    char body[MAX_EMAIL_BODY_SIZE];
    char sender[MAX_EMAIL_SENDER_SIZE];
    char recipient[MAX_EMAIL_RECIPIENT_SIZE];
} Email;

typedef struct mailbox {
    Email emails[MAX_EMAILS];
    int num_emails;
} Mailbox;

void display_email(Email e) {
    printf("Subject: %s\n", e.subject);
    printf("From: %s\n", e.sender);
    printf("To: %s\n", e.recipient);
    printf("Body: %s\n\n", e.body);
}

void display_mailbox(Mailbox mb) {
    printf("Number of emails: %d\n", mb.num_emails);
    for (int i = 0; i < mb.num_emails; i++) {
        printf("Email %d:\n", i+1);
        display_email(mb.emails[i]);
    }
}

void send_email(Mailbox *mb) {
    char subject[MAX_EMAIL_SUBJECT_SIZE];
    char body[MAX_EMAIL_BODY_SIZE];
    char sender[MAX_EMAIL_SENDER_SIZE];
    char recipient[MAX_EMAIL_RECIPIENT_SIZE];

    // Get input from user
    printf("Enter sender name: ");
    scanf("%s", sender);
    printf("Enter recipient name: ");
    scanf("%s", recipient);
    printf("Enter email subject: ");
    scanf("%s", subject);
    printf("Enter email body: ");
    scanf("%s", body);
    printf("\n");

    // Create email and add to mailbox
    Email e;
    strcpy(e.sender, sender);
    strcpy(e.recipient, recipient);
    strcpy(e.subject, subject);
    strcpy(e.body, body);
    mb->emails[mb->num_emails] = e;
    mb->num_emails++;
}

int main() {
    Mailbox my_mailbox;
    my_mailbox.num_emails = 0;

    // Menu loop
    while (1) {
        int choice;

        // Display menu options
        printf("1. Display mailbox\n");
        printf("2. Send email\n");
        printf("3. Quit\n\n");

        // Get user choice
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Process user choice
        switch (choice) {
            case 1:
                printf("\n");
                display_mailbox(my_mailbox);
                break;
            case 2:
                printf("\n");
                send_email(&my_mailbox);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
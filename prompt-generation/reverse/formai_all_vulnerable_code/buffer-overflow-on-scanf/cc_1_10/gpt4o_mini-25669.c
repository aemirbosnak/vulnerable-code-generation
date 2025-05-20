//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

typedef struct {
    Email emails[MAX_EMAILS];
    int email_count;
} Mailbox;

void init_mailbox(Mailbox *mb) {
    mb->email_count = 0;
}

void send_email(Mailbox *mb) {
    if (mb->email_count >= MAX_EMAILS) {
        printf("Mailbox is full, cannot send more emails.\n");
        return;
    }

    Email new_email;
    printf("Enter sender's email: ");
    scanf("%s", new_email.from);
    printf("Enter recipient's email: ");
    scanf("%s", new_email.to);
    printf("Enter subject: ");
    scanf(" %[^\n]s", new_email.subject);
    printf("Enter email body: ");
    scanf(" %[^\n]s", new_email.body);
    
    mb->emails[mb->email_count] = new_email;
    mb->email_count++;
    printf("Email sent successfully!\n");
}

void receive_email(Mailbox *mb) {
    if (mb->email_count == 0) {
        printf("No new emails in the mailbox.\n");
        return;
    }
    printf("You have %d new emails:\n", mb->email_count);
    for (int i = 0; i < mb->email_count; i++) {
        printf("Email %d\n", i + 1);
        printf("From: %s\n", mb->emails[i].from);
        printf("To: %s\n", mb->emails[i].to);
        printf("Subject: %s\n", mb->emails[i].subject);
        printf("Body: %s\n", mb->emails[i].body);
        printf("--------------------------------------------------\n");
    }
}

void display_menu() {
    printf("Email Client Menu:\n");
    printf("1. Send Email\n");
    printf("2. Receive Emails\n");
    printf("3. Exit\n");
}

int main() {
    Mailbox mailbox;
    init_mailbox(&mailbox);
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                send_email(&mailbox);
                break;
            case 2:
                receive_email(&mailbox);
                break;
            case 3:
                printf("Exiting the email client. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
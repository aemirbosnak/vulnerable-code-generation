//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT 100
#define MAX_BODY 512
#define MAX_SENDER 50
#define MAX_RECEIVER 50

typedef struct {
    char sender[MAX_SENDER];
    char receiver[MAX_RECEIVER];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
} Email;

Email inbox[MAX_EMAILS];
int inbox_count = 0;

void compose_email() {
    if (inbox_count >= MAX_EMAILS) {
        printf("Inbox is full! Cannot compose new email.\n");
        return;
    }

    Email new_email;

    printf("Enter sender email: ");
    scanf("%s", new_email.sender);
    printf("Enter receiver email: ");
    scanf("%s", new_email.receiver);
    printf("Enter subject: ");
    scanf(" %[^\n]", new_email.subject);
    printf("Enter email body: ");
    scanf(" %[^\n]", new_email.body);

    inbox[inbox_count++] = new_email;
    printf("Email composed successfully!\n");
}

void view_inbox() {
    if (inbox_count == 0) {
        printf("Inbox is empty.\n");
        return;
    }

    for (int i = 0; i < inbox_count; i++) {
        printf("Email %d:\n", i + 1);
        printf("From: %s\n", inbox[i].sender);
        printf("To: %s\n", inbox[i].receiver);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Body: %s\n", inbox[i].body);
        printf("----------------------------\n");
    }
}

void send_email() {
    if (inbox_count == 0) {
        printf("No emails to send.\n");
        return;
    }

    char choice;
    printf("Choose an email to send (1 to %d): ", inbox_count);
    scanf(" %c", &choice);

    int email_index = choice - '1'; // '1' to 'n' -> 0 to n-1
    if (email_index < 0 || email_index >= inbox_count) {
        printf("Invalid choice!\n");
        return;
    }

    printf("Sending email...\n");
    printf("Email sent to: %s\n", inbox[email_index].receiver);
    printf("Email subject: %s\n", inbox[email_index].subject);
    // After sending, we can consider removing email from inbox or marking as sent
    for (int i = email_index; i < inbox_count - 1; i++) {
        inbox[i] = inbox[i + 1];
    }
    inbox_count--;
    printf("Email removed from inbox after sending!\n");
}

void display_menu() {
    printf("\nWelcome to the Shape-Shifting Email Client!\n");
    printf("1. Compose Email\n");
    printf("2. View Inbox\n");
    printf("3. Send Email\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while(1) {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                compose_email();
                break;
            case 2:
                view_inbox();
                break;
            case 3:
                send_email();
                break;
            case 4:
                printf("Exiting the email client. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}
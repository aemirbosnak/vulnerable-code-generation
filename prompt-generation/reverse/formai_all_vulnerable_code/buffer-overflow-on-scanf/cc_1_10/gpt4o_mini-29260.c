//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT 100
#define MAX_CONTENT 500
#define EMAIL_ADDRESS 50

typedef struct {
    char from[EMAIL_ADDRESS];
    char to[EMAIL_ADDRESS];
    char subject[MAX_SUBJECT];
    char content[MAX_CONTENT];
} Email;

Email inbox[MAX_EMAILS];
int email_count = 0;

void send_email(const char *from, const char *to, const char *subject, const char *content) {
    if (email_count >= MAX_EMAILS) {
        printf("Inbox is full! Cannot send more emails.\n");
        return;
    }

    strcpy(inbox[email_count].from, from);
    strcpy(inbox[email_count].to, to);
    strcpy(inbox[email_count].subject, subject);
    strcpy(inbox[email_count].content, content);
    email_count++;
    printf("Email sent from %s to %s\n", from, to);
}

void view_inbox() {
    if (email_count == 0) {
        printf("Your inbox is empty!\n");
        return;
    }

    for (int i = 0; i < email_count; i++) {
        printf("Email %d:\n", i + 1);
        printf("From: %s\n", inbox[i].from);
        printf("To: %s\n", inbox[i].to);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Content:\n%s\n", inbox[i].content);
        printf("----------------------------\n");
    }
}

void display_menu() {
    printf("=== Simple C Email Client ===\n");
    printf("1. Send Email\n");
    printf("2. View Inbox\n");
    printf("3. Exit\n");
    printf("=============================\n");
}

int main() {
    int choice;
    char from[EMAIL_ADDRESS], to[EMAIL_ADDRESS], subject[MAX_SUBJECT], content[MAX_CONTENT];

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter your email address: ");
                fgets(from, EMAIL_ADDRESS, stdin);
                from[strcspn(from, "\n")] = 0; // Remove newline
                printf("Enter recipient's email address: ");
                fgets(to, EMAIL_ADDRESS, stdin);
                to[strcspn(to, "\n")] = 0; // Remove newline
                printf("Enter subject: ");
                fgets(subject, MAX_SUBJECT, stdin);
                subject[strcspn(subject, "\n")] = 0; // Remove newline
                printf("Enter content: ");
                fgets(content, MAX_CONTENT, stdin);
                content[strcspn(content, "\n")] = 0; // Remove newline
                
                send_email(from, to, subject, content);
                break;
            case 2:
                view_inbox();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
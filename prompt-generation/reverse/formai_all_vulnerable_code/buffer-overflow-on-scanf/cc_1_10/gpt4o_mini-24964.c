//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_EMAILS 100
#define EMAIL_SIZE 256
#define SUBJECT_SIZE 100
#define BODY_SIZE 512

typedef struct {
    char sender[EMAIL_SIZE];
    char recipient[EMAIL_SIZE];
    char subject[SUBJECT_SIZE];
    char body[BODY_SIZE];
} Email;

Email inbox[MAX_EMAILS];
int email_count = 0;

void clear_buffer() {
    while (getchar() != '\n');
}

void send_email() {
    if (email_count >= MAX_EMAILS) {
        printf("Inbox is full! Cannot send more emails.\n");
        return;
    }

    Email email;
    printf("Enter recipient's email: ");
    fgets(email.recipient, EMAIL_SIZE, stdin);
    email.recipient[strcspn(email.recipient, "\n")] = 0; // Remove newline

    printf("Enter your email: ");
    fgets(email.sender, EMAIL_SIZE, stdin);
    email.sender[strcspn(email.sender, "\n")] = 0; // Remove newline

    printf("Enter subject: ");
    fgets(email.subject, SUBJECT_SIZE, stdin);
    email.subject[strcspn(email.subject, "\n")] = 0; // Remove newline

    printf("Enter body (Enter 'END' on a new line to finish):\n");
    char line[BODY_SIZE];
    email.body[0] = '\0'; // Initialize body to empty string
    while (1) {
        fgets(line, BODY_SIZE, stdin);
        if (strcmp(line, "END\n") == 0) {
            break;
        }
        strcat(email.body, line);
    }

    inbox[email_count++] = email; // Save email to inbox
    printf("Email sent to %s!\n", email.recipient);
}

void view_inbox() {
    if (email_count == 0) {
        printf("Your inbox is empty!\n");
        return;
    }

    for (int i = 0; i < email_count; i++) {
        printf("Email %d:\n", i + 1);
        printf("From: %s\n", inbox[i].sender);
        printf("To: %s\n", inbox[i].recipient);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Body:\n%s\n", inbox[i].body);
        printf("---------------------------------\n");
    }
}

void display_menu() {
    printf("\n=== Simple Email Client ===\n");
    printf("1. Send an Email\n");
    printf("2. View Inbox\n");
    printf("3. Exit\n");
    printf("===========================\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_buffer(); // Clear new line from input buffer

        switch (choice) {
            case 1:
                send_email();
                break;
            case 2:
                view_inbox();
                break;
            case 3:
                printf("Exiting the Email Client. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
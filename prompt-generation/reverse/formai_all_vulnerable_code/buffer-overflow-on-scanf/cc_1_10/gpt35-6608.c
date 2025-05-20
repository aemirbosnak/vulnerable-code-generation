//FormAI DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_MESSAGE_LENGTH 500

struct Email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
};

struct Email inbox[MAX_EMAILS];
int email_count = 0;

void view_inbox() {
    printf("INBOX:\n");
    for (int i = 0; i < email_count; i++) {
        printf("From: %s\n", inbox[i].sender);
        printf("To: %s\n", inbox[i].recipient);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Message: %s\n", inbox[i].message);
        printf("\n");
    }
}

void send_email() {
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    printf("Recipient: ");
    scanf("%s", recipient);
    printf("Subject: ");
    scanf("%s", subject);
    printf("Message: ");
    getchar();
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    strcpy(inbox[email_count].recipient, recipient);
    strcpy(inbox[email_count].subject, subject);
    strcpy(inbox[email_count].message, message);
    email_count++;
    printf("Email sent!\n");
}

int main() {
    int choice;
    do {
        printf("1. View Inbox\n");
        printf("2. Send Email\n");
        printf("3. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                view_inbox();
                break;
            case 2:
                send_email();
                break;
            case 3:
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}
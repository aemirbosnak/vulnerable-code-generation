//FormAI DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LEN 50
#define MAX_BODY_LEN 200

struct email {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    char sender[MAX_SUBJECT_LEN];
};

struct email inbox[MAX_EMAILS];
int inbox_size = 0;

struct email sent[MAX_EMAILS];
int sent_size = 0;

void display_menu() {
    printf("\n\nWelcome to Shape Shifting Email Client!\n");
    printf("1. View Inbox\n");
    printf("2. View Sent Emails\n");
    printf("3. Compose Email\n");
    printf("4. Exit\n");
}

void view_inbox() {
    printf("\n\n--- INBOX ---\n");
    if (inbox_size == 0) {
        printf("You have no emails in your inbox.\n");
        return;
    }
    for (int i = 0; i < inbox_size; i++) {
        printf("Email %d:\n", i+1);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Body: %s\n", inbox[i].body);
        printf("From: %s\n", inbox[i].sender);
    }
}

void view_sent() {
    printf("\n\n--- SENT EMAILS ---\n");
    if (sent_size == 0) {
        printf("You have not sent any emails.\n");
        return;
    }
    for (int i = 0; i < sent_size; i++) {
        printf("Email %d:\n", i+1);
        printf("Subject: %s\n", sent[i].subject);
        printf("Body: %s\n", sent[i].body);
        printf("To: %s\n", sent[i].sender);
    }
}

void compose_email() {
    struct email new_email;
    printf("\n\n--- COMPOSE EMAIL ---\n");
    printf("Enter recipient email address: ");
    scanf("%s", new_email.sender);
    printf("Enter email subject: ");
    scanf("%s", new_email.subject);
    printf("Enter email body: ");
    scanf("%s", new_email.body);
    sent[sent_size] = new_email;
    sent_size++;
}

int main() {
    int choice = 0;
    while (choice != 4) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                view_inbox();
                break;
            case 2:
                view_sent();
                break;
            case 3:
                compose_email();
                break;
            case 4:
                printf("\n\nGoodbye!\n");
                break;
            default:
                printf("\n\nInvalid Choice. Please try again.\n");
                break;
        }
    }
    return 0;
}
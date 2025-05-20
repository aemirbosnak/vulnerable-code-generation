//FormAI DATASET v1.0 Category: Email Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_SENDER_LENGTH 50
#define MAX_BODY_LENGTH 1000

struct Email {
    char subject[MAX_SUBJECT_LENGTH];
    char sender[MAX_SENDER_LENGTH];
    char body[MAX_BODY_LENGTH];
};

struct EmailClient {
    struct Email emails[MAX_EMAILS];
    int numEmails;
};

void displayMenu() {
    printf("\nWelcome to the Email Client\n");
    printf("1. Compose Email\n");
    printf("2. View Inbox\n");
    printf("3. Exit\n");
}

void addEmail(struct EmailClient* client, char* subject, char* sender, char* body) {
    if (client->numEmails >= MAX_EMAILS) {
        printf("Max capacity of emails reached\n");
        return;
    }

    struct Email* email = &client->emails[client->numEmails++];

    strcpy(email->subject, subject);
    strcpy(email->sender, sender);
    strcpy(email->body, body);

    printf("\nEmail sent successfully!\n");
}

void viewInbox(struct EmailClient* client) {
    printf("\nInbox (%d)\n", client->numEmails);

    for (int i = 0; i < client->numEmails; i++) {
        struct Email* email = &client->emails[i];
        printf("%d. Subject: %s\n   From: %s\n   Body: %s\n", i + 1, email->subject, email->sender, email->body);
    }
}

int main() {
    struct EmailClient client = {0};

    while (1) {
        displayMenu();

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char subject[MAX_SUBJECT_LENGTH];
                char sender[MAX_SENDER_LENGTH];
                char body[MAX_BODY_LENGTH];

                printf("\nEnter subject: ");
                scanf(" %[^\n]s", subject);

                printf("Enter sender: ");
                scanf(" %[^\n]s", sender);

                printf("Enter body: ");
                scanf(" %[^\n]s", body);

                addEmail(&client, subject, sender, body);
                break;
            }

            case 2:
                viewInbox(&client);
                break;

            case 3:
                printf("\nExiting Email Client. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice selected.\n");
                break;
        }
    }

    return 0;
}
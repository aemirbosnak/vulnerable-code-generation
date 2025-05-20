//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT 100
#define MAX_BODY 500
#define MAX_ADDRESS 100

typedef struct {
    char from[MAX_ADDRESS];
    char to[MAX_ADDRESS];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
} Email;

typedef struct {
    Email inbox[MAX_EMAILS];
    int count;
} EmailClient;

void initializeClient(EmailClient* client) {
    client->count = 0;
    printf("🌟 Email Client Initialized! 🌟\n");
}

void composeEmail(EmailClient* client) {
    if (client->count >= MAX_EMAILS) {
        printf("✉️ Inbox is full! Cannot send more emails.\n");
        return;
    }

    Email newEmail;
    printf("✍️ Compose a New Email\n");

    printf("From: ");
    fgets(newEmail.from, MAX_ADDRESS, stdin);
    newEmail.from[strcspn(newEmail.from, "\n")] = 0; // Remove newline

    printf("To: ");
    fgets(newEmail.to, MAX_ADDRESS, stdin);
    newEmail.to[strcspn(newEmail.to, "\n")] = 0; // Remove newline

    printf("Subject: ");
    fgets(newEmail.subject, MAX_SUBJECT, stdin);
    newEmail.subject[strcspn(newEmail.subject, "\n")] = 0; // Remove newline

    printf("Body:\n");
    fgets(newEmail.body, MAX_BODY, stdin);
    newEmail.body[strcspn(newEmail.body, "\n")] = 0; // Remove newline

    client->inbox[client->count++] = newEmail;
    printf("📧 Email Sent Successfully!\n");
}

void viewEmails(EmailClient* client) {
    printf("📫 Your Inbox\n");
    if (client->count == 0) {
        printf("No emails found in the inbox!\n");
        return;
    }
    for (int i = 0; i < client->count; i++) {
        printf("\nEmail %d:\n", i + 1);
        printf("From: %s\n", client->inbox[i].from);
        printf("To: %s\n", client->inbox[i].to);
        printf("Subject: %s\n", client->inbox[i].subject);
        printf("Body: %s\n", client->inbox[i].body);
    }
    printf("\n");
}

void displayMenu() {
    printf("🌐 Welcome to your Email Client 🌐\n");
    printf("1. Compose Email\n");
    printf("2. View Emails\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    EmailClient client;
    initializeClient(&client);
    
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // To consume the newline character after choice input
        switch (choice) {
            case 1:
                composeEmail(&client);
                break;
            case 2:
                viewEmails(&client);
                break;
            case 3:
                printf("🚪 Exiting the Email Client. Goodbye!\n");
                return 0;
            default:
                printf("❌ Invalid option. Please try again.\n");
        }
    }

    return 0;
}
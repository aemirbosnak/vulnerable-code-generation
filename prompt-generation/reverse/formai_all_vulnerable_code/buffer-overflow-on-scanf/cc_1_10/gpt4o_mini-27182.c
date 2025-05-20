//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500
#define MAX_SENDER_LENGTH 50
#define MAX_RECEIVER_LENGTH 50

typedef struct {
    char sender[MAX_SENDER_LENGTH];
    char receiver[MAX_RECEIVER_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

typedef struct {
    Email emails[MAX_EMAILS];
    int count;
} EmailClient;

void initEmailClient(EmailClient *client) {
    client->count = 0;
}

void sendEmail(EmailClient *client) {
    if (client->count >= MAX_EMAILS) {
        printf("Mailbox is full! Can't send more emails.\n");
        return;
    }

    Email newEmail;
    printf("Enter sender's name: ");
    fgets(newEmail.sender, MAX_SENDER_LENGTH, stdin);
    newEmail.sender[strcspn(newEmail.sender, "\n")] = 0; // Remove newline

    printf("Enter receiver's name: ");
    fgets(newEmail.receiver, MAX_RECEIVER_LENGTH, stdin);
    newEmail.receiver[strcspn(newEmail.receiver, "\n")] = 0; // Remove newline

    printf("Enter email subject: ");
    fgets(newEmail.subject, MAX_SUBJECT_LENGTH, stdin);
    newEmail.subject[strcspn(newEmail.subject, "\n")] = 0; // Remove newline

    printf("Enter email body:\n");
    fgets(newEmail.body, MAX_BODY_LENGTH, stdin);
    newEmail.body[strcspn(newEmail.body, "\n")] = 0; // Remove newline

    client->emails[client->count] = newEmail;
    client->count++;
    printf("Email sent successfully!\n");
}

void viewEmails(const EmailClient *client) {
    if (client->count == 0) {
        printf("No emails to display.\n");
    } else {
        for (int i = 0; i < client->count; i++) {
            printf("\nEmail #%d\n", i + 1);
            printf("From: %s\n", client->emails[i].sender);
            printf("To: %s\n", client->emails[i].receiver);
            printf("Subject: %s\n", client->emails[i].subject);
            printf("Body: %s\n", client->emails[i].body);
            printf("------------------------\n");
        }
    }
}

void displayMenu() {
    printf("**************************\n");
    printf("*    Retro Email Client    *\n");
    printf("**************************\n");
    printf("1. Send Email\n");
    printf("2. View Emails\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    EmailClient client;
    initEmailClient(&client);
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // consume newline after number selection

        switch(choice) {
            case 1:
                sendEmail(&client);
                break;
            case 2:
                viewEmails(&client);
                break;
            case 3:
                printf("Exiting the email client. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
//FormAI DATASET v1.0 Category: Email Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define MAX_EMAILS 100

typedef struct {
    char sender[MAX_BUFFER];
    char recipient[MAX_BUFFER];
    char subject[MAX_BUFFER];
    char body[MAX_BUFFER * 10];
} Email;

Email emails[MAX_EMAILS];
int numEmails = 0;

void displayMenu() {
    printf("\n=========== C EMAIL CLIENT ===========\n");
    printf("1. Compose Email\n");
    printf("2. View Inbox\n");
    printf("3. Exit Program\n");
    printf("Enter selection: ");
}

void composeEmail() {
    printf("\n=========== COMPOSE EMAIL ===========\n");
    Email newEmail;
    printf("Sender: ");
    fgets(newEmail.sender, MAX_BUFFER, stdin);
    printf("Recipient: ");
    fgets(newEmail.recipient, MAX_BUFFER, stdin);
    printf("Subject: ");
    fgets(newEmail.subject, MAX_BUFFER, stdin);
    printf("Body: ");
    fgets(newEmail.body, MAX_BUFFER * 10, stdin);

    emails[numEmails++] = newEmail;
    printf("\nEmail sent successfully!\n");
}

void viewInbox() {
    printf("\n=========== INBOX ===========\n");
    if (numEmails == 0) {
        printf("No emails in inbox\n");
        return;
    }

    for (int i = 0; i < numEmails; i++) {
        printf("Email %d\n", i+1);
        printf("From: %s", emails[i].sender);
        printf("To: %s", emails[i].recipient);
        printf("Subject: %s", emails[i].subject);
        printf("Body: %s", emails[i].body);
        printf("\n");
    }
}

int main() {
    int selection = 0;

    while (selection != 3) {
        displayMenu();
        scanf("%d", &selection);
        getchar(); // consume newline character

        switch(selection) {
            case 1:
                composeEmail();
                break;
            case 2:
                viewInbox();
                break;
            case 3:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid selection...\n");
        }
    }

    return 0;
}
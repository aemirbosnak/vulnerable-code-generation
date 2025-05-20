//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT 100
#define MAX_BODY 500
#define EMAIL_LENGTH 50

typedef struct {
    char recipient[EMAIL_LENGTH];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
} Email;

typedef struct {
    Email emails[MAX_EMAILS];
    int count;
} EmailClient;

void initClient(EmailClient *client) {
    client->count = 0;
}

void composeEmail(EmailClient *client) {
    if (client->count >= MAX_EMAILS) {
        printf("Oh dear, the mailbox is full! No more love letters can be sent.\n");
        return;
    }
    
    Email email;
    printf("To whom do you wish to send your heartfelt message? ");
    scanf("%s", email.recipient);
    
    printf("What subject shall we adorn our love letter with? ");
    scanf(" %[^\n]", email.subject);
    
    printf("Now, pour your heart into the message:\n");
    scanf(" %[^\n]", email.body);
    
    client->emails[client->count++] = email;
    printf("Your love letter has been sent, fluttering through the virtual skies!\n\n");
}

void viewEmails(EmailClient *client) {
    if (client->count == 0) {
        printf("Alas, the inbox is empty! No messages of love to cherish.\n");
        return;
    } 

    printf("Here are the love letters you have received:\n");
    for (int i = 0; i < client->count; i++) {
        printf("Email %d:\n", i + 1);
        printf("  To: %s\n", client->emails[i].recipient);
        printf("  Subject: %s\n", client->emails[i].subject);
        printf("  Message: %s\n\n", client->emails[i].body);
    }
}

void romanticMenu() {
    printf("Welcome to the Love Note Email Client!\n");
    printf("1. Compose a Love Letter\n");
    printf("2. View Love Letters\n");
    printf("3. Exit the Romantic Realm\n");
    printf("Choose your path: ");
}

int main() {
    EmailClient client;
    initClient(&client);
    int choice;

    while (1) {
        romanticMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                composeEmail(&client);
                break;
            case 2:
                viewEmails(&client);
                break;
            case 3:
                printf("May your heart be forever entwined with love! Exiting...\n");
                exit(0);
            default:
                printf("A gentle reminder to choose a valid option, dear heart.\n\n");
        }
    }

    return 0;
}
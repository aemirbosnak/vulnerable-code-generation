//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT 100
#define MAX_BODY 500
#define MAX_ADDRESS 50
#define MAX_NAME 50

typedef struct {
    char from[MAX_ADDRESS];
    char to[MAX_ADDRESS];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
} Email;

typedef struct {
    Email emails[MAX_EMAILS];
    int email_count;
} EmailClient;

void initialize(EmailClient* client) {
    client->email_count = 0;
    printf("Initializing Email Client... It's alive?!\n");
}

void sendEmail(EmailClient* client) {
    if (client->email_count >= MAX_EMAILS) {
        printf("Oh my goodness! Can't send more emails! Inbox full!\n");
        return;
    }
    
    Email new_email;
    printf("Sending Email... \n");

    printf("From: ");
    fgets(new_email.from, MAX_ADDRESS, stdin);
    new_email.from[strcspn(new_email.from, "\n")] = 0; // Remove trailing newline

    printf("To: ");
    fgets(new_email.to, MAX_ADDRESS, stdin);
    new_email.to[strcspn(new_email.to, "\n")] = 0; // Remove trailing newline

    printf("Subject: ");
    fgets(new_email.subject, MAX_SUBJECT, stdin);
    new_email.subject[strcspn(new_email.subject, "\n")] = 0; // Remove trailing newline

    printf("Body: ");
    fgets(new_email.body, MAX_BODY, stdin);
    new_email.body[strcspn(new_email.body, "\n")] = 0; // Remove trailing newline

    client->emails[client->email_count++] = new_email;
    printf("Email sent! Why doesn't it feel like it?!\n");
}

void readEmails(EmailClient* client) {
    if (client->email_count == 0) {
        printf("Eek! No emails to read!\n");
        return;
    }

    printf("Reading Emails... Hold on tight! \n");
    for (int i = 0; i < client->email_count; i++) {
        printf("Email #%d\n", i + 1);
        printf("From: %s\n", client->emails[i].from);
        printf("To: %s\n", client->emails[i].to);
        printf("Subject: %s\n", client->emails[i].subject);
        printf("Body: %s\n\n", client->emails[i].body);
    }
}

void deleteEmails(EmailClient* client) {
    if (client->email_count > 0) {
        client->email_count = 0;
        printf("All emails deleted! It's so empty here... aghh!\n");
    } else {
        printf("Uh-oh! No emails to delete!\n");
    }
}

void showMenu() {
    printf("Welcome to the Shockingly Awful Email Client!\n");
    printf("1. Send Email\n");
    printf("2. Read Emails\n");
    printf("3. Delete All Emails\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    EmailClient client;
    initialize(&client);
    
    int choice;
    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar(); // Clear the newline from the buffer
        switch (choice) {
            case 1:
                sendEmail(&client);
                break;
            case 2:
                readEmails(&client);
                break;
            case 3:
                deleteEmails(&client);
                break;
            case 4:
                printf("Exiting the Email Client... The horror! Goodbye!\n");
                exit(0);
            default:
                printf("What?! Invalid choice! Try again!\n");
        }
    }
    return 0;
}
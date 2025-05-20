//FormAI DATASET v1.0 Category: Email Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LEN 50
#define MAX_BODY_LEN 200
#define MAX_EMAIL_SIZE 300

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    char recipient[30];
    bool read;
} Email;

typedef struct {
    Email emails[MAX_EMAILS];
    int num_emails;
} EmailClient;

void print_menu() {
    printf("\n1. Compose Email");
    printf("\n2. View Inbox");
    printf("\n3. View Unread Emails");
    printf("\n4. Exit");
}

void print_email(const Email *e) {
    printf("\n\nFrom: %s", e->recipient);
    printf("\nSubject: %s", e->subject);
    printf("\nBody: %s", e->body);
    printf("\nRead: %s\n", e->read ? "yes" : "no");
}

void print_emails(const EmailClient *client, bool show_read) {
    for (int i = 0; i < client->num_emails; i++) {
        const Email *e = &client->emails[i];
        if (show_read || !e->read) {
            printf("\n%2d | %s | %s", i + 1, e->recipient, e->subject);
            printf("\tRead: %s\n", e->read ? "yes" : "no");
        }
    }
}

void compose_email(EmailClient *client) {
    if (client->num_emails >= MAX_EMAILS) {
        printf("\nError: Max number of emails reached.");
        return;
    }

    Email *e = &client->emails[client->num_emails++];
    
    printf("\nEnter recipient:");
    scanf("%s", e->recipient);

    printf("\nEnter subject:");
    scanf("%s", e->subject);

    printf("\nEnter body:");
    scanf("%s", e->body);

    e->read = false;

    printf("\nEmail sent successfully.");
}

void view_inbox(const EmailClient *client) {
    if (client->num_emails == 0) {
        printf("\nInbox is empty.");
        return;
    }

    printf("\nInbox:");
    print_emails(client, true);

    int choice;
    do {
        printf("\nEnter email number to view (0 to exit): ");
        scanf("%d", &choice);
        if (choice != 0 && (choice < 1 || choice > client->num_emails)) {
            printf("\nInvalid choice.");
        }
    } while (choice != 0 && (choice < 1 || choice > client->num_emails));

    if (choice != 0) {
        Email *e = &client->emails[choice - 1];
        e->read = true;
        print_email(e);
    }
}

void view_unread_emails(const EmailClient *client) {
    printf("\nUnread Emails:");
    print_emails(client, false);
}

int main() {
    EmailClient client = { 0 };
    int choice;

    do {
        print_menu();
        printf("\nEnter choice:");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            compose_email(&client);
            break;
        case 2:
            view_inbox(&client);
            break;
        case 3:
            view_unread_emails(&client);
            break;
        case 4:
            printf("\nExiting program...");
            break;
        default:
            printf("\nInvalid choice.");
            break;
        }
    } while (choice != 4);

    return 0;
}
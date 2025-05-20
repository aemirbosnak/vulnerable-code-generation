//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500
#define MAX_EMAILS 100

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int id;
} Email;

typedef struct {
    Email *emails;
    int count;
    int capacity;
} EmailClient;

EmailClient* create_email_client(int capacity) {
    EmailClient *client = (EmailClient *)malloc(sizeof(EmailClient));
    client->emails = (Email *)malloc(capacity * sizeof(Email));
    client->count = 0;
    client->capacity = capacity;
    return client;
}

void send_email(EmailClient *client, const char *subject, const char *body) {
    if (client->count == client->capacity) {
        client->capacity *= 2;
        client->emails = (Email *)realloc(client->emails, client->capacity * sizeof(Email));
    }
    Email *new_email = &client->emails[client->count++];
    strncpy(new_email->subject, subject, MAX_SUBJECT_LENGTH);
    strncpy(new_email->body, body, MAX_BODY_LENGTH);
    new_email->id = client->count; // Assign an incremental ID
    printf("Email sent successfully with ID: %d\n", new_email->id);
}

void view_emails(EmailClient *client) {
    if (client->count == 0) {
        printf("No emails to view.\n");
        return;
    }
    for (int i = 0; i < client->count; i++) {
        printf("Email ID: %d\n", client->emails[i].id);
        printf("Subject: %s\n", client->emails[i].subject);
        printf("Body: %s\n\n", client->emails[i].body);
    }
}

void free_email_client(EmailClient *client) {
    free(client->emails);
    free(client);
}

int main() {
    EmailClient *client = create_email_client(5);
    int choice;
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];

    do {
        printf("Welcome to the Email Client!\n");
        printf("1. Send Email\n");
        printf("2. View Emails\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume newline character

        switch(choice) {
            case 1:
                printf("Enter Subject: ");
                fgets(subject, MAX_SUBJECT_LENGTH, stdin);
                subject[strcspn(subject, "\n")] = 0; // Remove newline
                printf("Enter Body: ");
                fgets(body, MAX_BODY_LENGTH, stdin);
                body[strcspn(body, "\n")] = 0; // Remove newline
                send_email(client, subject, body);
                break;

            case 2:
                view_emails(client);
                break;

            case 3:
                printf("Exiting the email client. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    free_email_client(client);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Email Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char from[MAX_EMAILS][50];
    char subject[MAX_EMAILS][MAX_SUBJECT_LENGTH];
    char body[MAX_EMAILS][MAX_BODY_LENGTH];
    int num_emails;
} EmailClient;

void initialize_email_client(EmailClient* client) {
    memset(client, 0, sizeof(EmailClient));
}

int add_email(EmailClient* client, char* from, char* subject, char* body) {
    if (client->num_emails >= MAX_EMAILS) {
        return -1;
    }

    strcpy(client->from[client->num_emails], from);
    strcpy(client->subject[client->num_emails], subject);
    strcpy(client->body[client->num_emails], body);

    client->num_emails++;

    return 0;
}

int main() {
    EmailClient client;
    initialize_email_client(&client);

    int choice;
    do {
        printf("1. Add Email\n");
        printf("2. View Emails\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter From: ");
                scanf("%s", client.from[client.num_emails]);
                printf("Enter Subject: ");
                scanf("%s", client.subject[client.num_emails]);
                printf("Enter Body: ");
                scanf("%s", client.body[client.num_emails]);
                break;
            case 2:
                for (int i = 0; i < client.num_emails; i++) {
                    printf("Email %d:\n");
                    printf("From: %s\n", client.from[i]);
                    printf("Subject: %s\n", client.subject[i]);
                    printf("Body: %s\n", client.body[i]);
                    printf("\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}
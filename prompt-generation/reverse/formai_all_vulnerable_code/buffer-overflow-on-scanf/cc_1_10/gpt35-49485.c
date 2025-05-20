//FormAI DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 200

// Define the email struct
struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char recipient[50];
    char sender[50];
};

// Define the email client struct
struct email_client {
    struct email emails[MAX_EMAILS];
    int num_emails;
};

// Define function prototypes
void compose_email(struct email_client *client);
void print_emails(struct email_client *client);
void send_email(struct email_client *client, int index);

int main() {
    struct email_client client = { 0 };

    // Display menu and execute user selection
    int choice;
    do {
        printf("\nEmail Client Menu\n");
        printf("1. Compose Email\n");
        printf("2. View Emails\n");
        printf("3. Send Email\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                compose_email(&client);
                break;
            case 2:
                print_emails(&client);
                break;
            case 3:
                printf("Enter email index to send: ");
                int index;
                scanf("%d", &index);
                send_email(&client, index);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to compose email and add it to the client's email list
void compose_email(struct email_client *client) {
    struct email email;

    printf("Composing Email\n");
    printf("Enter recipient's email address: ");
    scanf("%s", email.recipient);
    printf("Enter sender's email address: ");
    scanf("%s", email.sender);
    printf("Enter email subject: ");
    scanf("%s", email.subject);
    printf("Enter email body: ");
    scanf("%s", email.body);

    client->emails[client->num_emails++] = email;
}

// Function to print all emails in the client's email list
void print_emails(struct email_client *client) {
    printf("\nEmails\n");
    printf("------\n");
    for (int i = 0; i < client->num_emails; i++) {
        printf("[%d] From: %s\n", i, client->emails[i].sender);
        printf("    To: %s\n", client->emails[i].recipient);
        printf("    Subject: %s\n", client->emails[i].subject);
        printf("    Body: %s\n", client->emails[i].body);
    }
}

// Function to send email by printing it to the console
void send_email(struct email_client *client, int index) {
    printf("\nSending Email\n");
    printf("--------------\n");
    printf("From: %s\n", client->emails[index].sender);
    printf("To: %s\n", client->emails[index].recipient);
    printf("Subject: %s\n", client->emails[index].subject);
    printf("Body: %s\n", client->emails[index].body);
}
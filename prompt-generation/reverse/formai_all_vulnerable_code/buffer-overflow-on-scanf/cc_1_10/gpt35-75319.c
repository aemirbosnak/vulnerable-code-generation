//FormAI DATASET v1.0 Category: Email Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 256
#define MAX_MESSAGE_LENGTH 1024
#define MAX_EMAILS 100

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char sender[MAX_SUBJECT_LENGTH];
} Email;

typedef struct {
    char username[MAX_SUBJECT_LENGTH];
    char password[MAX_SUBJECT_LENGTH];
    Email inbox[MAX_EMAILS];
    int num_emails;
} EmailAccount;

void display_prompt(EmailAccount* account) {
    printf("Welcome, %s! You have %d new emails.\n", account->username, account->num_emails);
    printf("Type 'read' to read your emails or 'send' to send a new email:\n");
}

void read_emails(EmailAccount* account) {
    for (int i = 0; i < account->num_emails; i++) {
        Email* email = &account->inbox[i];
        printf("Email %d - Subject: %s\nFrom: %s\nMessage: %s\n", i+1, email->subject, email->sender, email->message);
    }
    account->num_emails = 0;
}

void send_email(EmailAccount* account) {
    Email email;
    printf("Enter recipient: ");
    scanf("%s", email.sender);
    printf("Enter subject: ");
    scanf("%s", email.subject);
    printf("Enter message: ");
    scanf("%s", email.message);
    printf("Email sent to %s with subject '%s':\n%s\n", email.sender, email.subject, email.message);
}

int main() {
    EmailAccount my_email = {"example_username", "example_password", {}, 0};
    char command[MAX_SUBJECT_LENGTH];
    while (1) {
        display_prompt(&my_email);
        scanf("%s", command);
        if (strcmp(command, "read") == 0) {
            read_emails(&my_email);
        } else if (strcmp(command, "send") == 0) {
            send_email(&my_email);
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}
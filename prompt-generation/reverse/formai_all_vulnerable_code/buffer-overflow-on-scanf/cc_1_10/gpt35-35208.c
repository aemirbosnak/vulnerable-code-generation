//FormAI DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000
#define MAX_EMAILS 100

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    char to[50];
    char from[50];
} Email;

void send_email(Email *email) {
    printf("Sending email...\n");
    printf("To: %s\n", email->to);
    printf("From: %s\n", email->from);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
}

int main() {
    int num_emails = 0;
    Email inbox[MAX_EMAILS];

    printf("Welcome to MyEmail Client!\n");

    while (1) {
        char option;
        printf("\nPlease select an option:\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");

        scanf(" %c", &option);
        fflush(stdin);

        if (option == '1') {
            Email new_email;
            printf("\n\nCompose Email\n");
            printf("To: ");
            fgets(new_email.to, sizeof(new_email.to), stdin);
            printf("From: ");
            fgets(new_email.from, sizeof(new_email.from), stdin);
            printf("Subject: ");
            fgets(new_email.subject, sizeof(new_email.subject), stdin);
            printf("Body: ");
            fgets(new_email.body, sizeof(new_email.body), stdin);

            send_email(&new_email);
            printf("Email sent successfully!\n");
        } else if (option == '2') {
            printf("\n\nInbox\n");
            if (num_emails == 0) {
                printf("No emails to display.\n");
            } else {
                for (int i = 0; i < num_emails; i++) {
                    printf("%d. From: %s\nSubject: %s\nBody: %s\n\n", i+1, inbox[i].from, inbox[i].subject, inbox[i].body);
                }
            }
        } else if (option == '3') {
            printf("\n\nExiting MyEmail Client...\n");
            break;
        } else {
            printf("\n\nInvalid option, please try again.\n");
        }
    }

    return 0;
}
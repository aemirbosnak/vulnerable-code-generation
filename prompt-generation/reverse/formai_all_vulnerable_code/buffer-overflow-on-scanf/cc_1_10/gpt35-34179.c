//FormAI DATASET v1.0 Category: Email Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 100
#define MAX_EMAILS 10

struct email {
    char sender[MAX_STRING_LEN];
    char recipient[MAX_STRING_LEN];
    char subject[MAX_STRING_LEN];
    char body[MAX_STRING_LEN];
};

struct email email_list[MAX_EMAILS];
int num_emails = 0;

void send_email(char sender[], char recipient[], char subject[], char body[]) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: email list is full\n");
        return;
    }

    struct email new_email;
    strncpy(new_email.sender, sender, MAX_STRING_LEN);
    strncpy(new_email.recipient, recipient, MAX_STRING_LEN);
    strncpy(new_email.subject, subject, MAX_STRING_LEN);
    strncpy(new_email.body, body, MAX_STRING_LEN);

    email_list[num_emails] = new_email;
    num_emails++;

    printf("Email sent successfully!\n");
}

void print_emails() {
    if (num_emails == 0) {
        printf("Email list is empty\n");
        return;
    }

    printf("Email List:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("Email %d:\n", i+1);
        printf("Sender: %s\n", email_list[i].sender);
        printf("Recipient: %s\n", email_list[i].recipient);
        printf("Subject: %s\n", email_list[i].subject);
        printf("Body: %s\n", email_list[i].body);
    }
}

int main() {
    int choice;
    char sender[MAX_STRING_LEN];
    char recipient[MAX_STRING_LEN];
    char subject[MAX_STRING_LEN];
    char body[MAX_STRING_LEN];

    do {
        printf("C Email Client:\n");
        printf("1. Send email\n");
        printf("2. View emails\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter sender email address: ");
                scanf("%s", sender);
                printf("Enter recipient email address: ");
                scanf("%s", recipient);
                printf("Enter email subject: ");
                scanf("%s", subject);
                printf("Enter email body: ");
                scanf("%s", body);

                send_email(sender, recipient, subject, body);
                break;

            case 2:
                print_emails();
                break;

            case 3:
                printf("Exiting C Email Client...\n");
                break;

            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
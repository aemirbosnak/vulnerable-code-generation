//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LEN 1000

typedef struct {
    char sender[MAX_EMAIL_LEN];
    char recipient[MAX_EMAIL_LEN];
    char subject[MAX_EMAIL_LEN];
    char message[MAX_EMAIL_LEN];
} Email;

void print_email(Email email) {
    printf("Sender: %s\n", email.sender);
    printf("Recipient: %s\n", email.recipient);
    printf("Subject: %s\n", email.subject);
    printf("Message: %s\n", email.message);
}

int main() {
    Email emails[MAX_EMAILS];
    int num_emails = 0;
    char command[MAX_EMAIL_LEN];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "new") == 0) {
            Email email;
            printf("Enter sender: ");
            scanf("%s", email.sender);
            printf("Enter recipient: ");
            scanf("%s", email.recipient);
            printf("Enter subject: ");
            scanf("%s", email.subject);
            printf("Enter message: ");
            scanf("%s", email.message);
            emails[num_emails++] = email;
        } else if (strcmp(command, "list") == 0) {
            for (int i = 0; i < num_emails; i++) {
                print_email(emails[i]);
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}
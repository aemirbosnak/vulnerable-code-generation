//Falcon-180B DATASET v1.0 Category: Email Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1000

typedef struct email_t {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];
} email_t;

int num_emails = 0;
email_t emails[MAX_EMAILS];

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Thou hast reached the limit of emails, my lord.\n");
        return;
    }

    email_t new_email;
    memset(&new_email, 0, sizeof(email_t));

    printf("Enter the name of the sender: ");
    scanf("%s", new_email.from);

    printf("Enter the name of the recipient: ");
    scanf("%s", new_email.to);

    printf("Enter the subject of the email: ");
    scanf("%s", new_email.subject);

    printf("Enter the body of the email: ");
    scanf("%s", new_email.body);

    emails[num_emails] = new_email;
    num_emails++;

    printf("Email added successfully, my lord.\n");
}

void view_emails() {
    if (num_emails == 0) {
        printf("Thou hast no emails, my lord.\n");
        return;
    }

    for (int i = 0; i < num_emails; i++) {
        printf("Email %d:\n");
        printf("From: %s\n", emails[i].from);
        printf("To: %s\n", emails[i].to);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n\n", emails[i].body);
    }
}

int main() {
    printf("Welcome to the Medieval Email Client!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add email\n");
        printf("2. View emails\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                view_emails();
                break;
            case 3:
                printf("Farewell, my lord.\n");
                return 0;
            default:
                printf("Invalid option, my lord.\n");
        }
    }

    return 0;
}
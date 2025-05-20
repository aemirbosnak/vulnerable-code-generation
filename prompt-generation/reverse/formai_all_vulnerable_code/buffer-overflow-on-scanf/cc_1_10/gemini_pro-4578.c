//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    int subscribed;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char *email) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    for (int i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            printf("Error: Email already exists.\n");
            return;
        }
    }

    strcpy(emails[num_emails].email, email);
    emails[num_emails].subscribed = 1;
    num_emails++;

    printf("Email added successfully.\n");
}

void remove_email(char *email) {
    for (int i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            emails[i] = emails[num_emails - 1];
            num_emails--;
            printf("Email removed successfully.\n");
            return;
        }
    }

    printf("Error: Email not found.\n");
}

void subscribe_email(char *email) {
    for (int i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            emails[i].subscribed = 1;
            printf("Email subscribed successfully.\n");
            return;
        }
    }

    printf("Error: Email not found.\n");
}

void unsubscribe_email(char *email) {
    for (int i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            emails[i].subscribed = 0;
            printf("Email unsubscribed successfully.\n");
            return;
        }
    }

    printf("Error: Email not found.\n");
}

void list_emails() {
    printf("Emails:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%s (%s)\n", emails[i].email, emails[i].subscribed ? "subscribed" : "unsubscribed");
    }
}

int main() {
    char command[50];
    char email[MAX_EMAIL_LENGTH];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s", email);
            add_email(email);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%s", email);
            remove_email(email);
        } else if (strcmp(command, "subscribe") == 0) {
            scanf("%s", email);
            subscribe_email(email);
        } else if (strcmp(command, "unsubscribe") == 0) {
            scanf("%s", email);
            unsubscribe_email(email);
        } else if (strcmp(command, "list") == 0) {
            list_emails();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Error: Unknown command.\n");
        }
    }

    return 0;
}
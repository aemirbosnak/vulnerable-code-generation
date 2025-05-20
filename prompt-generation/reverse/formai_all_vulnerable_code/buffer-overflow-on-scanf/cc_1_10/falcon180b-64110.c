//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 10000
#define MAX_EMAIL_LENGTH 1000

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

    strcpy(emails[num_emails].email, email);
    emails[num_emails].subscribed = 1;
    num_emails++;
}

void remove_email(char *email) {
    int i;

    for (i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            emails[i].subscribed = 0;
            break;
        }
    }
}

void send_email(char *subject, char *body) {
    int i;

    for (i = 0; i < num_emails; i++) {
        if (emails[i].subscribed) {
            printf("Sending email to %s...\n", emails[i].email);
        }
    }
}

int main() {
    char input[MAX_EMAIL_LENGTH];

    while (1) {
        printf("Enter command (add/remove/send/exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter email address: ");
            scanf("%s", input);
            add_email(input);
        } else if (strcmp(input, "remove") == 0) {
            printf("Enter email address: ");
            scanf("%s", input);
            remove_email(input);
        } else if (strcmp(input, "send") == 0) {
            printf("Enter subject: ");
            scanf("%s", input);
            printf("Enter body: ");
            scanf("%s", input);
            send_email(input, input);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
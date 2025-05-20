//Falcon-180B DATASET v1.0 Category: Email Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100

typedef struct email {
    char sender[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_EMAIL_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* sender, char* subject, char* body) {
    strcpy(emails[num_emails].sender, sender);
    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);
    num_emails++;
}

void print_emails() {
    for (int i = 0; i < num_emails; i++) {
        printf("Sender: %s\n", emails[i].sender);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n\n", emails[i].body);
    }
}

int main() {
    char input[MAX_EMAIL_LENGTH];
    char sender[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_EMAIL_LENGTH];

    while (1) {
        printf("Enter an email (or type 'exit' to quit):\n");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        char* p = input;
        while (isspace(*p)) {
            p++;
        }
        strcpy(sender, p);

        p = strchr(input, '@');
        if (p == NULL) {
            printf("Invalid email address.\n");
            continue;
        }
        *p = '\0';

        p = strchr(input, ':');
        if (p == NULL) {
            printf("Invalid email subject.\n");
            continue;
        }
        *p = '\0';

        strcpy(subject, p + 1);

        p = strchr(input, ':');
        if (p == NULL) {
            printf("Invalid email body.\n");
            continue;
        }
        *p = '\0';

        strcpy(body, p + 1);

        add_email(sender, subject, body);
    }

    print_emails();

    return 0;
}
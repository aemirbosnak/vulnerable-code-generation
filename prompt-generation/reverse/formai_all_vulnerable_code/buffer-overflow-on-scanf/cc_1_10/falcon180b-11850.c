//Falcon-180B DATASET v1.0 Category: Email Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 500

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} email_t;

int email_count = 0;
email_t emails[MAX_EMAILS];

void add_email(char *email, char *subject, char *body) {
    strcpy(emails[email_count].email, email);
    strcpy(emails[email_count].subject, subject);
    strcpy(emails[email_count].body, body);
    email_count++;
}

void print_emails() {
    int i;
    for (i = 0; i < email_count; i++) {
        printf("Email %d:\n");
        printf("Email: %s\n", emails[i].email);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n", emails[i].body);
        printf("\n");
    }
}

int main() {
    char input[MAX_EMAIL_LENGTH];
    int i;

    printf("Welcome to the Email Client!\n");

    while (1) {
        printf("Enter an email address (or type 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        add_email(input, "", "");
    }

    print_emails();

    return 0;
}
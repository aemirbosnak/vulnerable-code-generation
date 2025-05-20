//Falcon-180B DATASET v1.0 Category: Email Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_EMAIL_LENGTH];
} Email;

void read_emails(Email* emails, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter email #%d:\n", i + 1);
        printf("From: ");
        scanf("%s", emails[i].from);
        printf("To: ");
        scanf("%s", emails[i].to);
        printf("Subject: ");
        scanf("%s", emails[i].subject);
        printf("Body: ");
        fgets(emails[i].body, MAX_EMAIL_LENGTH, stdin);
    }
}

void send_email(Email email) {
    printf("Sending email from %s to %s:\n", email.from, email.to);
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s", email.body);
}

void main() {
    Email emails[MAX_EMAILS];
    int count;

    printf("Enter number of emails to send: ");
    scanf("%d", &count);

    if (count > MAX_EMAILS) {
        printf("Error: too many emails.\n");
        exit(1);
    }

    read_emails(emails, count);

    for (int i = 0; i < count; i++) {
        send_email(emails[i]);
    }
}
//Falcon-180B DATASET v1.0 Category: Email Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_EMAIL_LENGTH 200

typedef struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char from[MAX_EMAIL_LENGTH];
} Email;

Email create_email(char* subject, char* body, char* to, char* from) {
    Email email;
    strncpy(email.subject, subject, MAX_SUBJECT_LENGTH);
    strncpy(email.body, body, MAX_BODY_LENGTH);
    strncpy(email.to, to, MAX_EMAIL_LENGTH);
    strncpy(email.from, from, MAX_EMAIL_LENGTH);
    return email;
}

void send_email(Email* email) {
    printf("Sending email...\n");
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
    printf("To: %s\n", email->to);
    printf("From: %s\n", email->from);
}

int main() {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char from[MAX_EMAIL_LENGTH];

    printf("Enter the subject: ");
    scanf("%s", subject);

    printf("Enter the body: ");
    scanf("%[^\n]", body);

    printf("Enter the recipient's email address: ");
    scanf("%s", to);

    printf("Enter your email address: ");
    scanf("%s", from);

    Email email = create_email(subject, body, to, from);
    send_email(&email);

    return 0;
}
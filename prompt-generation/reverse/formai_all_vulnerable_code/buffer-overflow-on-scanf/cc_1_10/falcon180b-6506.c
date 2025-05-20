//Falcon-180B DATASET v1.0 Category: Email Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECIPIENTS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char name[MAX_RECIPIENTS];
    char email[MAX_RECIPIENTS];
} Recipient;

typedef struct {
    char from[MAX_RECIPIENTS];
    char to[MAX_RECIPIENTS];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

void send_email(Email *email) {
    printf("Sending email...\n");
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
}

int main() {
    Email email;
    int num_recipients;

    printf("Enter number of recipients: ");
    scanf("%d", &num_recipients);

    printf("Enter sender's name: ");
    scanf("%s", email.from);

    printf("Enter sender's email: ");
    scanf("%s", email.from);

    printf("Enter recipient %d's name: ", 1);
    scanf("%s", email.to);

    printf("Enter recipient %d's email: ", 1);
    scanf("%s", email.to);

    strcpy(email.subject, "Test Email");
    strcpy(email.body, "Hello World!");

    send_email(&email);

    return 0;
}
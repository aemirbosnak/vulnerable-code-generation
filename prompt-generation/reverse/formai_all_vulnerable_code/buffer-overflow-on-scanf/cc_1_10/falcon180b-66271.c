//Falcon-180B DATASET v1.0 Category: Email Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10
#define MAX_ATTACHMENTS 5

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char recipients[MAX_RECIPIENTS][50];
    int num_recipients;
    char attachments[MAX_ATTACHMENTS][100];
    int num_attachments;
    time_t timestamp;
} Email;

Email create_email() {
    Email email;
    email.num_recipients = 0;
    email.num_attachments = 0;
    strcpy(email.subject, "");
    strcpy(email.body, "");
    email.timestamp = time(NULL);
    return email;
}

void add_recipient(Email* email, char* recipient) {
    if (email->num_recipients >= MAX_RECIPIENTS) {
        printf("Error: Maximum number of recipients reached.\n");
        return;
    }
    strcpy(email->recipients[email->num_recipients], recipient);
    email->num_recipients++;
}

void add_attachment(Email* email, char* attachment) {
    if (email->num_attachments >= MAX_ATTACHMENTS) {
        printf("Error: Maximum number of attachments reached.\n");
        return;
    }
    strcpy(email->attachments[email->num_attachments], attachment);
    email->num_attachments++;
}

void send_email(Email email) {
    // Code to send email goes here
    printf("Email sent successfully!\n");
}

int main() {
    Email email = create_email();
    char recipient[50];
    int i;

    printf("Enter recipient email addresses (up to %d):\n", MAX_RECIPIENTS - 1);
    for (i = 0; i < MAX_RECIPIENTS - 1; i++) {
        scanf("%s", recipient);
        add_recipient(&email, recipient);
    }

    printf("Enter email subject (up to %d characters):\n", MAX_SUBJECT_LENGTH - 1);
    scanf("%s", email.subject);

    printf("Enter email body (up to %d characters):\n", MAX_BODY_LENGTH - 1);
    scanf("%[^\n]", email.body);

    printf("Enter attachment filenames (up to %d):\n", MAX_ATTACHMENTS - 1);
    for (i = 0; i < MAX_ATTACHMENTS - 1; i++) {
        scanf("%s", email.attachments[i]);
    }

    send_email(email);

    return 0;
}
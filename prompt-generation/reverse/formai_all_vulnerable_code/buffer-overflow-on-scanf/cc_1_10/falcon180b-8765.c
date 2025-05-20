//Falcon-180B DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
} Email;

void send_email(Email* email) {
    printf("Sending email...\n");
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
    printf("Recipients:\n");
    for (int i = 0; i < email->num_recipients; i++) {
        printf("%s\n", email->recipients[i]);
    }
    printf("Attachments:\n");
    for (int i = 0; i < email->num_attachments; i++) {
        printf("%s\n", email->attachments[i]);
    }
}

int main() {
    Email email;

    printf("Enter email subject (max %d characters): ", MAX_SUBJECT_LENGTH);
    scanf("%[^\n]", email.subject);

    printf("Enter email body (max %d characters): ", MAX_BODY_LENGTH);
    scanf("%[^\n]", email.body);

    int num_recipients = 0;
    while (num_recipients < MAX_RECIPIENTS) {
        printf("Enter recipient email address (max %d characters): ", 50);
        scanf("%[^\n]", email.recipients[num_recipients]);
        num_recipients++;
    }
    email.num_recipients = num_recipients;

    int num_attachments = 0;
    while (num_attachments < MAX_ATTACHMENTS) {
        printf("Enter attachment file name (max %d characters): ", 100);
        scanf("%[^\n]", email.attachments[num_attachments]);
        num_attachments++;
    }
    email.num_attachments = num_attachments;

    send_email(&email);

    return 0;
}
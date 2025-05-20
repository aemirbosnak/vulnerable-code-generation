//Falcon-180B DATASET v1.0 Category: Email Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10
#define MAX_ATTACHMENTS 5

typedef struct {
    char subject[MAX_SUBJECT_LENGTH + 1];
    char body[MAX_BODY_LENGTH + 1];
    char recipients[MAX_RECIPIENTS][100];
    char attachments[MAX_ATTACHMENTS][100];
    int num_recipients;
    int num_attachments;
} Email;

void send_email(Email *email) {
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

    printf("Enter subject (max %d characters): ", MAX_SUBJECT_LENGTH);
    scanf("%[^\n]", email.subject);

    printf("Enter body (max %d characters): ", MAX_BODY_LENGTH);
    scanf("%[^\n]", email.body);

    int num_recipients = 0;
    printf("Enter number of recipients (max %d): ", MAX_RECIPIENTS);
    scanf("%d", &num_recipients);

    for (int i = 0; i < num_recipients; i++) {
        printf("Enter recipient %d (max 100 characters): ", i + 1);
        scanf("%[^\n]", email.recipients[i]);
    }

    int num_attachments = 0;
    printf("Enter number of attachments (max %d): ", MAX_ATTACHMENTS);
    scanf("%d", &num_attachments);

    for (int i = 0; i < num_attachments; i++) {
        printf("Enter attachment %d (max 100 characters): ", i + 1);
        scanf("%[^\n]", email.attachments[i]);
    }

    email.num_recipients = num_recipients;
    email.num_attachments = num_attachments;

    send_email(&email);

    return 0;
}
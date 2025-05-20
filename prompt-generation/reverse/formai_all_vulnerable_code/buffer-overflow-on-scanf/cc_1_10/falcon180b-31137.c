//Falcon-180B DATASET v1.0 Category: Email Client ; Style: introspective
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
    char recipients[MAX_RECIPIENTS][100];
    char attachments[MAX_ATTACHMENTS][100];
    time_t timestamp;
} email;

void send_email(email *e) {
    printf("Sending email...\n");
    printf("Subject: %s\n", e->subject);
    printf("Body:\n%s\n", e->body);
    printf("Recipients:\n");
    for (int i = 0; i < strlen(e->recipients); i++) {
        printf("%s\n", e->recipients[i]);
    }
    printf("Attachments:\n");
    for (int i = 0; i < strlen(e->attachments); i++) {
        printf("%s\n", e->attachments[i]);
    }
}

int main() {
    email e;
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char recipients[MAX_RECIPIENTS][100];
    char attachments[MAX_ATTACHMENTS][100];
    int num_recipients = 0;
    int num_attachments = 0;

    printf("Enter email subject: ");
    scanf("%s", subject);

    printf("Enter email body: ");
    fgets(body, MAX_BODY_LENGTH, stdin);

    printf("Enter number of recipients: ");
    scanf("%d", &num_recipients);

    for (int i = 0; i < num_recipients; i++) {
        printf("Enter recipient %d email address: ", i+1);
        scanf("%s", recipients[i]);
    }

    printf("Enter number of attachments: ");
    scanf("%d", &num_attachments);

    for (int i = 0; i < num_attachments; i++) {
        printf("Enter attachment %d filename: ", i+1);
        scanf("%s", attachments[i]);
    }

    strcpy(e.subject, subject);
    strcpy(e.body, body);
    strcpy(e.recipients[0], recipients[0]);
    strcpy(e.attachments[0], attachments[0]);

    time_t now = time(0);
    e.timestamp = now;

    send_email(&e);

    return 0;
}
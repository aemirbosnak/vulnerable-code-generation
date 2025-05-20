//Falcon-180B DATASET v1.0 Category: Email Client ; Style: medieval
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
    char subject[MAX_SUBJECT_LENGTH+1];
    char body[MAX_BODY_LENGTH+1];
    char sender[MAX_SUBJECT_LENGTH+1];
    char recipients[MAX_RECIPIENTS][MAX_SUBJECT_LENGTH+1];
    int num_recipients;
    char attachments[MAX_ATTACHMENTS][MAX_SUBJECT_LENGTH+1];
    int num_attachments;
    time_t timestamp;
} Email;

void send_email(Email* email) {
    printf("Sending email:\n");
    printf("Subject: %s\n", email->subject);
    printf("Sender: %s\n", email->sender);
    printf("Recipients:\n");
    for (int i = 0; i < email->num_recipients; i++) {
        printf("- %s\n", email->recipients[i]);
    }
    printf("Attachments:\n");
    for (int i = 0; i < email->num_attachments; i++) {
        printf("- %s\n", email->attachments[i]);
    }
    printf("Timestamp: %s\n", ctime(&email->timestamp));
}

int main() {
    Email email;

    printf("Enter the subject of the email: ");
    scanf("%s", email.subject);

    printf("Enter the body of the email: ");
    scanf("%[^\n]", email.body);

    printf("Enter the sender's name: ");
    scanf("%s", email.sender);

    int num_recipients;
    printf("Enter the number of recipients: ");
    scanf("%d", &num_recipients);

    printf("Enter the recipients' names:\n");
    for (int i = 0; i < num_recipients; i++) {
        scanf("%s", email.recipients[i]);
    }

    int num_attachments;
    printf("Enter the number of attachments: ");
    scanf("%d", &num_attachments);

    printf("Enter the attachments' names:\n");
    for (int i = 0; i < num_attachments; i++) {
        scanf("%s", email.attachments[i]);
    }

    time_t current_time = time(NULL);
    email.timestamp = current_time;

    send_email(&email);

    return 0;
}
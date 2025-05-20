//Falcon-180B DATASET v1.0 Category: Email Client ; Style: mind-bending
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
    scanf("%s", email.subject);

    printf("Enter body (max %d characters): \n", MAX_BODY_LENGTH);
    fgets(email.body, MAX_BODY_LENGTH, stdin);
    email.body[strcspn(email.body, "\n")] = '\0';

    int num_recipients = 0;
    printf("Enter number of recipients (max %d): ", MAX_RECIPIENTS);
    scanf("%d", &num_recipients);

    for (int i = 0; i < num_recipients; i++) {
        printf("Enter recipient %d (max %d characters): ", i+1, 50);
        scanf("%s", email.recipients[i]);
    }

    int num_attachments = 0;
    printf("Enter number of attachments (max %d): ", MAX_ATTACHMENTS);
    scanf("%d", &num_attachments);

    for (int i = 0; i < num_attachments; i++) {
        printf("Enter attachment %d (max %d characters): ", i+1, 100);
        scanf("%s", email.attachments[i]);
    }

    send_email(&email);

    return 0;
}
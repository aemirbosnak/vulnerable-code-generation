//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
} Email;

void read_email(Email* email) {
    printf("Subject: %s\n", email->subject);
    printf("Sender: %s\n", email->sender);
    printf("Recipients:\n");
    for (int i = 0; i < email->num_recipients; i++) {
        printf("\t%s\n", email->recipients[i]);
    }
    printf("\nBody:\n%s\n", email->body);
    printf("Attachments:\n");
    for (int i = 0; i < email->num_attachments; i++) {
        printf("\t%s\n", email->attachments[i]);
    }
}

int main() {
    Email email;

    printf("Enter the subject of the email:\n");
    scanf("%[^\n]", email.subject);

    printf("Enter the sender's email address:\n");
    scanf("%[^\n]", email.sender);

    int num_recipients = 0;
    char recipient[MAX_SUBJECT_LENGTH+1];
    while (num_recipients < MAX_RECIPIENTS && scanf(" %[^\n]", recipient)!= EOF) {
        strcpy(email.recipients[num_recipients], recipient);
        num_recipients++;
    }

    printf("Enter the body of the email:\n");
    scanf("%[^\n]", email.body);

    int num_attachments = 0;
    char attachment[MAX_SUBJECT_LENGTH+1];
    while (num_attachments < MAX_ATTACHMENTS && scanf(" %[^\n]", attachment)!= EOF) {
        strcpy(email.attachments[num_attachments], attachment);
        num_attachments++;
    }

    email.num_recipients = num_recipients;
    email.num_attachments = num_attachments;

    read_email(&email);

    return 0;
}
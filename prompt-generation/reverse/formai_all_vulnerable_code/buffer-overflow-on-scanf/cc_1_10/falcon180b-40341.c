//Falcon-180B DATASET v1.0 Category: Email Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_SIZE 1000
#define MAX_SUBJECT_SIZE 100

typedef struct {
    char from[MAX_EMAIL_SIZE];
    char to[MAX_EMAIL_SIZE];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_EMAIL_SIZE];
} Email;

void send_email(Email *email) {
    printf("Sending email from %s to %s with subject %s:\n%s\n", email->from, email->to, email->subject, email->body);
}

void read_emails(Email emails[], int num_emails) {
    for (int i = 0; i < num_emails; i++) {
        printf("Email #%d:\n", i+1);
        printf("From: %s\n", emails[i].from);
        printf("To: %s\n", emails[i].to);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body:\n%s\n", emails[i].body);
    }
}

int main() {
    Email emails[10];
    int num_emails = 0;

    while (num_emails < 10) {
        printf("Enter the sender's email address: ");
        scanf("%s", emails[num_emails].from);

        printf("Enter the recipient's email address: ");
        scanf("%s", emails[num_emails].to);

        printf("Enter the subject: ");
        scanf("%s", emails[num_emails].subject);

        printf("Enter the body of the email: ");
        scanf("%s", emails[num_emails].body);

        num_emails++;
    }

    printf("You have %d emails in your inbox.\n", num_emails);

    for (int i = 0; i < num_emails; i++) {
        send_email(&emails[i]);
    }

    return 0;
}
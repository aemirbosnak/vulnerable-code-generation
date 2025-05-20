//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_RECIPIENTS 10
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000

typedef struct {
    char sender[MAX_RECIPIENTS];
    char recipients[MAX_RECIPIENTS];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
} Email;

void read_email(Email *email) {
    printf("Enter sender: ");
    scanf("%s", email->sender);
    printf("Enter recipients (separated by spaces): ");
    scanf("%s", email->recipients);
    printf("Enter subject: ");
    scanf("%s", email->subject);
    printf("Enter body: ");
    scanf("%s", email->body);
}

void send_email(Email *email) {
    printf("Sending email...\n");
    printf("Sender: %s\n", email->sender);
    printf("Recipients: %s\n", email->recipients);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
}

int main() {
    Email emails[MAX_EMAILS];
    int num_emails;

    printf("Enter the number of emails: ");
    scanf("%d", &num_emails);

    for (int i = 0; i < num_emails; i++) {
        read_email(&emails[i]);
    }

    for (int i = 0; i < num_emails; i++) {
        send_email(&emails[i]);
    }

    return 0;
}
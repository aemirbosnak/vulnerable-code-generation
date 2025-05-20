//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: light-weight
/*
 * email_client.c
 *
 * A simple email client program written in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_EMAIL_LENGTH 1024

typedef struct {
    char* from;
    char* to;
    char* subject;
    char* message;
} Email;

void send_email(Email* email) {
    printf("Sending email to %s...\n", email->to);
    printf("From: %s\n", email->from);
    printf("Subject: %s\n", email->subject);
    printf("Message: %s\n", email->message);
}

void receive_email(Email* email) {
    printf("Received email from %s...\n", email->from);
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Message: %s\n", email->message);
}

int main() {
    Email email;
    char line[MAX_LINE_LENGTH];

    printf("Enter email sender: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    email.from = strdup(line);

    printf("Enter email recipient: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    email.to = strdup(line);

    printf("Enter email subject: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    email.subject = strdup(line);

    printf("Enter email message: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    email.message = strdup(line);

    send_email(&email);
    receive_email(&email);

    return 0;
}
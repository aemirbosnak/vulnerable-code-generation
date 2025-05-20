//Falcon-180B DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_EMAIL_LENGTH 50
#define MAX_SUBJECT_LENGTH 100

// Struct to hold email information
typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_LINE_LENGTH];
} Email;

// Function to read in an email from the user
void read_email(Email* email) {
    printf("From: ");
    scanf("%s", email->from);

    printf("To: ");
    scanf("%s", email->to);

    printf("Subject: ");
    scanf("%s", email->subject);

    printf("Body: ");
    fgets(email->body, MAX_LINE_LENGTH, stdin);

    // Remove newline character from the end of the body
    email->body[strcspn(email->body, "\n")] = '\0';
}

// Function to send an email
void send_email(Email* email) {
    printf("Sending email from %s to %s with subject %s:\n%s\n", email->from, email->to, email->subject, email->body);
}

// Function to read in multiple emails from the user
void read_emails(Email* emails, int num_emails) {
    for (int i = 0; i < num_emails; i++) {
        read_email(&emails[i]);
    }
}

// Function to send multiple emails
void send_emails(Email* emails, int num_emails) {
    for (int i = 0; i < num_emails; i++) {
        send_email(&emails[i]);
    }
}

int main() {
    // Prompt the user for the number of emails they want to send
    int num_emails;
    printf("How many emails do you want to send? ");
    scanf("%d", &num_emails);

    // Allocate memory for the emails
    Email* emails = (Email*) malloc(num_emails * sizeof(Email));

    // Read in the emails from the user
    read_emails(emails, num_emails);

    // Send the emails
    send_emails(emails, num_emails);

    // Free the memory used for the emails
    free(emails);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Email Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAIL_LENGTH 1024

// Struct to hold email data
typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];
    time_t timestamp;
} Email;

// Function to send email
void send_email(Email *email) {
    printf("Sending email from %s to %s with subject %s\n", email->from, email->to, email->subject);
    printf("Body:\n%s\n", email->body);
}

// Function to receive email
Email receive_email() {
    Email email;
    printf("Enter sender email address: ");
    scanf("%s", email.from);
    printf("Enter recipient email address: ");
    scanf("%s", email.to);
    printf("Enter email subject: ");
    scanf("%s", email.subject);
    printf("Enter email body: ");
    fgets(email.body, MAX_EMAIL_LENGTH, stdin);
    email.timestamp = time(NULL);
    return email;
}

// Function to display list of emails
void display_emails(Email *emails, int num_emails) {
    printf("List of emails:\n");
    for (int i = 0; i < num_emails; i++) {
        send_email(&emails[i]);
    }
}

// Main function
int main() {
    Email emails[MAX_EMAIL_LENGTH];
    int num_emails = 0;

    // Loop to receive and store emails
    while (1) {
        Email new_email = receive_email();
        strcpy(emails[num_emails].from, new_email.from);
        strcpy(emails[num_emails].to, new_email.to);
        strcpy(emails[num_emails].subject, new_email.subject);
        strcpy(emails[num_emails].body, new_email.body);
        num_emails++;
        if (num_emails >= MAX_EMAIL_LENGTH) {
            break;
        }
    }

    // Display list of emails
    display_emails(emails, num_emails);

    return 0;
}
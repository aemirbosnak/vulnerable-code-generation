//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: creative
// Unique C Email Client Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct {
    char from[50];
    char to[50];
    char subject[50];
    char body[100];
} Email;

void send_email(Email email) {
    printf("Sending email from %s to %s with subject %s and body %s\n", email.from, email.to, email.subject, email.body);
}

int main() {
    Email emails[MAX_EMAILS];
    int num_emails = 0;

    // Prompt user to enter email information
    printf("Enter email information (type 'exit' to quit):\n");
    while (num_emails < MAX_EMAILS) {
        printf("From: ");
        scanf("%s", emails[num_emails].from);
        printf("To: ");
        scanf("%s", emails[num_emails].to);
        printf("Subject: ");
        scanf("%s", emails[num_emails].subject);
        printf("Body: ");
        scanf("%s", emails[num_emails].body);

        // Check if user wants to quit
        char quit;
        printf("Do you want to quit (y/n)? ");
        scanf("%s", &quit);
        if (quit == 'y') {
            break;
        }

        // Increment number of emails
        num_emails++;
    }

    // Send emails
    for (int i = 0; i < num_emails; i++) {
        send_email(emails[i]);
    }

    return 0;
}
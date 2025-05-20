//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAIL_SIZE 1024
#define MAX_SUBJECT_SIZE 128
#define MAX_RECIPIENTS 10

typedef struct email {
    char sender[128];
    char recipients[MAX_RECIPIENTS][128];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_EMAIL_SIZE];
    time_t timestamp;
} email;

int main() {
    // Declare the email struct
    email email;

    // Get the sender's email address
    printf("Enter your email address: ");
    scanf("%s", email.sender);

    // Get the recipient's email addresses
    printf("Enter the email addresses of the recipients (up to %d): ", MAX_RECIPIENTS);
    for (int i = 0; i < MAX_RECIPIENTS; i++) {
        scanf("%s", email.recipients[i]);
    }

    // Get the subject of the email
    printf("Enter the subject of the email: ");
    scanf("%s", email.subject);

    // Get the body of the email
    printf("Enter the body of the email: ");
    scanf("%s", email.body);

    // Get the current timestamp
    email.timestamp = time(NULL);

    // Print the email
    printf("From: %s\n", email.sender);
    printf("To: %s\n", email.recipients[0]);
    printf("Subject: %s\n", email.subject);
    printf("Body: %s\n", email.body);
    printf("Timestamp: %s\n", ctime(&email.timestamp));

    return 0;
}
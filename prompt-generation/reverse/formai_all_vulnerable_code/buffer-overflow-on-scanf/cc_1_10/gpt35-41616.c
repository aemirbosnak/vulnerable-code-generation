//FormAI DATASET v1.0 Category: Email Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 1000
#define MAX_ADDR_LEN 100
#define MAX_SUBJECT_LEN 100

typedef struct {
    char from[MAX_ADDR_LEN];
    char to[MAX_ADDR_LEN];
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MSG_LEN];
} Email;

int main() {
    Email email;

    // Configure email settings
    printf("Enter your email address: ");
    scanf("%s", email.from);

    printf("Enter recipient's email address: ");
    scanf("%s", email.to);

    printf("Enter email subject: ");
    scanf("%s", email.subject);

    // Compose email
    printf("Enter email message:\n");
    getchar(); // clear buffer
    fgets(email.message, MAX_MSG_LEN, stdin);

    // Send email
    printf("\nSending email...\n");
    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Message: %s\n", email.message);

    // Clear message buffer
    memset(email.message, 0, sizeof(email.message));

    // Receive email
    printf("\nChecking for new email...\n");

    // Simulate receiving email (for demo purposes only)
    strncpy(email.from, "johndoe@example.com", MAX_ADDR_LEN);
    strncpy(email.subject, "Hello from John Doe", MAX_SUBJECT_LEN);
    strncpy(email.message, "This is a test email.", MAX_MSG_LEN);

    printf("New email received:\n");
    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Message: %s\n", email.message);

    return 0;
}
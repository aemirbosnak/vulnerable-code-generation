//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

void send_email(Email email);
void display_email(Email email);
void prompt_user_for_email(Email *email);

int main() {
    Email emails[MAX_EMAILS];
    int email_count = 0;
    char choice;

    printf("Welcome to Email Client!\n");

    do {
        // Prompt user for email details
        if (email_count < MAX_EMAILS) {
            Email email;
            prompt_user_for_email(&email);
            emails[email_count++] = email;

            // Send the email (just print it for this example)
            send_email(email);
        } else {
            printf("Email limit reached! Cannot send more emails.\n");
            break;
        }

        printf("Would you like to send another email? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using Email Client. Goodbye!\n");

    return 0;
}

void prompt_user_for_email(Email *email) {
    printf("Enter your email address: ");
    scanf("%s", email->from);
    
    printf("Enter recipient's email address: ");
    scanf("%s", email->to);
    
    printf("Enter the subject: ");
    scanf(" %[^\n]", email->subject); // allows spaces in subject
    
    printf("Enter the email body (max %d characters):\n", MAX_BODY_LENGTH);
    scanf(" %[^\n]", email->body); // allows spaces in body
}

void send_email(Email email) {
    printf("\nSending Email...\n");
    display_email(email);
    printf("Email sent successfully!\n\n");
}

void display_email(Email email) {
    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s\n", email.body);
}
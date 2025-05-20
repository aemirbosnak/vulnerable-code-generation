//FormAI DATASET v1.0 Category: Email Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct definition to hold email message contents
typedef struct email_message {
    char from[50];
    char to[50];
    char subject[100];
    char body[1000];
} email_message;

// Function to send email message
void send_email(email_message* message) {
    printf("Sending email to %s from %s with subject: %s\n", message->to, message->from, message->subject);
    printf("Email body: %s\n", message->body);
    // Code here to actually send email
}

// Main program entry point
int main() {
    char choice;
    email_message* message = (email_message*)malloc(sizeof(email_message));
    
    // Prompt user for email message contents
    printf("Enter email from: ");
    scanf("%s", message->from);
    printf("Enter email to: ");
    scanf("%s", message->to);
    printf("Enter email subject: ");
    scanf("%s", message->subject);
    printf("Enter email body: ");
    scanf("%s", message->body);
    
    // Prompt user to confirm email details
    printf("Are the following email details correct?(Y/N)\n");
    printf("From: %s\n", message->from);
    printf("To: %s\n", message->to);
    printf("Subject: %s\n", message->subject);
    printf("Body: %s\n", message->body);
    scanf(" %c", &choice);
    
    // If user confirms email details, send the email
    if (choice == 'Y' || choice == 'y') {
        send_email(message);
        printf("Email sent!\n");
    }
    else {
        printf("Email cancelled.\n");
    }

    free(message);
    return 0;
}
//FormAI DATASET v1.0 Category: Email Client ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUFFER 512
#define MAX_SUBJECT 64
#define MAX_SENDER 64
#define MAX_RECEIVER 64
#define MAX_MESSAGE 2048

struct Email {
    char sender[MAX_SENDER];
    char receiver[MAX_RECEIVER];
    char subject[MAX_SUBJECT];
    char message[MAX_MESSAGE];
};

void sendEmail(struct Email* email) {
    printf("\n\nSending Email...\n");
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->receiver);
    printf("Subject: %s\n", email->subject);
    printf("Message: %s\n", email->message);
}

int main() {
    char buffer[MAX_BUFFER];
    struct Email email;
    
    // Get sender email address
    printf("Enter your email address: ");
    fgets(buffer, MAX_BUFFER, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    strcpy(email.sender, buffer);
    
    // Get receiver email address
    printf("Enter receiver's email address: ");
    fgets(buffer, MAX_BUFFER, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    strcpy(email.receiver, buffer);
    
    // Get email subject
    printf("Enter email subject: ");
    fgets(buffer, MAX_BUFFER, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    strcpy(email.subject, buffer);
    
    // Get email message
    printf("Enter email message:\n");
    fgets(buffer, MAX_BUFFER, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    strcpy(email.message, buffer);
    
    sendEmail(&email);
    
    return 0;
}
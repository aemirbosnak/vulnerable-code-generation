//FormAI DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold email details
typedef struct EMail {
    char sender[50];
    char receiver[50];
    char subject[100];
    char body[1000];
} EMail;

// function to send email
void sendEmail(EMail *email) {
    printf("\nSending Email...\n");
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->receiver);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
    printf("Email Sent Successfully!\n");
}

int main() {
    printf("Welcome to the Email Client!\n");

    EMail email; // create email struct

    // get sender details
    printf("\nEnter Sender Details:\n");
    printf("Sender Name: ");
    scanf("%s", email.sender);
    printf("Sender Email Address: ");
    scanf("%s", email.sender);

    // get receiver details
    printf("\nEnter Receiver Details:\n");
    printf("Receiver Name: ");
    scanf("%s", email.receiver);
    printf("Receiver Email Address: ");
    scanf("%s", email.receiver);

    // get email subject and body
    printf("\nEnter Email Subject: ");
    scanf("%s", email.subject);
    printf("Enter Email Body: ");
    scanf("%s", email.body);

    // send email
    sendEmail(&email);

    printf("\nExiting Email Client...\n");
    return 0;
}
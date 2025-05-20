//FormAI DATASET v1.0 Category: Email Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_ATTACHMENTS 5
#define MAX_ATTACHMENT_NAME_LENGTH 50

// Struct for Email Messages
typedef struct {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char attachments[MAX_ATTACHMENTS][MAX_ATTACHMENT_NAME_LENGTH];
    int attachment_count;
} Email;

// Function to send email
void send_email(Email *email) {
    // Code to send email goes here
    printf("Email Sent!\n");
}

int main() {
    // Variables to store user input
    char sender[50], recipient[50], subject[MAX_SUBJECT_LENGTH], body[MAX_BODY_LENGTH];
    char attachment_names[MAX_ATTACHMENTS][MAX_ATTACHMENT_NAME_LENGTH];
    int attachment_count = 0;

    // Ask user to enter sender, recipient, subject and body of email
    printf("Enter Sender: ");
    scanf("%s", sender);
    printf("Enter Recipient: ");
    scanf("%s", recipient);
    printf("Enter Subject: ");
    getchar(); // discard newline character
    fgets(subject, MAX_SUBJECT_LENGTH, stdin);
    printf("Enter Body: ");
    fgets(body, MAX_BODY_LENGTH, stdin);

    // Ask user if they want to add any attachments
    char answer;
    printf("Do you want to add any attachments? (y/n) ");
    scanf("%c", &answer);
    if (answer == 'y') {
        do {
            printf("Enter Attachment %d Name: ", attachment_count+1);
            getchar(); // discard newline character
            fgets(attachment_names[attachment_count], MAX_ATTACHMENT_NAME_LENGTH, stdin);
            attachment_count++;
            if (attachment_count == MAX_ATTACHMENTS) {
                printf("Maximum number of attachments reached!\n");
                break;
            }
            printf("Do you want to add another attachment? (y/n) ");
            scanf("%c", &answer);
        } while (answer == 'y');
    }

    // Create Email Object
    Email email = {
        .sender = sender,
        .recipient = recipient,
        .attachment_count = attachment_count
    };
    strcpy(email.subject, subject);
    strcpy(email.body, body);
    for (int i = 0; i < attachment_count; i++) {
        strcpy(email.attachments[i], attachment_names[i]);
    }

    // Send Email
    send_email(&email);

    return 0;
}
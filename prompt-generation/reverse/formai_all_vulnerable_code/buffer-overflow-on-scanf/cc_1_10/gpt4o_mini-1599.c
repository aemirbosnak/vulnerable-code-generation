//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 10
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500
#define MAX_NAME_LENGTH 50

typedef struct {
    char sender[MAX_NAME_LENGTH];
    char receiver[MAX_NAME_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

void sendEmail(Email email) {
    printf("Sending email from: %s\n", email.sender);
    printf("To: %s\n", email.receiver);
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s\n", email.body);
    printf("Email sent! Or is it? 🕵️‍♂️\n");
}

void printEmails(Email emails[], int count) {
    printf("You have got mail! 📬 (or maybe just a bunch of spam)\n");
    for (int i = 0; i < count; i++) {
        printf("Email #%d:\n", i + 1);
        printf("From: %s\n", emails[i].sender);
        printf("To: %s\n", emails[i].receiver);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body:\n%s\n", emails[i].body);
        printf("-------------------------------------\n");
    }
}

void composeEmail(Email *email) {
    printf("Composing a new email! 🖊️\n");
    
    printf("Enter sender's name: ");
    fgets(email->sender, MAX_NAME_LENGTH, stdin);
    email->sender[strcspn(email->sender, "\n")] = 0; // Remove newline

    printf("Enter receiver's name: ");
    fgets(email->receiver, MAX_NAME_LENGTH, stdin);
    email->receiver[strcspn(email->receiver, "\n")] = 0; // Remove newline

    printf("Enter subject: ");
    fgets(email->subject, MAX_SUBJECT_LENGTH, stdin);
    email->subject[strcspn(email->subject, "\n")] = 0; // Remove newline

    printf("Enter body (type 'end' to finish):\n");
    if (fgets(email->body, MAX_BODY_LENGTH, stdin) != NULL) {
        char buffer[500]; // Temporary buffer for multi-line input
        int length = strlen(email->body);
        // Continue getting input until 'end' is encountered
        while (strncmp(email->body, "end", 3) != 0) {
            strcat(email->body + length, buffer); // Append new body content
            length += strlen(buffer);
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) break; // Break on error
        }
        email->body[length - 1] = '\0'; // Remove the last 'end' line
    }
}

int main() {
    Email inbox[MAX_EMAILS];
    int emailCount = 0;

    printf("Welcome to the Comedy Email Client! 🎉\n");
    
    while (1) {
        printf("Choose an option:\n");
        printf("1. Compose a new email\n");
        printf("2. View inbox\n");
        printf("3. Quit (Or run away forever!)\n");
        printf("Your choice: ");
        
        int choice;
        scanf("%d", &choice);
        getchar(); // Clear the newline left in buffer
        
        switch (choice) {
            case 1:
                if (emailCount < MAX_EMAILS) {
                    composeEmail(&inbox[emailCount]);
                    sendEmail(inbox[emailCount]);
                    emailCount++;
                } else {
                    printf("Oops! Your inbox is full. You might want to delete some junk! 🙄\n");
                }
                break;
            case 2:
                printEmails(inbox, emailCount);
                break;
            case 3:
                printf("Quitting the email client. May your inbox always stay empty! 😄\n");
                exit(0);
            default:
                printf("That’s not an option! Try again or laugh it off! 😂\n");
        }
    }

    return 0;
}
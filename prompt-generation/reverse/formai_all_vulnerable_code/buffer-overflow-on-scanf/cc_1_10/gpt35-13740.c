//FormAI DATASET v1.0 Category: Email Client ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMAILS 100 // maximum number of emails that can be stored
#define MAX_EMAIL_LENGTH 256 // maximum length of each email

typedef struct {
    char sender[MAX_EMAIL_LENGTH];
    char receiver[MAX_EMAIL_LENGTH];
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];
} Email;

int numEmails = 0; // number of emails stored

Email emails[MAX_EMAILS]; // array of emails

void sendEmail(char *sender, char *receiver, char *subject, char *body) {
    if (numEmails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails exceeded.\n");
        return;
    }

    Email newEmail; // create a new email

    strcpy(newEmail.sender, sender); // set the sender field
    strcpy(newEmail.receiver, receiver); // set the receiver field
    strcpy(newEmail.subject, subject); // set the subject field
    strcpy(newEmail.body, body); // set the body field

    emails[numEmails] = newEmail; // add the new email to the array

    numEmails++; // increase the number of emails stored

    printf("Email sent successfully!\n");
}

void printEmail(Email email) {
    printf("From: %s\n", email.sender); // print sender
    printf("To: %s\n", email.receiver); // print receiver
    printf("Subject: %s\n", email.subject); // print subject
    printf("Body: %s\n", email.body); // print body
}

void viewEmails() {
    if (numEmails == 0) {
        printf("No emails found.\n");
        return;
    }

    printf("List of Emails:\n");

    for (int i = 0; i < numEmails; i++) {
        printf("Email %d:\n", i+1); // print the email number

        printEmail(emails[i]); // print the email details
    }
}

int main() {
    int choice;

    do {
        printf("\n1) Send an email\n");
        printf("2) View all emails\n");
        printf("3) Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char sender[MAX_EMAIL_LENGTH];
                char receiver[MAX_EMAIL_LENGTH];
                char subject[MAX_EMAIL_LENGTH];
                char body[MAX_EMAIL_LENGTH];

                printf("Enter sender: ");
                scanf("%s", sender);

                printf("Enter receiver: ");
                scanf("%s", receiver);

                printf("Enter subject: ");
                scanf("%s", subject);

                printf("Enter body: ");
                scanf("%s", body);

                sendEmail(sender, receiver, subject, body);

                break;
            }

            case 2: {
                viewEmails();

                break;
            }

            case 3: {
                printf("Exiting program.\n");

                break;
            }

            default: {
                printf("Invalid choice.\n");

                break;
            }
        }
    } while (choice != 3);

    return 0;
}
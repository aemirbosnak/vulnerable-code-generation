//FormAI DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_EMAILS 100

typedef struct Email {
    char sender[30];
    char recipient[30];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int numEmails = 0;

void sendEmail(char* sender, char* recipient, char* subject, char* body) {
    if(numEmails >= MAX_EMAILS) {
        printf("Max number of emails reached, cannot send.\n");
        return;
    }

    Email newEmail;
    strcpy(newEmail.sender, sender);
    strcpy(newEmail.recipient, recipient);
    strcpy(newEmail.subject, subject);
    strcpy(newEmail.body, body);

    emails[numEmails] = newEmail;
    numEmails++;

    printf("Email sent successfully to %s!\n", recipient);
}

void checkInbox(char* recipient) {
    printf("Checking inbox for %s...\n", recipient);

    for(int i = 0; i < numEmails; i++) {
        if(strcmp(emails[i].recipient, recipient) == 0) {
            printf("************************************\n");
            printf("Sender: %s\n", emails[i].sender);
            printf("Subject: %s\n", emails[i].subject);
            printf("Body: %s\n", emails[i].body);
            printf("************************************\n");
        }
    }

    printf("End of inbox for %s.\n", recipient);
}

int main() {
    printf("Welcome to our unique C Email Client!\n");

    while(1) {
        printf("What would you like to do?\n");
        printf("1. Send an email\n");
        printf("2. Check inbox\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                    char sender[30], recipient[30], subject[MAX_SUBJECT_LENGTH], body[MAX_BODY_LENGTH];

                    printf("Enter sender email: ");
                    scanf("%s", sender);

                    printf("Enter recipient email: ");
                    scanf("%s", recipient);

                    printf("Enter email subject: ");
                    scanf(" %[^\n]", subject);

                    printf("Enter email body: ");
                    scanf(" %[^\n]", body);

                    sendEmail(sender, recipient, subject, body);
                    break;
                }
            
            case 2:
                {
                    char recipient[30];

                    printf("Enter recipient email: ");
                    scanf("%s", recipient);

                    checkInbox(recipient);
                    break;
                }

            case 3:
                printf("Thank you for using our unique C Email Client!\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
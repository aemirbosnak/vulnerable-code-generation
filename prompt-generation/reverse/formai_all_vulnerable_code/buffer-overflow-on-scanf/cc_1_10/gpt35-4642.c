//FormAI DATASET v1.0 Category: Email Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NUM_EMAILS 100 // Maximum number of emails that can be stored
#define MAX_EMAIL_LEN 256 // Maximum length of an email

typedef struct {
    char to[MAX_EMAIL_LEN]; // recipient email address
    char from[MAX_EMAIL_LEN]; // sender email address
    char subject[MAX_EMAIL_LEN]; // email subject
    char body[MAX_EMAIL_LEN]; // email body text
} Email;

Email emails[MAX_NUM_EMAILS]; // array to store all emails
int numEmails = 0; // current number of emails stored

// function to add a new email to the array
void addEmail(char* to, char* from, char* subject, char* body) {
    if (numEmails < MAX_NUM_EMAILS) {
        strcpy(emails[numEmails].to, to);
        strcpy(emails[numEmails].from, from);
        strcpy(emails[numEmails].subject, subject);
        strcpy(emails[numEmails].body, body);
        numEmails++;
    }
    else {
        printf("Maximum number of emails reached!\n");
    }
}

// function to print all emails in the array
void printEmails() {
    int i;
    for (i = 0; i < numEmails; i++) {
        printf("To: %s\n", emails[i].to);
        printf("From: %s\n", emails[i].from);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n\n", emails[i].body);
    }
}

int main() {
    int option;
    bool quit = false;

    while (!quit) {
        printf("\nEmail Client Options:\n");
        printf("1. Compose new email\n");
        printf("2. View all emails\n");
        printf("3. Quit\n");
        printf("Enter option number: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter recipient email address: ");
                char to[MAX_EMAIL_LEN];
                scanf("%s", to);

                printf("Enter sender email address: ");
                char from[MAX_EMAIL_LEN];
                scanf("%s", from);

                printf("Enter email subject: ");
                char subject[MAX_EMAIL_LEN];
                scanf("%s", subject);

                printf("Enter email body text: ");
                char body[MAX_EMAIL_LEN];
                scanf("%s", body);

                addEmail(to, from, subject, body);
                printf("Email added!\n");
                break;

            case 2:
                printf("\nAll Emails:\n");
                printEmails();
                break;

            case 3:
                quit = true;
                break;

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}
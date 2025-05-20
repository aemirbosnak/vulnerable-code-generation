//FormAI DATASET v1.0 Category: Email Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 200
#define MAX_EMAIL_LENGTH 60
#define MAX_NAME_LENGTH 50

typedef struct {
    char sender[MAX_EMAIL_LENGTH];
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

typedef struct {
    int count;
    Email messages[MAX_MESSAGES];
} EmailList;

int main() {
    int choice = 0;
    EmailList inbox = {0};
    EmailList sent = {0};

    while (choice != 5) {
        printf("\nWelcome to Brave Email Client!\n");
        printf("\n1. Compose Email");
        printf("\n2. Check Inbox");
        printf("\n3. Check Sent");
        printf("\n4. Delete Inbox");
        printf("\n5. Quit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Email new_email;
                printf("\nTo: ");
                scanf("%s", new_email.recipient);
                printf("Subject: ");
                scanf("%s", new_email.subject);
                printf("Body: ");
                scanf("%s", new_email.body);
                printf("From: ");
                scanf("%s", new_email.sender);
                sent.messages[sent.count++] = new_email;
                printf("\nEmail sent!\n");
                break;
            }

            case 2: {
                printf("\n------------------------------------------------------------------------\n");
                printf("                                   INBOX\n");
                printf("------------------------------------------------------------------------\n");
                int i;
                for (i = 0; i < inbox.count; ++i) {
                    printf("\nFrom: %s", inbox.messages[i].sender);
                    printf("\nSubject: %s", inbox.messages[i].subject);
                    printf("\nBody: %s", inbox.messages[i].body);
                    printf("\n------------------------------------------------------------------------\n");
                }
                break;
            }

            case 3: {
                printf("\n------------------------------------------------------------------------\n");
                printf("                                   SENT\n");
                printf("------------------------------------------------------------------------\n");
                int i;
                for (i = 0; i < sent.count; ++i) {
                    printf("\nTo: %s", sent.messages[i].recipient);
                    printf("\nSubject: %s", sent.messages[i].subject);
                    printf("\nBody: %s", sent.messages[i].body);
                    printf("\n------------------------------------------------------------------------\n");
                }
                break;
            }

            case 4: {
                inbox.count = 0;
                printf("\nInbox deleted!\n");
                break;
            }

            case 5: {
                printf("\nGoodbye!\n");
                break;
            }

            default: {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 200

typedef struct {
    char sender[20];
    char receiver[20];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} email_t;

int main() {
    email_t inbox[MAX_EMAILS];
    int num_emails = 0;
    char choice;

    printf("\nWelcome to HappyMail!\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("1) Compose a new email\n");
        printf("2) View inbox\n");
        printf("3) Exit\n");

        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("\nCompose new email:\n");

                email_t new_email;

                printf("From: ");
                scanf("%s", new_email.sender);

                printf("To: ");
                scanf("%s", new_email.receiver);

                printf("Subject (max %d characters): ", MAX_SUBJECT_LENGTH);
                scanf("%s", new_email.subject);

                printf("Body (max %d characters): ", MAX_BODY_LENGTH);
                scanf(" %[^\n]s", new_email.body);

                inbox[num_emails++] = new_email;

                printf("\nEmail sent! :)\n");

                break;
            case '2':
                if (num_emails == 0) {
                    printf("\nYour inbox is empty :(\n");
                } else {
                    printf("\nInbox:\n");

                    for (int i = 0; i < num_emails; i++) {
                        printf("\nEmail #%d\n", i + 1);
                        printf("From: %s\n", inbox[i].sender);
                        printf("To: %s\n", inbox[i].receiver);
                        printf("Subject: %s\n", inbox[i].subject);
                        printf("Body: %s\n", inbox[i].body);
                    }
                }

                break;
            case '3':
                printf("\nThank you for using HappyMail! Have a nice day :) \n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != '3');

    return 0;
}
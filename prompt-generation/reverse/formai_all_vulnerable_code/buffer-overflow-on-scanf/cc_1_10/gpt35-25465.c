//FormAI DATASET v1.0 Category: Email Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT 50
#define MAX_MESSAGE 1000
#define MAX_EMAILS 100

struct Email {
    char subject[MAX_SUBJECT];
    char message[MAX_MESSAGE];
    char recipient[MAX_SUBJECT];
};

struct Email inbox[MAX_EMAILS];
int num_emails = 0;

int main() {
    while (1) {
        printf("Welcome to the C Email Client\n");
        printf("1. Compose an Email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            struct Email new_email;
            printf("\nEnter subject: ");
            scanf("%s", new_email.subject);
            printf("Enter message: ");
            scanf("%s", new_email.message);
            printf("Enter recipient: ");
            scanf("%s", new_email.recipient);

            inbox[num_emails] = new_email;
            num_emails++;
            printf("\nEmail sent!\n");
        } else if (choice == 2) {
            if (num_emails == 0) {
                printf("\nInbox is empty.\n");
            } else {
                printf("\n--- Inbox ---\n");
                for (int i = 0; i < num_emails; i++) {
                    printf("From: %s\nSubject: %s\nMessage: %s\n", inbox[i].recipient, inbox[i].subject, inbox[i].message);
                }
            }
        } else if (choice == 3) {
            printf("\nGoodbye!");
            break;
        } else {
            printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}
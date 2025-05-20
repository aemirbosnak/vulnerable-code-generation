//FormAI DATASET v1.0 Category: Email Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define MAX_EMAILS 50

typedef struct Email {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char sender[MAX_SUBJECT_LENGTH];
    char recipient[MAX_SUBJECT_LENGTH];
} Email;

int main() {
    Email emails[MAX_EMAILS];
    int num_emails = 0;

    int choice;
    do {
        printf("\nWelcome to the Email Client!\n");
        printf("Choose an option:\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                if (num_emails >= MAX_EMAILS) {
                    printf("Inbox full! Cannot compose new email.\n");
                    break;
                }

                printf("\nCompose New Email\n");
                Email e;
                printf("From: ");
                scanf("%s", e.sender);

                printf("To: ");
                scanf("%s", e.recipient);

                printf("Subject: ");
                scanf("%s", e.subject);

                printf("Message: ");
                getchar();
                fgets(e.message, MAX_MESSAGE_LENGTH, stdin);

                emails[num_emails++] = e;
                printf("Email sent!\n");

                break;
            }

            case 2: {
                if (num_emails == 0) {
                    printf("Inbox empty!\n");
                    break;
                }

                printf("\nInbox:\n");
                for (int i = 0; i < num_emails; i++) {
                    printf("%d. From: %s\n", i+1, emails[i].sender);
                    printf("   Subject: %s\n", emails[i].subject);
                }

                int email_choice;
                do {
                    printf("\nEnter email number to view (0 to exit): ");
                    scanf("%d", &email_choice);

                    if (email_choice < 0 || email_choice > num_emails) {
                        printf("Invalid email number! Try again.\n");
                    } else if (email_choice != 0) {
                        printf("\nEmail Details:\n");
                        printf("From: %s\n", emails[email_choice-1].sender);
                        printf("To: %s\n", emails[email_choice-1].recipient);
                        printf("Subject: %s\n", emails[email_choice-1].subject);
                        printf("Message: %s\n", emails[email_choice-1].message);
                    }
                } while (email_choice != 0);

                break;
            }

            case 3: {
                printf("Exiting Email Client...\n");
                break;
            }

            default: {
                printf("Invalid choice! Try again.\n");
                break;
            }
        }
    } while (choice != 3);

    return 0;
}
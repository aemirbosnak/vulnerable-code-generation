//FormAI DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMAILS 10
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 1000

typedef struct { 
    char subject[MAX_SUBJECT_LENGTH]; 
    char body[MAX_BODY_LENGTH]; 
    char recipient[MAX_SUBJECT_LENGTH];
} email_t;

int main() {
    email_t inbox[MAX_EMAILS];
    int inboxSize = 0;
    bool isRunning = true;

    while (isRunning) {
        printf("*** POST-APOCALYPTIC EMAIL CLIENT ***\n\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox (%d)\n", inboxSize);
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Compose Email
                email_t email;
                printf("\nCompose Email\n\n");
                printf("Recipient: ");
                scanf("%s", email.recipient);
                printf("\nSubject: ");
                scanf("%s", email.subject);
                printf("\nBody: ");
                scanf("\n%[^\t\n]s", email.body);

                if (inboxSize < MAX_EMAILS) {
                    inbox[inboxSize++] = email;
                } else {
                    printf("\nInbox is full!\n");
                }

                printf("\nEmail sent successfully!\n");
                break;
            }

            case 2: {
                // View Inbox
                printf("\nViewing Inbox\n\n");
                if (inboxSize > 0) {
                    for (int i = 0; i < inboxSize; i++) {
                        printf("%d. From: %s\n", i+1, inbox[i].recipient);
                        printf("   Subject: %s\n", inbox[i].subject);
                        printf("   Message: %s\n\n", inbox[i].body);
                    }
                } else {
                    printf("Inbox is empty!\n");
                }
                break;
            }

            case 3: {
                // Exit
                printf("\nExiting Program\n");
                isRunning = false;
                break;
            }

            default: {
                printf("\nInvalid Choice!\n");
                break;
            }
        }
    }

    return 0;
}
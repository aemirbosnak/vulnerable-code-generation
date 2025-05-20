//FormAI DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 1024
#define MAX_EMAILS 10

typedef struct {
    char sender[MAX_CHARACTERS];
    char subject[MAX_CHARACTERS];
    char content[MAX_CHARACTERS];
} Email;

int main() {
    Email inbox[MAX_EMAILS];
    int numEmails = 0;

    while (1) {
        // Display menu options to user
        printf("Welcome to the Email Client!\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");

        int option;
        scanf("%d", &option);

        switch(option) {
            case 1: // Compose email
                printf("Enter sender address: ");
                char sender[MAX_CHARACTERS];
                scanf("%s", sender);

                printf("Enter email subject: ");
                char subject[MAX_CHARACTERS];
                scanf("%s", subject);

                printf("Enter email content: ");
                char content[MAX_CHARACTERS];
                scanf("%s", content);

                // Save email to inbox
                Email newEmail;
                strcpy(newEmail.sender, sender);
                strcpy(newEmail.subject, subject);
                strcpy(newEmail.content, content);

                inbox[numEmails] = newEmail;
                numEmails++;

                printf("Email saved to inbox successfully!\n");
                break;

            case 2: // View inbox
                if (numEmails == 0) {
                    printf("Inbox is empty.\n");
                } else {
                    printf("Inbox:\n");
                    for (int i = 0; i < numEmails; i++) {
                        printf("Email %d:\n", i+1);
                        printf("Sender: %s\n", inbox[i].sender);
                        printf("Subject: %s\n", inbox[i].subject);
                        printf("Content: %s\n", inbox[i].content);
                    }
                }
                break;

            case 3: // Exit program
                printf("Exiting Email Client. Goodbye!\n");
                exit(0);
                break;

            default: // Invalid option entered
                printf("Invalid option entered. Please try again.\n");
                break;
        }
    }

    return 0;
}
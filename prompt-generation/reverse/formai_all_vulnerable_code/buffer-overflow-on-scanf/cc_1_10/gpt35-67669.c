//FormAI DATASET v1.0 Category: Email Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char sender[MAX_LENGTH];
    char recipient[MAX_LENGTH];
    char subject[MAX_LENGTH];
    char body[MAX_LENGTH];
} Email;

void clearInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Email inbox[10];
    int inboxSize = 0;

    char option;
    do {
        printf("-------------------------------------------------\n");
        printf("Welcome to C Email Client!\n");
        printf("-------------------------------------------------\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Quit\n");
        printf("-------------------------------------------------\n");

        printf("Please enter an option: ");
        scanf(" %c", &option);

        switch(option) {
            case '1': {
                printf("-------------------------------------------------\n");
                printf("Compose Email\n");
                printf("-------------------------------------------------\n");

                Email email;

                clearInput();
                printf("Sender: ");
                fgets(email.sender, MAX_LENGTH, stdin);

                clearInput();
                printf("Recipient: ");
                fgets(email.recipient, MAX_LENGTH, stdin);

                clearInput();
                printf("Subject: ");
                fgets(email.subject, MAX_LENGTH, stdin);

                clearInput();
                printf("Body: ");
                fgets(email.body, MAX_LENGTH, stdin);

                inbox[inboxSize] = email;
                inboxSize++;

                printf("-------------------------------------------------\n");
                printf("Email sent!\n");
                printf("-------------------------------------------------\n");

                break;
            }
            case '2': {
                printf("-------------------------------------------------\n");
                printf("View Inbox\n");
                printf("-------------------------------------------------\n");

                if (inboxSize == 0) {
                    printf("No emails in your inbox. Go ahead and compose one!\n");
                } else {
                    for (int i = 0; i < inboxSize; i++) {
                        printf("Email %d:\n", i+1);
                        printf("\tFrom: %s", inbox[i].sender);
                        printf("\tTo: %s", inbox[i].recipient);
                        printf("\tSubject: %s", inbox[i].subject);
                        printf("\tBody: %s", inbox[i].body);
                    }
                }

                break;
            }
            case '3': {
                printf("-------------------------------------------------\n");
                printf("Goodbye!\n");
                printf("-------------------------------------------------\n");

                break;
            }
            default: {
                printf("-------------------------------------------------\n");
                printf("Invalid option selected.\n");
                printf("-------------------------------------------------\n");

                break;
            }
        }

    } while (option != '3');

    return 0;
}
//FormAI DATASET v1.0 Category: Email Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct email {
    char sender[100];
    char recipient[100];
    char subject[100];
    char message[500];
} Email;

int main() {
    printf("Welcome to our mind-bending C email client!\n");

    Email e1 = {"charles@gmail.com", "john@yahoo.com", "Hello", "Hey, how are you? It's been a while."};

    char userChoice;
    do {
        printf("\nSelect an option:\n");
        printf("1. Compose an email\n");
        printf("2. View received email\n");
        printf("3. Exit\n");
        printf("> ");
        scanf(" %c", &userChoice);

        switch(userChoice) {
            case '1': {
                Email newEmail;
                printf("\n---- Compose an email ----\n");

                printf("Enter recipient email: ");
                scanf("%s", newEmail.recipient);

                printf("Enter subject: ");
                scanf("%s", newEmail.subject);

                printf("Enter message: ");
                scanf("%s", newEmail.message);

                printf("\nEmail sent to %s with subject \"%s\" and message \"%s\"\n", newEmail.recipient, newEmail.subject, newEmail.message);
                break;
            }

            case '2': {
                printf("\n---- Inbox ----\n");
                printf("You have 1 new email!\n");

                printf("Sender: %s\n", e1.sender);
                printf("Subject: %s\n", e1.subject);
                printf("Message: %s\n", e1.message);
                break;
            }

            case '3': {
                printf("\nBye bye, have a great day!\n");
                exit(0);
            }

            default: {
                printf("Invalid option. Please try again.\n");
                break;
            }
        }
    } while(userChoice != '3');

    return 0;
}
//FormAI DATASET v1.0 Category: Email Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_EMAIL_LENGTH 256

typedef struct {
    char message[MAX_MESSAGE_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char sender[MAX_EMAIL_LENGTH];
    char recipient[MAX_EMAIL_LENGTH];
} Email;

int main() {
    Email email;
    char input[MAX_MESSAGE_LENGTH];
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char sender[MAX_EMAIL_LENGTH];
    char temp[MAX_SUBJECT_LENGTH];
    int option = 0;

    printf("Welcome to my C Email Client!\n\n");

    printf("Please enter your email address: ");
    scanf("%s", sender);

    printf("\nPlease enter your email password: ");
    scanf("%s", temp);

    printf("\nWelcome %s! What would you like to do?\n", sender);
    printf("Enter 1 to send an email\n");
    printf("Enter 2 to view your inbox\n");
    printf("Enter 3 to exit\n");

    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("\nCompose your email here:\n");

            printf("Enter recipient email address: ");
            scanf("%s", recipient);
            strcpy(email.recipient, recipient);

            printf("\nEnter your subject: ");
            scanf("%s", subject);
            strcpy(email.subject, subject);

            printf("\nEnter your message: \n");
            getchar(); // Remove newline character from input buffer
            fgets(input, MAX_MESSAGE_LENGTH, stdin); // Get message input
            strcpy(email.message, input);

            strcpy(email.sender, sender);

            printf("\nMessage sent!\n");
            break;

        case 2:
            printf("\nWelcome to your inbox,\n");
            printf("\nSorry there are no messages to display at this time.\n");
            break;

        case 3:
            printf("\nGoodbye!\n");
            exit(0);
            break;

        default:
            printf("\nInvalid option selected.\n");
            break;
    }

    return 0;
}
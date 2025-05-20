//Falcon-180B DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECTS 100
#define MAX_SENDERS 100
#define MAX_RECIPIENTS 100
#define MAX_BODY 1000
#define MAX_ATTACHMENTS 10

typedef struct {
    char subject[MAX_SUBJECTS];
    char sender[MAX_SENDERS];
    char recipients[MAX_RECIPIENTS];
    char body[MAX_BODY];
    char attachments[MAX_ATTACHMENTS][MAX_ATTACHMENTS];
} Email;

int main() {
    Email email;
    int choice;

    do {
        printf("Welcome to the Happy Email Client!\n");
        printf("What would you like to do?\n");
        printf("1. Create a new email\n");
        printf("2. Read emails\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Creating a new email...\n");
                printf("Enter the subject: ");
                scanf("%s", email.subject);
                printf("Enter the sender: ");
                scanf("%s", email.sender);
                printf("Enter the recipients (comma-separated): ");
                scanf("%s", email.recipients);
                printf("Enter the body: ");
                fgets(email.body, MAX_BODY, stdin);
                printf("Enter the attachments (comma-separated): ");
                scanf("%s", email.attachments[0]);
                break;
            case 2:
                printf("Reading emails...\n");
                printf("You have %d unread emails.\n", 0); // TODO: Implement email reading
                break;
            case 3:
                printf("Exiting the Happy Email Client...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 3);

    return 0;
}
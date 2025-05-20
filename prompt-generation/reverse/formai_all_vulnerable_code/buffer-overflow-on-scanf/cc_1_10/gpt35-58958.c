//FormAI DATASET v1.0 Category: Email Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_EMAILS 100

typedef struct {
    char subject[MAX_SUBJECT_LENGTH], body[MAX_BODY_LENGTH], to[30];
} Email;

int main() {
    Email unreads[MAX_EMAILS], sent[MAX_EMAILS];
    int numUnreads = 0, numSent = 0, choice = 0;
    char to[30], subject[MAX_SUBJECT_LENGTH], body[MAX_BODY_LENGTH];
    bool running = true;

    printf("Welcome to the C Email Client!\n\n");

    while(running) {
        printf("What would you like to do?\n");
        printf("1. Compose email\n");
        printf("2. View unread emails\n");
        printf("3. View sent emails\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar(); // To consume the trailing newline character

        switch(choice) {
            case 1:
                printf("\nEnter recipient's email address: ");
                fgets(to, 30, stdin);
                printf("\nEnter subject: ");
                fgets(subject, MAX_SUBJECT_LENGTH, stdin);
                printf("\nEnter body: ");
                fgets(body, MAX_BODY_LENGTH, stdin);

                // Create a new email and add it to the sent folder
                Email newEmail = {0};
                strncpy(newEmail.to, to, strlen(to)-1); // Removing the newline character
                strncpy(newEmail.subject, subject, strlen(subject)-1);
                strncpy(newEmail.body, body, strlen(body)-1);
                sent[numSent] = newEmail;
                numSent++;

                printf("\nEmail sent successfully to %s!\n\n", to);
                break;
            case 2:
                if(numUnreads == 0) {
                    printf("\nNo new emails.\n\n");
                } else {
                    printf("\nUnread Emails\n");
                    printf("--------------\n");
                    for(int i=0; i<numUnreads; i++) {
                        printf("From: %s\n", unreads[i].to);
                        printf("Subject: %s\n", unreads[i].subject);
                        printf("Message: %s\n\n", unreads[i].body);
                    }
                    numUnreads = 0; // All unread emails have been read
                }
                break;
            case 3:
                if(numSent == 0) {
                    printf("\nNo sent emails.\n\n");
                } else {
                    printf("\nSent Emails\n");
                    printf("-----------\n");
                    for(int i=0; i<numSent; i++) {
                        printf("To: %s\n", sent[i].to);
                        printf("Subject: %s\n", sent[i].subject);
                        printf("Message: %s\n\n", sent[i].body);
                    }
                }
                break;
            case 4:
                printf("\nGoodbye!\n");
                running = false;
                break;
            default:
                printf("\nInvalid choice. Try again.\n\n");
                break;
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Email Client ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Defining struct Email to store email data
struct Email {
    char to[50];
    char subject[100];
    char body[1000];
};

// Function to validate email address
int isEmailValid(char *email) {
    int i, atSymbol = 0;
    for(i = 0; email[i] != '\0'; i++) {
        if(email[i] == '@') {
            atSymbol++;
        }
    }
    if(atSymbol == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    struct Email inbox[30]; // maximum inbox size
    int i, inboxSize = 0, choice, emailIndex = -1; 

    while(1) {
        printf("\n---------------------------------\n");
        printf("Welcome to Retro Email Client!\n");
        printf("---------------------------------\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. View Email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clearing input buffer 
        while(getchar() != '\n');

        switch(choice) {
            case 1: {
                printf("\nEnter email details\n");

                // Taking input of email details
                struct Email e;
                printf("To: ");
                gets(e.to);
                while(!isEmailValid(e.to)) {
                    printf("Invalid email address!\n");
                    printf("To: ");
                    gets(e.to);
                }
                printf("Subject: ");
                gets(e.subject);
                printf("Body: ");
                gets(e.body);

                // Storing email in inbox
                inboxSize++;
                inbox[inboxSize-1] = e;
                break;
            }
            case 2: {
                printf("\nInbox (%d mails)\n", inboxSize);
                printf("-----------------------------\n");
                // Displaying emails in inbox
                for(i = 0; i < inboxSize; i++) {
                    printf("%d. %s\n", i+1, inbox[i].subject);
                }
                break;
            }
            case 3: {
                printf("\nEnter email index: ");
                scanf("%d", &emailIndex);
                // Clearing input buffer 
                while(getchar() != '\n');

                // Validating email index
                if(emailIndex < 1 || emailIndex > inboxSize) {
                    printf("\nInvalid email index!\n");
                    emailIndex = -1;
                    break;
                }

                // Displaying email details
                printf("\nFrom: %s\n", inbox[emailIndex-1].to);
                printf("Subject: %s\n", inbox[emailIndex-1].subject);
                printf("Body: %s\n", inbox[emailIndex-1].body);
                break;
            }
            case 4: {
                printf("\nThank you for using Retro Email Client!\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice!\n");
            }
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Email Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char option[50];
    printf("Welcome to MyEmail - A C Email Client\n");
    printf("What would you like to do today? \n");

    while(strcmp(option, "quit") != 0){
        printf("> ");
        scanf("%s", option);

        if(strcmp(option, "send") == 0){
            printf("Enter recipient email address: ");
            char recipient[50];
            scanf("%s", recipient);

            printf("Enter email subject: ");
            char subject[100];
            scanf("%s", subject);

            printf("Enter email body: ");
            char body[500];
            scanf("%s", body);

            printf("Your email has been sent to %s\n", recipient);
        }
        else if(strcmp(option, "check") == 0){
            printf("Checking for new emails...\n");
            printf("No new emails at this time.\n");
        }
        else if(strcmp(option, "help") == 0){
            printf("MyEmail commands: \n");
            printf(" - send: send an email \n");
            printf(" - check: check for new emails \n");
            printf(" - quit: exit the email client \n");
        }
        else if(strcmp(option, "quit") == 0){
            printf("Thank you for using MyEmail! \n");
            break;
        }
        else{
            printf("Invalid command. Type 'help' for a list of commands. \n");
        }
    }

    return 0;
}
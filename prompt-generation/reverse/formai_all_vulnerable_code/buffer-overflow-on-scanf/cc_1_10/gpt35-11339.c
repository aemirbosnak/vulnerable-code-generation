//FormAI DATASET v1.0 Category: Email Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct {
    char sender[50];
    char receiver[50];
    char subject[100];
    char content[500];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void send_email() {
    printf("\nEnter sender: ");
    fgets(emails[num_emails].sender, 50, stdin);
    printf("Enter receiver: ");
    fgets(emails[num_emails].receiver, 50, stdin);
    printf("Enter subject: ");
    fgets(emails[num_emails].subject, 100, stdin);
    printf("Enter content: ");
    fgets(emails[num_emails].content, 500, stdin);
    num_emails++;
    printf("Email Sent!\n");
}

void view_emails() {
    if(num_emails == 0) {
        printf("\nNo emails to display!\n");
    } else {
        printf("\n");
        for(int i = 0; i < num_emails; i++) {
            printf("Email #%d\nSender: %sReceiver: %sSubject: %sContent: %s", i+1,
                    emails[i].sender, emails[i].receiver, emails[i].subject, emails[i].content);
            printf("------------------------\n");
        }
    }
}

int main() {
    char command[10];

    printf("Welcome to Unique C Email Client\n\n");

    while(1) {
        printf("Available commands: send, view, quit\n");
        printf("Enter command: ");
        scanf("%s", command);

        if(strcmp(command, "send") == 0) {
            send_email();
        } else if(strcmp(command, "view") == 0) {
            view_emails();
        } else if(strcmp(command, "quit") == 0) {
            printf("Exiting email client...\n");
            exit(0);
        } else {
            printf("Invalid command. Try again.\n");
        }

        // clean up input buffer
        while(getchar() != '\n');
    }

    return 0;
}
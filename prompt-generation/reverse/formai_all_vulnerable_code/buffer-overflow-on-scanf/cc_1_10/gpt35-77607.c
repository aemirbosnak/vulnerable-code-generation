//FormAI DATASET v1.0 Category: Email Client ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_SENDER_LENGTH 50
#define MAX_BODY_LENGTH 500

struct email {
    char sender[MAX_SENDER_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
};

int main() {
    struct email emails[MAX_EMAILS];
    int num_emails = 0;
    char choice;

    printf("---Email Client---\n");

    do {
        printf("\nMain Menu:\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");
        printf("\nEnter choice: ");
        scanf("%c", &choice);
        getchar(); // to clear input buffer

        switch(choice) {
            case '1':
                if(num_emails >= MAX_EMAILS) {
                    printf("\nInbox is full. Cannot send more emails.\n");
                    break;
                }

                printf("\nCompose Email:\n");
                printf("From: ");
                fgets(emails[num_emails].sender, MAX_SENDER_LENGTH, stdin);
                printf("Subject: ");
                fgets(emails[num_emails].subject, MAX_SUBJECT_LENGTH, stdin);
                printf("Body: ");
                fgets(emails[num_emails].body, MAX_BODY_LENGTH, stdin);

                printf("\nEmail sent successfully.\n");
                num_emails++;
                break;
            case '2':
                if(num_emails == 0) {
                    printf("\nInbox is empty.\n");
                    break;
                }
                
                printf("\nInbox:\n");
                for(int i = 0; i < num_emails; i++) {
                    printf("---Email %d---\n", i+1);
                    printf("From: %s", emails[i].sender);
                    printf("Subject: %s", emails[i].subject);
                    printf("Body: %s", emails[i].body);
                    printf("\n");
                }
                break;
            case '3':
                printf("\nProgram terminating...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
                break;
        }
    } while(1);

    return 0;
}
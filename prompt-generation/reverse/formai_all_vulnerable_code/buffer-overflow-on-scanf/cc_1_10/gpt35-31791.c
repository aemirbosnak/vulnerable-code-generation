//FormAI DATASET v1.0 Category: Email Client ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_EMAILS 10
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 200

struct Email {
    char sender[50];
    char receiver[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
};

int main() {
    struct Email inbox[MAX_EMAILS];
    int email_count = 0;
    int choice = -1;

    while(choice != 0) {
        printf("Welcome to the Email Client\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("0. Quit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(email_count < MAX_EMAILS) {
                    struct Email new_email;
                    printf("From: ");
                    scanf("%s", new_email.sender);
                    printf("To: ");
                    scanf("%s", new_email.receiver);
                    printf("Subject: ");
                    scanf("%s", new_email.subject);
                    printf("Body: ");
                    scanf("%s", new_email.body);

                    inbox[email_count] = new_email;
                    email_count++;

                    printf("Email sent!\n");
                } else {
                    printf("Inbox full! Cannot compose new email.\n");
                }
                break;
            case 2:
                printf("Inbox:\n");
                if(email_count > 0) {
                    for(int i = 0; i < email_count; i++) {
                        printf("From: %s\n", inbox[i].sender);
                        printf("To: %s\n", inbox[i].receiver);
                        printf("Subject: %s\n", inbox[i].subject);
                        printf("Body: %s\n", inbox[i].body);
                        printf("-----------------------------\n");
                    }
                } else {
                    printf("Inbox empty!\n");
                }
                break;
            case 0:
                printf("Exiting Email Client. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}
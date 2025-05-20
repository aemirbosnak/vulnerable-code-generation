//FormAI DATASET v1.0 Category: Email Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT 50
#define MAX_BODY 500
#define MAX_SENDER 30
#define MAX_RECIPIENT 50

struct Email {
    char sender[MAX_SENDER];
    char recipient[MAX_RECIPIENT];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
};

int main() {
    int option, num_emails = 0;
    struct Email emails[MAX_EMAILS];
    char input[MAX_BODY];
    char email_body[MAX_BODY];

    do {
        printf("\n-----MENU-----\n");
        printf("1. Compose email\n");
        printf("2. View inbox\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: // Compose email
                if(num_emails == MAX_EMAILS) {
                    printf("\nInbox is full. Please delete an email before composing a new one.\n");
                } else {
                    struct Email new_email;
                    printf("\nEnter sender: ");
                    scanf("%s", new_email.sender);
                    printf("Enter recipient: ");
                    scanf("%s", new_email.recipient);
                    printf("Enter subject: ");
                    scanf("%s", new_email.subject);
                    printf("Enter body: ");
                    scanf("%s", email_body);
                    strcpy(new_email.body, email_body);
                    emails[num_emails++] = new_email;
                    printf("\nEmail sent successfully!\n");
                }
                break;
            case 2: // View inbox
                if(num_emails == 0) {
                    printf("\nNo emails in inbox.\n");
                } else {
                    for(int i = 0; i < num_emails; i++) {
                        printf("\n-----EMAIL %d-----\n", i+1);
                        printf("Sender: %s\n", emails[i].sender);
                        printf("Recipient: %s\n", emails[i].recipient);
                        printf("Subject: %s\n", emails[i].subject);
                        printf("Body: %s\n", emails[i].body);
                    }
                }
                break;
            case 3: // Exit
                printf("\nExiting program...\n");
                break;
            default: // Invalid option
                printf("\nInvalid option. Please try again.\n");
                break;
        }

    } while(option != 3);

    return 0;
}
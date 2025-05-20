//FormAI DATASET v1.0 Category: Email Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_SUBJECT 100
#define MAX_EMAIL_BODY 500
#define MAX_EMAILS 10

typedef struct Email {
    char sender[50];
    char recipient[50];
    char subject[MAX_EMAIL_SUBJECT];
    char body[MAX_EMAIL_BODY];
} Email;

int main() {
    Email emails[MAX_EMAILS];
    int numEmails = 0;
    int menuChoice;
    
    printf("Welcome to the FutureMail Email Client\n\n");
    
    do {
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &menuChoice);
        
        switch(menuChoice) {
            case 1:
                if(numEmails < MAX_EMAILS) {
                    Email newEmail;
                    printf("\nEnter Recipient: ");
                    scanf("%s", newEmail.recipient);
                    printf("\nEnter Subject: ");
                    scanf("%s", newEmail.subject);
                    printf("\nEnter Body: ");
                    scanf("%s", newEmail.body);
                    strcpy(newEmail.sender, "Me");
                    emails[numEmails++] = newEmail;
                    printf("\nEmail Sent Successfully!\n\n");
                } else {
                    printf("\nYou have reached the maximum number of emails allowed (%d). Please delete some to make room for more.\n\n", MAX_EMAILS);
                }
                break;
            case 2:
                if(numEmails == 0) {
                    printf("\nYour inbox is empty.\n\n");
                } else {
                    printf("\nYour Inbox:\n");
                    printf("-------------------------------------------------------------\n");
                    for(int i = 0; i < numEmails; i++) {
                        printf("%d) From: %s\t\tTo: %s\t\tSubject: %s\n", i + 1, emails[i].sender, emails[i].recipient, emails[i].subject);
                    }
                    printf("-------------------------------------------------------------\n");
                    int emailSelection;
                    do {
                        printf("\nWhich email would you like to read (1-%d) or enter 0 to return to main menu: ", numEmails);
                        scanf("%d", &emailSelection);
                        
                        if(emailSelection > 0 && emailSelection <= numEmails) {
                            Email selectedEmail = emails[emailSelection - 1];
                            printf("\nFrom: %s\n", selectedEmail.sender);
                            printf("To: %s\n", selectedEmail.recipient);
                            printf("Subject: %s\n", selectedEmail.subject);
                            printf("Body: %s\n\n", selectedEmail.body);
                        } else if(emailSelection != 0) {
                            printf("\nInvalid email selection. Please try again.\n\n");
                        }
                    } while(emailSelection != 0);
                }
                break;
            case 3:
                printf("\nHave a nice day!\n");
                break;
            default:
                printf("\nInvalid option selected. Please try again.\n\n");
        }
    } while(menuChoice != 3);
    
    return 0;
}
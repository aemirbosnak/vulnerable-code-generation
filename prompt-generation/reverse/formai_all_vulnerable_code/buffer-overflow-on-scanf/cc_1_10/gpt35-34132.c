//FormAI DATASET v1.0 Category: Email Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {
    char sender[30];
    char recipient[30];
    char subject[50];
    char body[500];
    char time[20];
};

int main() {
    int option;
    char choice;
    int count = 0;
    struct email inbox[100];

    do {
        printf("\n\t\t########## EMAIL CLIENT ##########\n");
        printf("\n\t\t1. Compose Email\n\t\t2. View Inbox\n\t\t3. Exit\n\t\tEnter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                printf("\n\t\t########## COMPOSE EMAIL ##########\n");
                printf("\n\t\tEnter sender email address: ");
                scanf("%s", inbox[count].sender);
                printf("\t\tEnter recipient email address: ");
                scanf("%s", inbox[count].recipient);
                printf("\t\tEnter email subject: ");
                scanf("%s", inbox[count].subject);
                printf("\t\tEnter email body (max 500 characters):\n");
                scanf(" %[^\n]s", inbox[count].body);
                printf("\t\tEmail sent successfully!");
                count++;
                break;
            }
            case 2: {
                printf("\n\t\t########## INBOX ##########\n");
                if(count == 0) {
                    printf("\n\t\tInbox Empty!\n");
                    break;
                }
                else {
                    for(int i = 0; i < count; i++) {
                        printf("\n\t\tEmail #%d", i+1);
                        printf("\n\t\tSender: %s", inbox[i].sender);
                        printf("\n\t\tRecipient: %s", inbox[i].recipient);
                        printf("\n\t\tSubject: %s", inbox[i].subject);
                        printf("\n\t\tBody: %s", inbox[i].body);
                        printf("\n\t\tTime: %s", inbox[i].time);
                        printf("\n\t\t===========================\n"); 
                    }
                }
                break;
            }
            case 3: {
                printf("\n\t\tThank you for using the Email Client!\n");
                exit(0);
            }
            default: {
                printf("\n\t\tInvalid Option! Please try again.\n");
                break;
            }
        }

        printf("\n\t\tDo you want to continue (y/n)? ");
        scanf(" %c", &choice);
    } while(choice == 'y');

    printf("\n\t\tGoodbye!\n");
    return 0;
}
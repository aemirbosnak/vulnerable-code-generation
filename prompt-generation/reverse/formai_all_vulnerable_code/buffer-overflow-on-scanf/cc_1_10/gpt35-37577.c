//FormAI DATASET v1.0 Category: Email Client ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Function to display messages in the mailbox
void displayMailbox(char mailbox[][100], int msgCount) {
    int i;
    for (i = 0; i < msgCount; i++) {
        printf("%d. %s\n", i + 1, mailbox[i]);
    }
}

//Function to send a new message
void sendEmail(char mailbox[][100], int *msgCount) {
    char newMsg[100];
    printf("Enter a new message: ");
    scanf("%s", newMsg);
    strcpy(mailbox[*msgCount], newMsg);
    (*msgCount)++;
    printf("\nMessage sent successfully!\n");
}

//Function to delete messages from the mailbox
void deleteEmail(char mailbox[][100], int *msgCount) {
    int i, msgNum;
    displayMailbox(mailbox, *msgCount);
    printf("\nEnter the message number to delete: ");
    scanf("%d", &msgNum);
    //Shift email messages up by one after deleting
    for (i = msgNum - 1; i < *msgCount - 1; i++) {
        strcpy(mailbox[i], mailbox[i+1]);
    }
    (*msgCount)--;
    printf("\nMessage deleted successfully!\n");
}

void main() {
    char mailbox[50][100];  //Maximum 50 messages each with 100 characters
    int msgCount = 0;       //Counter for the number of messages in the mailbox
    int choice;
    do {
        //Display menu
        printf("\n\nEnter your choice:\n1. Display mailbox\n2. Send an email\n3. Delete an email\n4. Exit\n");
        scanf("%d", &choice);
        //Perform action based on choice
        switch (choice) {
            case 1:
                if (msgCount == 0) {
                    printf("\nMailbox is empty.\n");
                } else {
                    displayMailbox(mailbox, msgCount);
                }
                break;
            case 2:
                sendEmail(mailbox, &msgCount);
                break;
            case 3:
                if (msgCount == 0) {
                    printf("\nMailbox is empty.\n");
                } else {
                    deleteEmail(mailbox, &msgCount);
                }
                break;
            case 4:
                printf("\nExiting the program...\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    } while (choice != 4);
}
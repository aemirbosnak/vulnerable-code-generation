//FormAI DATASET v1.0 Category: Email Client ; Style: immersive
// Welcome to our immersive C email client program!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BODY_LENGTH 1000
#define MAX_EMAILS 10

typedef struct{
    char sender[50];
    char recipient[50];
    char subject[50];
    char body[MAX_BODY_LENGTH];
} Email;

Email inbox[MAX_EMAILS];
int numEmails = 0;

void clearInbox(){
    for(int i = 0; i < numEmails; i++){
        strcpy(inbox[i].sender, "");
        strcpy(inbox[i].recipient, "");
        strcpy(inbox[i].subject, "");
        strcpy(inbox[i].body, "");
    }
    numEmails = 0;
}

void displayEmail(Email e){
    printf("\nSender: %s", e.sender);
    printf("\nRecipient: %s", e.recipient);
    printf("\nSubject: %s", e.subject);
    printf("\nBody: %s", e.body);
}

void displayInbox(){
    printf("\n*****INBOX*****\n");
    for(int i = 0; i < numEmails; i++){
        printf("\nEmail %d:", i+1);
        displayEmail(inbox[i]);
    }
    printf("\n***************\n");
}

void composeEmail(){
    printf("\n*************\nCOMPOSE EMAIL\n*************\n");

    if(numEmails >= MAX_EMAILS){
        printf("Inbox is full. Please delete emails to make space.\n");
        return;
    }

    Email e;

    printf("\nEnter sender email address: ");
    scanf("%s", e.sender);

    printf("Enter recipient email address: ");
    scanf("%s", e.recipient);

    printf("Enter email subject: ");
    scanf("%s", e.subject);

    printf("Enter email body (max %d characters): ", MAX_BODY_LENGTH);
    getchar(); //to clear input buffer
    fgets(e.body, MAX_BODY_LENGTH, stdin);

    inbox[numEmails++] = e;
    printf("\nEmail sent!\n");
}

void deleteEmail(){
    int num;
    printf("\nEnter the number of the email you would like to delete: ");
    scanf("%d", &num);

    if(num < 1 || num > numEmails){
        printf("Invalid email number.\n");
        return;
    }

    for(int i = num-1; i < numEmails-1; i++){
        inbox[i] = inbox[i+1];
    }
    numEmails--;
    printf("\nEmail deleted.\n");
}

int main(){

    int choice = 0;

    while(choice != 5){
        printf("\n**********\nMAIN MENU\n**********\n");
        printf("1. Display inbox\n");
        printf("2. Compose email\n");
        printf("3. Delete email\n");
        printf("4. Clear inbox\n");
        printf("5. Exit\n");

        printf("\nEnter choice (1-5): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                displayInbox();
                break;
            case 2:
                composeEmail();
                break;
            case 3:
                deleteEmail();
                break;
            case 4:
                clearInbox();
                printf("\nInbox cleared.\n");
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please choose a number from 1-5.\n");
        }
    }

    return 0;
}
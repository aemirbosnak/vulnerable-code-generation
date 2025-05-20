//FormAI DATASET v1.0 Category: Email Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 10
#define MAX_LENGTH 1000
#define MAX_SENDERS 200

typedef struct{
    char sender[MAX_SENDERS];
    char subject[MAX_LENGTH];
    char message[MAX_LENGTH];
} Email;

void printMenu(){
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("               Purrfect Email Client\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                     Main Menu\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("1 - Compose New Email\n");
    printf("2 - Check Inbox\n");
    printf("3 - Quit\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter your choice : ");
}

void clearBuffer(){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void invalidChoice(){
    printf("Invalid choice. Please enter a valid choice.\n");
}

void addEmail(Email* emails, int* numEmails){
    int senderLength = 0;
    int subjectLength = 0;
    int messageLength = 0;
    
    printf("Enter sender : ");
    fgets(emails[*numEmails].sender, MAX_SENDERS, stdin);
    senderLength = strlen(emails[*numEmails].sender);
    if(senderLength > 0 && emails[*numEmails].sender[senderLength - 1] == '\n'){
        emails[*numEmails].sender[senderLength - 1] = '\0';
    }
    
    printf("Enter subject : ");
    fgets(emails[*numEmails].subject, MAX_LENGTH, stdin);
    subjectLength = strlen(emails[*numEmails].subject);
    if(subjectLength > 0 && emails[*numEmails].subject[subjectLength - 1] == '\n'){
        emails[*numEmails].subject[subjectLength - 1] = '\0';
    }
    
    printf("Enter message : ");
    fgets(emails[*numEmails].message, MAX_LENGTH, stdin);
    messageLength = strlen(emails[*numEmails].message);
    if(messageLength > 0 && emails[*numEmails].message[messageLength - 1] == '\n'){
        emails[*numEmails].message[messageLength - 1] = '\0';
    }
    
    printf("Email sent successfully!\n\n");
    *numEmails += 1;
}

void viewInbox(Email* emails, int numEmails){
    if(numEmails == 0){
        printf("You have no new emails.\n\n");
        return;
    }
    
    printf("Your inbox:\n");
    for(int i = 0; i < numEmails; i++){
        printf("Sender : %s\n", emails[i].sender);
        printf("Subject : %s\n", emails[i].subject);
        printf("Message : %s\n", emails[i].message);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
}

int main(){
    Email emails[MAX_EMAILS];
    int numEmails = 0;
    int choice = 0;
    while(choice != 3){
        printMenu();
        if(scanf("%d", &choice) != 1){
            clearBuffer();
            invalidChoice();
            continue;
        }
        clearBuffer();
        switch(choice){
            case 1:
                addEmail(emails, &numEmails);
                break;
            case 2:
                viewInbox(emails, numEmails);
                break;
            case 3:
                printf("Thank you for using Purrfect Email Client. Goodbye!\n\n");
                break;
            default:
                invalidChoice();
                break;
        }
    }
    return 0;
}
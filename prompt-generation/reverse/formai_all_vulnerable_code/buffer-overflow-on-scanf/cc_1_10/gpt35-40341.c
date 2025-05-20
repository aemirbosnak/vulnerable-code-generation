//FormAI DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define MAX_INPUT to limit input size*/
#define MAX_INPUT 200

/* function signature declaration*/
void send_email();
void receive_email();

/* main function */
int main()
{
    int choice;

    /* keep running program until user chooses to exit*/
    while(1){
        printf("\n------ Email Client ------\n");
        printf("\nEnter your choice:\n1. Send email\n2. Receive email\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: send_email(); break; /*call the send_email function*/
            case 2: receive_email(); break; /*call the receive_email function*/
            case 3: printf("\nGoodbye!\n"); exit(0); /*exit program*/
            default: printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0; /*program ends*/
}

/* define structure for email message */
typedef struct{
    char sender[MAX_INPUT];
    char recipient[MAX_INPUT];
    char subject[MAX_INPUT];
    char body[MAX_INPUT];
} Email;

/*function definition for sending email*/
void send_email(){
    Email message; /*create an instance of Email struct*/

    /*get user input for email fields*/
    printf("\n====== SEND EMAIL ======\n");
    printf("\nSender: ");
    scanf("%s", message.sender);
    printf("\nRecipient: ");
    scanf("%s", message.recipient);
    printf("\nSubject: ");
    scanf("%s", message.subject);
    printf("\nBody: ");
    scanf("%s", message.body);

    /*print confirmation message*/
    printf("\nEmail sent successfully!");
    printf("\nSender: %s", message.sender);
    printf("\nRecipient: %s", message.recipient);
    printf("\nSubject: %s", message.subject);
    printf("\nBody: %s", message.body);
}

/*function definition for receiving email*/
void receive_email(){

    /*create pointer to file*/
    FILE *infile;
    Email message; /*create an instance of Email struct*/

    /*open file for reading*/
    infile = fopen("inbox.txt", "r");

    if(infile == NULL){ /*check if file exists*/
        printf("\nInbox is empty!\n");
    }
    else{
        /*read the file line by line and print email messages*/
        printf("\n====== INBOX ======\n");
        while(fscanf(infile, "%s %s %s %s", message.sender, message.recipient, message.subject, message.body) != EOF){
            printf("\nSender: %s", message.sender);
            printf("\nRecipient: %s", message.recipient);
            printf("\nSubject: %s", message.subject);
            printf("\nBody: %s", message.body);
            printf("\n----------------\n");
        }

        /*close the file*/
        fclose(infile);
    }
}
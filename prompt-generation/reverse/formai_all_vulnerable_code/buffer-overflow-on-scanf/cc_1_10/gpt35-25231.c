//FormAI DATASET v1.0 Category: Email Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define the maximum length of the email message */
#define MAX_EMAIL_LENGTH 1000

/* Provide a struct to hold the information for each email */
typedef struct {
    char sender[50];
    char recipient[50];
    char subject[100];
    char message[MAX_EMAIL_LENGTH];
    char timestamp[30];
} email;

/* Declare function prototypes */
void printMenu();
void sendEmail(email* eml);
void viewSentEmails(email* emls, int numEmails);
void viewReceivedEmails(email* emls, int numEmails);

int main() {
    /* Declare variables */
    email inbox[100];
    email sent[100];
    int numSent = 0;
    int numReceived = 0;
    char option[2];

    printf("Welcome to the Introspective Email Client!\n");

    do {
        /* Print main menu and get user input */
        printMenu();
        printf("Please enter an option: ");
        scanf("%s", option);

        /* Act on user input */
        switch (option[0]) {
            case '1':
                sendEmail(&sent[numSent]);
                numSent++;
                break;
            case '2':
                viewSentEmails(sent, numSent);
                break;
            case '3':
                viewReceivedEmails(inbox, numReceived);
                break;
            case '4':
                printf("Thank you for using the Introspective Email Client!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (option[0] != '4');

    return 0;
}

/* Define functions */

void printMenu() {
    printf("\n1. Send Email\n");
    printf("2. View Sent Emails\n");
    printf("3. View Received Emails\n");
    printf("4. Quit\n");
}

void sendEmail(email* eml) {
    char receiver[50];
    char subject[100];
    char message[MAX_EMAIL_LENGTH];

    /* Get input from user */
    printf("\nSend Email:\n");
    printf("Recipient: ");
    scanf("%s", receiver);
    printf("Subject: ");
    scanf("%s", subject);
    printf("Message (max %d characters):\n", MAX_EMAIL_LENGTH-1);
    getchar();  /* Flush the newline character from the scanf call */
    fgets(message, MAX_EMAIL_LENGTH, stdin);

    /* Copy input to email struct */
    strcpy(eml->sender, "introspective@emailclient.com");
    strcpy(eml->recipient, receiver);
    strcpy(eml->subject, subject);
    strcpy(eml->message, message);

    /* Record timestamp */
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(eml->timestamp, "%d-%02d-%02d %02d:%02d:%02d",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

    /* Display confirmation message */
    printf("Email sent successfully!\n");
}

void viewSentEmails(email* emls, int numEmails) {
    if (numEmails == 0) {
        printf("\nNo emails sent yet.\n");
        return;
    }

    printf("\nSent Emails:\n");

    /* Print headers */
    printf("%-25s %-25s %-50s %s\n", "Timestamp", "Recipient", "Subject", "Message");
    printf("-------------------------------------------------------------------------------------\n");

    /* Print emails */
    for (int i = 0; i < numEmails; i++) {
        printf("%-25s %-25s %-50s %.40s\n",
               emls[i].timestamp, emls[i].recipient,
               emls[i].subject, emls[i].message);
    }
}

void viewReceivedEmails(email* emls, int numEmails) {
    if (numEmails == 0) {
        printf("\nInbox is empty.\n");
        return;
    }

    printf("\nReceived Emails:\n");

    /* Print headers */
    printf("%-25s %-25s %-50s %s\n", "Timestamp", "Sender", "Subject", "Message");
    printf("-------------------------------------------------------------------------------------\n");

    /* Print emails */
    for (int i = 0; i < numEmails; i++) {
        printf("%-25s %-25s %-50s %.40s\n",
               emls[i].timestamp, emls[i].sender,
               emls[i].subject, emls[i].message);
    }
}
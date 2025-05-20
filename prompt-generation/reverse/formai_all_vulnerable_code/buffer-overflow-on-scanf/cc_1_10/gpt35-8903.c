//FormAI DATASET v1.0 Category: Email Client ; Style: realistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_EMAILS 10 //Maximum emails that can be stored
#define MAX_SUBJECT 50 //Maximum subject length
#define MAX_BODY 1000 //Maximum body length

//Email structure
struct Email {
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
    char sender[50];
    char recipient[50];
    char date[50];
};

//Function prototypes
void displayMenu();
void displayEmails(struct Email[]);
void receiveEmail(struct Email[]);
void sendEmail(struct Email[]);

int main () {
    struct Email emails[MAX_EMAILS];
    int choice;
    int emailCount = 0;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayEmails(emails);
                break;
            case 2:
                receiveEmail(emails);
                emailCount++;
                break;
            case 3:
                sendEmail(emails);
                break;
            case 4:
                printf("Exiting Email client...\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }
    } while(choice != 4);
    
    return 0;
}

//Function to display the main menu
void displayMenu() {
    printf("\nEnter your choice:\n");
    printf("1. View emails\n");
    printf("2. Receive email\n");
    printf("3. Send email\n");
    printf("4. Quit\n");
}

//Function to display all emails currently stored
void displayEmails(struct Email emails[]) {
    if(emails[0].subject[0] == '\0') {
        printf("No emails to display\n");
        return;
    }
    
    printf("\nList of emails:\n");
    for(int i=0; i<MAX_EMAILS; i++) {
        if(emails[i].subject[0] != '\0') {
            printf("Subject: %s\n", emails[i].subject);
            printf("From: %s\n", emails[i].sender);
            printf("Date: %s\n", emails[i].date);
            printf("\n");
        }
    }
}

//Function to receive an email and store it in the email list
void receiveEmail(struct Email emails[]) {
    if(emails[MAX_EMAILS-1].subject[0] != '\0') {
        printf("Cannot receive any more emails. Email list is full.\n");
        return;
    }
    
    struct Email newEmail;
    printf("\nEnter sender: ");
    scanf("%s", newEmail.sender);
    printf("Enter subject: ");
    scanf("%s", newEmail.subject);
    printf("Enter date: ");
    scanf("%s", newEmail.date);
    printf("Enter body: ");
    fflush(stdin);
    fgets(newEmail.body, MAX_BODY, stdin);
    strcpy(emails[MAX_EMAILS-1].recipient, "You");
    
    for(int i=0; i<MAX_EMAILS; i++) {
        if(emails[i].subject[0] == '\0') {
            emails[i] = newEmail;
            printf("\nEmail received and stored in list successfully\n");
            break;
        }
    }
}

//Function to send an email
void sendEmail(struct Email emails[]) {
    if(emails[0].subject[0] == '\0') {
        printf("No emails to reply to\n");
        return;
    }
    
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
    char recipient[50];
    int emailIndex;
    
    printf("\nEnter index of email you want to reply to: ");
    scanf("%d", &emailIndex);
    printf("Enter recipient: ");
    scanf("%s", recipient);
    printf("Enter subject: ");
    fflush(stdin);
    fgets(subject, MAX_SUBJECT, stdin);
    printf("Enter body: ");
    fflush(stdin);
    fgets(body, MAX_BODY, stdin);
    
    printf("\nEmail sent successfully\n");
}
//FormAI DATASET v1.0 Category: Email Client ; Style: futuristic
//Futuristic C Email Client Example Program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMAILS 100 //Maximum number of emails that can be stored
#define MAX_SUBJECT_LENGTH 100 //Maximum length of email subject
#define MAX_BODY_LENGTH 1000 //Maximum length of email body
#define MAX_EMAIL_ADDRESS_LENGTH 100 //Maximum length of email address

//Email structure to store all necessary information about an email
typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char to_address[MAX_EMAIL_ADDRESS_LENGTH];
    char from_address[MAX_EMAIL_ADDRESS_LENGTH];
} Email;

//EmailBox structure to store multiple emails
typedef struct {
    Email emails[MAX_EMAILS];
    int num_emails;
} EmailBox;

//Function to send email
void send_email(char* to_address, char* from_address, char* subject, char* body) {
    printf("Sending email to %s from %s\nSubject: %s\nBody: %s\n", to_address, from_address, subject, body);
}

//Function to compose email and add it to email box
void compose_email(EmailBox* inbox) {
    Email new_email;
    printf("Enter To Address: ");
    scanf("%s", new_email.to_address);
    printf("Enter From Address: ");
    scanf("%s", new_email.from_address);
    printf("Enter Subject: ");
    scanf("%s", new_email.subject);
    printf("Enter Body: ");
    scanf("%s", new_email.body);
    inbox->emails[inbox->num_emails] = new_email;
    inbox->num_emails++;
}

int main() {
    EmailBox inbox;
    inbox.num_emails = 0;
    int choice = 0;
    while (choice != 3) {
        printf("Futuristic Email Client\n1. Compose Email\n2. View Inbox\n3. Exit\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                compose_email(&inbox);
                printf("Email Sent!\n");
                break;
            case 2:
                printf("Inbox:\n");
                for(int i = 0; i < inbox.num_emails; i++) {
                    printf("Email %d\nTo: %s\nFrom: %s\nSubject: %s\nBody: %s\n", i+1, inbox.emails[i].to_address, 
                           inbox.emails[i].from_address, inbox.emails[i].subject, inbox.emails[i].body);
                }
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
    return 0;
}
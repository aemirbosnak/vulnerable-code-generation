//FormAI DATASET v1.0 Category: Email Client ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_EMAILS 10
#define MAX_SUBJECT 50
#define MAX_BODY 1000

//Email structure
struct Email{
    char sender[50];
    char receiver[50];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
};

//Function to send email
void sendEmail(struct Email *mail, int *email_count){
    if(*email_count >= MAX_EMAILS){
        printf("Inbox full. Delete some emails to send new emails.\n");
        return;
    }
    printf("\nEnter sender's email address: ");
    scanf("%s", mail[*email_count].sender);
    printf("Enter receiver's email address: ");
    scanf("%s", mail[*email_count].receiver);
    printf("Enter subject: ");
    scanf("%s", mail[*email_count].subject);
    printf("Enter body: ");
    getchar();
    fgets(mail[*email_count].body, MAX_BODY, stdin);
    printf("\nEmail sent successfully!\n");
    (*email_count)++;
}

//Function to view emails
void viewEmails(struct Email *mail, int email_count){
    printf("\nInbox:\n");
    for(int i=0; i<email_count; i++){
        printf("Email %d:\n", i+1);
        printf("From: %s\n", mail[i].sender);
        printf("To: %s\n", mail[i].receiver);
        printf("Subject: %s\n", mail[i].subject);
        printf("Body: %s\n", mail[i].body);
        printf("\n");
    }
}

int main(){
    int choice, email_count=0;
    struct Email mail[MAX_EMAILS];
    while(1){
        printf("\n\nChoose an option:\n");
        printf("1. Send email\n");
        printf("2. View emails\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                sendEmail(mail, &email_count);
                break;
            case 2:
                viewEmails(mail, email_count);
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}
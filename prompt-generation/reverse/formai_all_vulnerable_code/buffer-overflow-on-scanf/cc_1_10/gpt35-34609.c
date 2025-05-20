//FormAI DATASET v1.0 Category: Email Client ; Style: unmistakable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Global Variables*/
char username[100];
char password[100];
char server[100];
char recipient[100];
char subject[100];
char messageBody[1000];

/*Function Prototype*/
void login();
void createEmail();
void sendEmail();

int main(){
    printf("Welcome to C Email Client!\n");
    printf("---------------------------\n");

    login();
    createEmail();
    sendEmail();

    return 0;
}

/*Function to prompt user to enter login credentials*/
void login(){
    printf("\nEnter your email address: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    printf("Enter your server: ");
    scanf("%s", server);
}

/*Function to create email*/
void createEmail(){
    printf("\n-------------\n");
    printf("Create Email:\n");
    printf("-------------\n");

    printf("\nEnter recipient email address: ");
    scanf("%s", recipient);

    printf("Enter subject: ");
    scanf("%s", subject);

    printf("Enter message body: ");
    scanf("%s", messageBody);
}

/*Function to send email*/
void sendEmail(){
    printf("\nSending Email...\n");

    //SMTP connection code here

    printf("Email sent successfully!\n");
}
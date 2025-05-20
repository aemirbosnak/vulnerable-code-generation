//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){
    
    printf("Hello and welcome to our SMTP Client Program!\n");
    printf("Before we begin, let's make sure you are authorized.\n");
    printf("Please enter your username: ");

    char* username = (char*)malloc(sizeof(char)*20); 
    scanf("%s", username);

    printf("\nPlease enter your password: ");

    char* password = (char*)malloc(sizeof(char)*20); 
    scanf("%s", password);

    printf("\nWonderful! You are now authorized to use our SMTP Client Program. Let's get started!\n");
    printf("Please enter the email address of the recipient: ");

    char* recipient = (char*)malloc(sizeof(char)*50); 
    scanf("%s", recipient);

    printf("\nPlease enter the subject of your email: ");

    char* subject = (char*)malloc(sizeof(char)*100); 
    scanf("%s", subject);

    printf("\nPlease enter your message: ");

    char* message = (char*)malloc(sizeof(char)*500); 
    scanf("%s", message);

    // Here comes the fun part!
    printf("\n\nAre you ready to send your email? Press 'Yes' to continue or 'No' to exit: ");

    char* confirm = (char*)malloc(sizeof(char)*4); 
    scanf("%s", confirm);

    if(strcmp(confirm,"Yes")==0){
        printf("\nEmail sent successfully! Congrats on becoming a master SMTP Client Programmer :D\n");
    }
    else{
        printf("\nEmail not sent :( Maybe next time you will have the courage to press 'Yes'\n");
    }

    free(username);
    free(password);
    free(recipient);
    free(subject);
    free(message);
    free(confirm);

    return 0;
}
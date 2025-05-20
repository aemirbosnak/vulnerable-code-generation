//FormAI DATASET v1.0 Category: Email Client ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to Send Email
void send_email(char *to, char *subject, char *body){

    printf("\n To: %s \n", to);
    printf(" Subject: %s \n", subject);
    printf(" Body: %s \n", body);
    printf("\n Email sent successfully!\n");

}

//Function to Read Email
void read_email(char *from, char *subject, char *body){

    printf("\n From: %s \n", from);
    printf(" Subject: %s \n", subject);
    printf(" Body: %s \n", body);
    printf("\n Email read successfully!\n");

}

int main(){

    char to[100], from[100], subject[100], body[1000];
    int option;

    printf("Welcome to MyC Email Client! \n");
    printf("Please Select an Option: \n");
    printf("1. Send Email \n");
    printf("2. Read Email \n");
    printf("3. Exit \n");

    //get user input
    scanf("%d", &option);

    switch(option){

        case 1:
            printf("\n Enter To Address: ");
            scanf("%s", to);
            printf(" Enter Subject: ");
            scanf("%s", subject);
            printf(" Enter Body: ");
            scanf("%s", body);
            send_email(to, subject, body);
            break;

        case 2:
            printf("\n Enter From Address: ");
            scanf("%s", from);
            printf(" Enter Subject: ");
            scanf("%s", subject);
            printf(" Enter Body: ");
            scanf("%s", body);
            read_email(from, subject, body);
            break;

        case 3:
            printf("\n Thank you for using MyC Email Client! \n");
            break;

        default:
            printf("Invalid option. Please try again. \n");
            break;
    }

    return 0;
}
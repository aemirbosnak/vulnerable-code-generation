//FormAI DATASET v1.0 Category: Email Client ; Style: standalone
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_BUFFER 1024

// Define a structure for email data
struct email{
    char from[MAX_BUFFER], to[MAX_BUFFER], subject[MAX_BUFFER], message[MAX_BUFFER];
};

// Function to display main menu
void display_menu(){
    printf("Welcome to C Email Client!\n");
    printf("1. Create Email\n");
    printf("2. View Inbox\n");
    printf("3. Exit\n");
}

// Function to read an email and return a 'struct email'
struct email read_email(){
    struct email email;
    printf("From: ");
    fgets(email.from, MAX_BUFFER, stdin);
    printf("To: ");
    fgets(email.to, MAX_BUFFER, stdin);
    printf("Subject: ");
    fgets(email.subject, MAX_BUFFER, stdin);
    printf("Message: ");
    fgets(email.message, MAX_BUFFER, stdin);
    return email;
}

// Function to display an email
void display_email(struct email email){
    printf("From: %s", email.from);
    printf("To: %s", email.to);
    printf("Subject: %s", email.subject);
    printf("Message: %s", email.message);
    printf("\n");
}

// Function to view all emails in the inbox
void view_inbox(struct email *inbox, int *num_emails){
    if(*num_emails == 0){
        printf("Inbox is empty!\n");
        return;
    }
    for(int i=0; i<*num_emails; i++){
        display_email(inbox[i]);
        printf("-------------------------------------------------\n");
    }
}

int main(){
    int option = 0, num_emails = 0;
    struct email inbox[MAX_BUFFER];

    while(option != 3){
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &option);
        getchar();

        switch(option){
            case 1:
                inbox[num_emails++] = read_email();
                printf("Email created successfully!\n");
                printf("-------------------------------------------------\n");
                break;
            case 2:
                view_inbox(inbox, &num_emails);
                break;
            case 3:
                printf("Exiting C Email Client!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}
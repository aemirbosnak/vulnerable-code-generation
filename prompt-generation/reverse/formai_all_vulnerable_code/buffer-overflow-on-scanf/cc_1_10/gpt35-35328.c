//FormAI DATASET v1.0 Category: Email Client ; Style: protected
#include<stdio.h>
#include<stdlib.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_CONTENT_LENGTH 1000
#define MAX_EMAILS 10

typedef struct email {
    char sender[50];
    char receiver[50];
    char subject[MAX_SUBJECT_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Email;

typedef struct email_account {
    char email_address[50];
    char password[50];
    int num_emails;
    Email emails[MAX_EMAILS];
} EmailAccount;

int main() {
    EmailAccount my_email_account;
    
    printf("Welcome to the Email Client Program!\n");
    printf("Enter your email address:\n");
    scanf("%s", my_email_account.email_address);
    printf("Enter your password:\n");
    scanf("%s", my_email_account.password);
    
    // Let's assume that the user has 2 emails in their inbox
    my_email_account.num_emails = 2;
    
    // Email 1
    Email email_1;
    strcpy(email_1.sender, "johndoe@gmail.com");
    strcpy(email_1.receiver, my_email_account.email_address);
    strcpy(email_1.subject, "Meeting Request");
    strcpy(email_1.content, "Hello, I would like to request a meeting with you to discuss our upcoming project. Please let me know a good time to meet. Thanks!");
    
    my_email_account.emails[0] = email_1;
    
    // Email 2
    Email email_2;
    strcpy(email_2.sender, "janedoe@yahoo.com");
    strcpy(email_2.receiver, my_email_account.email_address);
    strcpy(email_2.subject, "Invitation to a Party");
    strcpy(email_2.content, "Hi, you're invited to my party this Friday at 7 pm. We'll have food, drinks and games. Hope to see you there!");
    
    my_email_account.emails[1] = email_2;
    
    printf("Hello, %s! You have %d emails in your inbox.\n", my_email_account.email_address, my_email_account.num_emails);
    
    // Let's print out the details of the emails in the inbox
    for (int i = 0; i < my_email_account.num_emails; i++) {
        printf("Email %d\n", i+1);
        printf("From: %s\n", my_email_account.emails[i].sender);
        printf("Subject: %s\n", my_email_account.emails[i].subject);
        printf("Content: %s\n\n", my_email_account.emails[i].content);
    }
    
    return 0;
}
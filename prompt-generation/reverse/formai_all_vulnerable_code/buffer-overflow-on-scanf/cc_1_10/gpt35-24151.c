//FormAI DATASET v1.0 Category: Email Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 50
#define MAX_SENDER_NAME 50
#define MAX_SUBJECT 100
#define MAX_BODY 500

typedef struct Email {
    char sender_name[MAX_SENDER_NAME];
    char recipient_name[MAX_SENDER_NAME];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
} Email;

int num_emails = 0;
Email inbox[MAX_EMAILS];

void send_email(char sender_name[], char recipient_name[], char subject[], char body[]) {
    if(num_emails >= MAX_EMAILS) {
        printf("Inbox is full!\n");
        return;
    }
    
    Email new_email;
    strcpy(new_email.sender_name, sender_name);
    strcpy(new_email.recipient_name, recipient_name);
    strcpy(new_email.subject, subject);
    strcpy(new_email.body, body);
    
    inbox[num_emails++] = new_email;
    
    printf("Email sent successfully!\n");
}

void view_inbox() {
    if(num_emails == 0) {
        printf("Inbox is empty!\n");
        return;
    }
    
    for(int i = 0; i < num_emails; i++) {
        printf("Email %d:\n", i+1);
        printf("From: %s\n", inbox[i].sender_name);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Body: %s\n\n", inbox[i].body);
    }
}

int main() {
    int choice;
    
    do {
        printf("1. Send Email\n");
        printf("2. View Inbox\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
            {
                char sender_name[MAX_SENDER_NAME];
                char recipient_name[MAX_SENDER_NAME];
                char subject[MAX_SUBJECT];
                char body[MAX_BODY];
                
                printf("Enter sender name: ");
                scanf("%s", sender_name);
                
                printf("Enter recipient name: ");
                scanf("%s", recipient_name);
                
                printf("Enter subject: ");
                scanf("%s", subject);
                
                printf("Enter body: ");
                scanf(" %[^\n]s", body);
                
                send_email(sender_name, recipient_name, subject, body);
                
                break;
            }
            case 2:
            {
                view_inbox();
                break;
            }
            case 3:
            {
                printf("Quitting...\n");
                break;
            }
            default:
            {
                printf("Invalid Choice!\n");
                break;
            }
        }
    } while(choice != 3);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Email Client ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_EMAILS 1024

struct Email {
    char sender[100];
    char receiver[100];
    char subject[100];
    char message[1000];
    char date[100];
};

struct Email emails[MAX_EMAILS];
int num_emails = 0;

void compose_email() {
    struct Email new_email;
    printf("Enter sender email: ");
    scanf("%s", new_email.sender);
    printf("Enter receiver email: ");
    scanf("%s", new_email.receiver);
    printf("Enter email subject: ");
    scanf("%s", new_email.subject);
    printf("Enter email message: ");
    scanf("%s", new_email.message);
    printf("Enter date in dd/mm/yyyy format: ");
    scanf("%s", new_email.date);
    emails[num_emails++] = new_email;
    printf("Email sent successfully!\n");
}

int search_email(char keyword[]) {
    int found = 0;
    for(int i=0; i<num_emails; i++) {
        if(strstr(emails[i].sender, keyword) || strstr(emails[i].receiver, keyword) || strstr(emails[i].subject, keyword) || strstr(emails[i].message, keyword)) {
            printf("Email #%d\nSender: %s\nReceiver: %s\nSubject: %s\nMessage: %s\nDate: %s\n\n", i+1, emails[i].sender, emails[i].receiver, emails[i].subject, emails[i].message, emails[i].date);
            found = 1;
        }
    }
    return found;
}

void search_emails() {
    char keyword[100];
    printf("Enter keyword to search: ");
    scanf("%s", keyword);
    int result = search_email(keyword);
    if(!result) {
        printf("No emails found!\n");
    }
}

void display_emails() {
    if(num_emails == 0) {
        printf("No emails to show!\n");
    } else {
        for(int i=0; i<num_emails; i++) {
            printf("Email #%d\nSender: %s\nReceiver: %s\nSubject: %s\nMessage: %s\nDate: %s\n\n", i+1, emails[i].sender, emails[i].receiver, emails[i].subject, emails[i].message, emails[i].date);
        }
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    while(1) {
        printf("Enter command (compose, search, display, exit): ");
        scanf("%s", command);
        if(strcmp(command, "compose") == 0) {
            compose_email();
        } else if(strcmp(command, "search") == 0) {
            search_emails();
        } else if(strcmp(command, "display") == 0) {
            display_emails();
        } else if(strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid command! Try again.\n");
        }
    }
    return 0;
}
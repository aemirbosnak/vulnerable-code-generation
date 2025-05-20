//FormAI DATASET v1.0 Category: Email Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 10
#define MAX_SUBJECT_LEN 50
#define MAX_BODY_LEN 100
#define MAX_NAME_LEN 20

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    char sender[MAX_NAME_LEN];
    char recipient[MAX_NAME_LEN];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void print_email(Email e) {
    printf("From: %s\n", e.sender);
    printf("To: %s\n", e.recipient);
    printf("Subject: %s\n", e.subject);
    printf("Body: %s\n", e.body);
}

void print_inbox() {
    if(num_emails == 0) {
        printf("No emails in inbox.\n");
    }
    else {
        printf("Inbox:\n");
        for(int i=0; i<num_emails; i++) {
            printf("Email %d:\n", i+1);
            print_email(emails[i]);
            printf("\n");
        }
    }
}

void send_email() {
    if(num_emails == MAX_EMAILS) {
        printf("Inbox is full. Cannot send email.\n");
    }
    else {
        Email new_email;
        printf("Enter sender name: ");
        scanf("%s", new_email.sender);
        printf("Enter recipient name: ");
        scanf("%s", new_email.recipient);
        printf("Enter email subject: ");
        scanf("%s", new_email.subject);
        printf("Enter email body: ");
        scanf("%s", new_email.body);

        emails[num_emails++] = new_email;
        printf("Email sent!\n");
    }
}

int main() {
    printf("Welcome to the Ephemeral Email Client!\n");

    while(1) {
        printf("Enter 'P' to print inbox, 'S' to send email, or 'Q' to quit: ");
        char input[10];
        scanf("%s", input);

        if(strcmp(input, "P") == 0) {
            print_inbox();
        }
        else if(strcmp(input, "S") == 0) {
            send_email();
        }
        else if(strcmp(input, "Q") == 0) {
            printf("Goodbye!\n");
            return 0;
        }
        else {
            printf("Invalid input. Try again.\n");
        }
    }
}
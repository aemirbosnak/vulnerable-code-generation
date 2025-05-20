//FormAI DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Email {
    char to[50];
    char from[50];
    char subject[100];
    char body[500];
};

void send_email(struct Email email) {
    printf("Preparing to send email...\n");
    printf("To: %s\n", email.to);
    printf("From: %s\n", email.from);
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s\n", email.body);
    printf("Sending email...\n");
}

void receive_email() {
    char email[1000];
    printf("Receiving email...\n");
    printf("Type the contents of the email below:\n");
    scanf("%[^\n]", email);
    printf("You received an email:\n%s\n", email);
}

int main() {
    printf("Welcome to the C Email Client\n");
    while(1) {
        printf("Menu:\n");
        printf("1. Send Email\n");
        printf("2. Receive Email\n");
        printf("3. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Preparing to compose email...\n");
                struct Email new_email;
                printf("To: ");
                scanf("%s", new_email.to);
                printf("From: ");
                scanf("%s", new_email.from);
                printf("Subject: ");
                scanf("%s", new_email.subject);
                printf("Body: ");
                scanf("%s", new_email.body);
                send_email(new_email);
                break;
            case 2:
                receive_email();
                break;
            case 3:
                printf("Exiting C Email Client. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}
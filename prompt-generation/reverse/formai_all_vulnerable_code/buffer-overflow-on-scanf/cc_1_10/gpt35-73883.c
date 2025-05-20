//FormAI DATASET v1.0 Category: Email Client ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500

typedef struct Email {
    char from[50];
    char to[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

int num_emails = 0;
int current_index = 0;
Email emails[MAX_EMAILS];

void send_email() {
    // code for sending email goes here
}

void compose_email() {
    // code for composing email goes here
}

void view_emails() {
    printf("You have %d emails.\n", num_emails);
    for (int i = 0; i < num_emails; i++) {
        printf("Email #%d:\n", i+1);
        printf("From: %s\n", emails[i].from);
        printf("To: %s\n", emails[i].to);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n\n", emails[i].body);
    }
}

int main() {
    printf("Welcome to my email client!\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Compose new email\n");
        printf("2. View emails\n");
        printf("3. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                compose_email();
                break;
            case 2:
                view_emails();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
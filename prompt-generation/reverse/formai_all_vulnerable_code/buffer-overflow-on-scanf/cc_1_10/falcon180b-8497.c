//Falcon-180B DATASET v1.0 Category: Email Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1024

typedef struct {
    char subject[MAX_EMAIL_LENGTH];
    char sender[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];
} email_t;

int num_emails = 0;
email_t emails[MAX_EMAILS];

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Email inbox is full.\n");
        return;
    }

    printf("Enter email subject: ");
    scanf("%s", emails[num_emails].subject);

    printf("Enter email sender: ");
    scanf("%s", emails[num_emails].sender);

    printf("Enter email body: ");
    scanf("%s", emails[num_emails].body);

    num_emails++;
}

void read_email(int index) {
    if (index < 0 || index >= num_emails) {
        printf("Error: Invalid email index.\n");
        return;
    }

    printf("Subject: %s\n", emails[index].subject);
    printf("Sender: %s\n", emails[index].sender);
    printf("Body: %s\n", emails[index].body);
}

int main() {
    char choice;

    do {
        printf("\nWelcome to the email client!\n");
        printf("1. Add email\n");
        printf("2. Read email\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            add_email();
            break;
        case '2':
            printf("Enter email index: ");
            int index = atoi(scanf("%d", &index));
            read_email(index);
            break;
        case '3':
            printf("Exiting email client...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '3');

    return 0;
}
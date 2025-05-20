//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME 50
#define MAX_SUBJECT 100

typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAILS];
    char subject[MAX_SUBJECT];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char *name, char *email, char *subject) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }
    strcpy(emails[num_emails].name, name);
    strcpy(emails[num_emails].email, email);
    strcpy(emails[num_emails].subject, subject);
    num_emails++;
}

void send_emails() {
    for (int i = 0; i < num_emails; i++) {
        printf("Sending email to %s (%s) about %s...\n", emails[i].name, emails[i].email, emails[i].subject);
    }
}

void main() {
    printf("Welcome to the mailing list manager!\n");
    char choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("A - Add an email\n");
        printf("S - Send emails\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);
        switch (choice) {
            case 'A':
                printf("Enter name: ");
                scanf("%s", emails[num_emails].name);
                printf("Enter email: ");
                scanf("%s", emails[num_emails].email);
                printf("Enter subject: ");
                scanf("%s", emails[num_emails].subject);
                num_emails++;
                printf("\nEmail added successfully!\n");
                break;
            case 'S':
                send_emails();
                break;
            case 'Q':
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice!= 'Q');
}
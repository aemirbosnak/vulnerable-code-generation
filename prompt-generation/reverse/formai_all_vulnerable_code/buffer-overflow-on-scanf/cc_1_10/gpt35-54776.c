//FormAI DATASET v1.0 Category: Mailing list manager ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// maximum number of emails that can be stored
#define MAX_EMAILS 1000

// email structure
struct email {
    char to[100];
    char from[100];
    char subject[100];
    char message[1000];
};

// function prototypes
void add_email();
void display_emails();
void search_emails();

// global variable to keep track of number of emails stored
int num_emails = 0;

// array of email structures to store emails
struct email emails[MAX_EMAILS];

int main() {
    int choice;

    // continuously display menu until user quits
    while (1) {
        printf("1. Add an email\n");
        printf("2. Display all emails\n");
        printf("3. Search for an email\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                display_emails();
                break;
            case 3:
                search_emails();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

// function to add an email to the array of emails
void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Maximum number of emails reached\n");
        return;
    }

    struct email new_email;

    printf("To: ");
    scanf("%s", new_email.to);

    printf("From: ");
    scanf("%s", new_email.from);

    printf("Subject: ");
    scanf("%s", new_email.subject);

    printf("Message: ");
    scanf("%s", new_email.message);

    // add new email to array of emails
    emails[num_emails] = new_email;
    num_emails++;

    printf("Email added successfully\n");
}

// function to display all emails in the array
void display_emails() {
    if (num_emails == 0) {
        printf("No emails to display\n");
        return;
    }

    printf("To           From         Subject            Message\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < num_emails; i++) {
        printf("%-12s %-12s %-20s %-25s\n", emails[i].to, emails[i].from, emails[i].subject, emails[i].message);
    }
}

// function to search for an email
void search_emails() {
    if (num_emails == 0) {
        printf("No emails to search\n");
        return;
    }

    char search_string[100];

    printf("Enter search string: ");
    scanf("%s", search_string);

    printf("To           From         Subject            Message\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < num_emails; i++) {
        // perform search on all fields of email
        if (strstr(emails[i].to, search_string) != NULL ||
            strstr(emails[i].from, search_string) != NULL ||
            strstr(emails[i].subject, search_string) != NULL ||
            strstr(emails[i].message, search_string) != NULL) {
            printf("%-12s %-12s %-20s %-25s\n", emails[i].to, emails[i].from, emails[i].subject, emails[i].message);
        }
    }
}
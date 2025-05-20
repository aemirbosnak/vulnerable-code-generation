//FormAI DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100 // maximum number of emails that can be stored
#define MAX_SUBJECT_SIZE 100 // maximum length of email subject
#define MAX_BODY_SIZE 500 // maximum length of email body
#define MAX_EMAIL_SIZE 1000 // maximum length of email including subject, body, to, cc fields
#define MAX_RECIPIENTS 10 // maximum number of recipients per email

typedef struct {
    char to[MAX_EMAIL_SIZE];
    char cc[MAX_EMAIL_SIZE];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];
} Email;

int num_emails = 0;
Email emails[MAX_EMAILS];

void print_menu() {
    printf("\n\nWelcome to C Email Client!\n");
    printf("1. Compose new email\n");
    printf("2. View emails\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
}

void compose_email() {
    char to[MAX_EMAIL_SIZE] = "", cc[MAX_EMAIL_SIZE] = "", subject[MAX_SUBJECT_SIZE] = "", body[MAX_BODY_SIZE] = "";
    char recipients[MAX_EMAIL_SIZE] = "";
    char *token;

    printf("\nEnter email address(es) of recipient(s) separated by commas: ");
    fgets(recipients, MAX_EMAIL_SIZE, stdin);
    recipients[strcspn(recipients, "\n")] = '\0'; // remove newline character if present

    token = strtok(recipients, ",");
    while (token != NULL) {
        if (strlen(to) == 0) {
            strcpy(to, token);
        } else if (strlen(cc) == 0) {
            strcpy(cc, token);
        }
        token = strtok(NULL, ",");
    }

    printf("Enter email subject: ");
    fgets(subject, MAX_SUBJECT_SIZE, stdin);
    subject[strcspn(subject, "\n")] = '\0';

    printf("Enter email body: ");
    fgets(body, MAX_BODY_SIZE, stdin);
    body[strcspn(body, "\n")] = '\0';

    Email new_email;
    strcpy(new_email.to, to);
    strcpy(new_email.cc, cc);
    strcpy(new_email.subject, subject);
    strcpy(new_email.body, body);

    emails[num_emails++] = new_email;

    printf("\nEmail sent successfully!");
}

void view_emails() {
    if (num_emails == 0) {
        printf("\nNo emails to display.");
    } else {
        printf("\n\n------------EMAILS------------\n\n");
        for (int i = 0; i < num_emails; i++) {
            printf("Email %d:\nTo: %s\nCc: %s\nSubject: %s\nBody: %s\n\n", i+1, emails[i].to, emails[i].cc, emails[i].subject, emails[i].body);
        }
    }    
}

int main() {
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);
        getchar(); // remove newline character from stdin

        switch (choice) {
            case 1:
                compose_email();
                break;
            case 2:
                view_emails();
                break;
            case 3:
                printf("\nThank you for using C Email Client!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Email Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char from[MAX_EMAILS][100];
    char subject[MAX_EMAILS][MAX_SUBJECT_LENGTH];
    char body[MAX_EMAILS][MAX_BODY_LENGTH];
    time_t date[MAX_EMAILS];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    char from[100];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t date;

    printf("Enter the sender's email address: ");
    scanf("%s", from);

    printf("Enter the subject: ");
    scanf("%s", subject);

    printf("Enter the body of the email: ");
    fgets(body, MAX_BODY_LENGTH, stdin);
    body[strcspn(body, "\n")] = '\0';

    date = time(NULL);

    strcpy(emails[num_emails].from[num_emails], from);
    strcpy(emails[num_emails].subject[num_emails], subject);
    strcpy(emails[num_emails].body[num_emails], body);
    emails[num_emails].date[num_emails] = date;

    num_emails++;
}

void view_emails() {
    int i, j;

    printf("Email Sender    Subject                 Date\n");
    printf("-----------------------------------------------------\n");

    for (i = 0; i < num_emails; i++) {
        printf("%-20s ", emails[i].from[i]);
        printf("%-40s ", emails[i].subject[i]);
        printf("%-20s ", ctime(&emails[i].date[i]));
    }
}

void main() {
    int choice;

    do {
        printf("\nEmail Client\n");
        printf("1. Add Email\n");
        printf("2. View Emails\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                view_emails();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);
}
//Falcon-180B DATASET v1.0 Category: Email Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 1000
#define SUBJECT_LEN 100
#define BODY_LEN 1000
#define FROM_LEN 100
#define TO_LEN 100
#define CC_LEN 100
#define DATE_LEN 30

typedef struct email {
    char subject[SUBJECT_LEN];
    char body[BODY_LEN];
    char from[FROM_LEN];
    char to[TO_LEN];
    char cc[CC_LEN];
    char date[DATE_LEN];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    printf("Enter subject: ");
    scanf("%s", emails[num_emails].subject);

    printf("Enter body: ");
    scanf("%s", emails[num_emails].body);

    printf("Enter from: ");
    scanf("%s", emails[num_emails].from);

    printf("Enter to: ");
    scanf("%s", emails[num_emails].to);

    printf("Enter cc: ");
    scanf("%s", emails[num_emails].cc);

    time_t now = time(NULL);
    strftime(emails[num_emails].date, DATE_LEN, "%Y-%m-%d %H:%M:%S", localtime(&now));

    num_emails++;
}

void view_emails() {
    if (num_emails == 0) {
        printf("No emails found.\n");
        return;
    }

    for (int i = 0; i < num_emails; i++) {
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n", emails[i].body);
        printf("From: %s\n", emails[i].from);
        printf("To: %s\n", emails[i].to);
        printf("CC: %s\n", emails[i].cc);
        printf("Date: %s\n\n", emails[i].date);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add email\n");
        printf("2. View emails\n");
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
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}
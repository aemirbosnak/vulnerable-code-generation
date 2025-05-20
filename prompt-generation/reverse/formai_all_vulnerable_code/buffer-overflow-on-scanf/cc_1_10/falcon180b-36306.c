//Falcon-180B DATASET v1.0 Category: Email Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 1000
#define SUBJECT_LENGTH 100
#define BODY_LENGTH 1000
#define FROM_LENGTH 100
#define TO_LENGTH 100
#define CC_LENGTH 100
#define BCC_LENGTH 100
#define DATE_LENGTH 20

typedef struct email {
    char subject[SUBJECT_LENGTH];
    char from[FROM_LENGTH];
    char to[TO_LENGTH];
    char cc[CC_LENGTH];
    char bcc[BCC_LENGTH];
    char body[BODY_LENGTH];
    char date[DATE_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    Email new_email;
    printf("Enter subject: ");
    scanf("%s", new_email.subject);
    printf("Enter from: ");
    scanf("%s", new_email.from);
    printf("Enter to: ");
    scanf("%s", new_email.to);
    printf("Enter cc: ");
    scanf("%s", new_email.cc);
    printf("Enter bcc: ");
    scanf("%s", new_email.bcc);
    printf("Enter body: ");
    scanf("%[^\n]", new_email.body);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", new_email.date);

    emails[num_emails] = new_email;
    num_emails++;
}

void view_emails() {
    if (num_emails == 0) {
        printf("No emails found.\n");
        return;
    }

    for (int i = 0; i < num_emails; i++) {
        printf("Email %d:\n", i + 1);
        printf("Subject: %s\n", emails[i].subject);
        printf("From: %s\n", emails[i].from);
        printf("To: %s\n", emails[i].to);
        printf("Cc: %s\n", emails[i].cc);
        printf("Bcc: %s\n", emails[i].bcc);
        printf("Body: %s\n", emails[i].body);
        printf("Date: %s\n\n", emails[i].date);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add email\n2. View emails\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                view_emails();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}
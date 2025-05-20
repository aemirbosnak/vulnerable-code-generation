//Falcon-180B DATASET v1.0 Category: Email Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Email limit reached.\n");
        return;
    }

    Email new_email;
    printf("Enter subject (max %d characters): ", MAX_SUBJECT_LENGTH - 1);
    scanf("%s", new_email.subject);

    printf("Enter body (max %d characters): ", MAX_BODY_LENGTH - 1);
    fgets(new_email.body, MAX_BODY_LENGTH, stdin);
    new_email.body[strcspn(new_email.body, "\n")] = '\0';

    time_t now = time(NULL);
    new_email.timestamp = now;

    emails[num_emails] = new_email;
    num_emails++;

    printf("Email added successfully.\n");
}

void view_emails() {
    if (num_emails == 0) {
        printf("No emails found.\n");
        return;
    }

    for (int i = 0; i < num_emails; i++) {
        Email email = emails[i];
        printf("Email %d:\n");
        printf("Subject: %s\n", email.subject);
        printf("Body:\n%s\n", email.body);
        printf("Timestamp: %s\n\n", ctime(&email.timestamp));
    }
}

int main() {
    char choice;
    do {
        printf("Email Client\n");
        printf("1. Add email\n");
        printf("2. View emails\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_email();
                break;
            case '2':
                view_emails();
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '3');

    return 0;
}
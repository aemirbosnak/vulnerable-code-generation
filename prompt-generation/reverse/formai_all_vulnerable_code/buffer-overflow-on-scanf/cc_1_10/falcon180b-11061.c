//Falcon-180B DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_FROM_LENGTH 256
#define MAX_TO_LENGTH 256
#define MAX_BODY_LENGTH 4096

typedef struct {
    char from[MAX_FROM_LENGTH];
    char to[MAX_TO_LENGTH];
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

    Email *email = &emails[num_emails];

    printf("Enter from: ");
    scanf("%s", email->from);

    printf("Enter to: ");
    scanf("%s", email->to);

    printf("Enter subject: ");
    scanf("%s", email->subject);

    printf("Enter body: ");
    scanf("%[^\n]", email->body);

    email->timestamp = time(NULL);
    num_emails++;
}

void list_emails() {
    if (num_emails == 0) {
        printf("No emails.\n");
        return;
    }

    for (int i = 0; i < num_emails; i++) {
        Email *email = &emails[i];
        printf("%d. From: %s\nTo: %s\nSubject: %s\nTimestamp: %s\n\n", i+1, email->from, email->to, email->subject, ctime(&email->timestamp));
    }
}

void search_emails() {
    char search_term[MAX_SUBJECT_LENGTH];

    printf("Enter search term: ");
    scanf("%s", search_term);

    for (int i = 0; i < num_emails; i++) {
        Email *email = &emails[i];
        if (strstr(email->subject, search_term)) {
            printf("%d. From: %s\nTo: %s\nSubject: %s\nTimestamp: %s\n\n", i+1, email->from, email->to, email->subject, ctime(&email->timestamp));
        }
    }
}

int main() {
    char choice;

    while (1) {
        printf("Email Client\n");
        printf("A. Add email\n");
        printf("L. List emails\n");
        printf("S. Search emails\n");
        printf("Q. Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                add_email();
                break;
            case 'L':
                list_emails();
                break;
            case 'S':
                search_emails();
                break;
            case 'Q':
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
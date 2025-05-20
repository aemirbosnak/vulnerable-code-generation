//Falcon-180B DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 10000

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(Email* email) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }
    emails[num_emails++] = *email;
}

void print_emails() {
    printf("Total emails: %d\n", num_emails);
    for (int i = 0; i < num_emails; i++) {
        printf("From: %s\n", emails[i].from);
        printf("To: %s\n", emails[i].to);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n", emails[i].body);
        printf("Timestamp: %s\n\n", ctime(&emails[i].timestamp));
    }
}

int main() {
    char input[MAX_EMAIL_LENGTH];
    Email email;

    while (1) {
        printf("Enter email (q to quit):\n");
        fgets(input, MAX_EMAIL_LENGTH, stdin);
        if (strcmp(input, "q") == 0) {
            break;
        }
        if (sscanf(input, "%s %s %s %s", email.from, email.to, email.subject, email.body)!= 4) {
            printf("Invalid email format.\n");
            continue;
        }
        email.timestamp = time(NULL);
        add_email(&email);
    }

    print_emails();

    return 0;
}
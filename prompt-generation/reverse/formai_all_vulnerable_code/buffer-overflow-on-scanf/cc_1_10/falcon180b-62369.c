//Falcon-180B DATASET v1.0 Category: Email Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 1000

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];
    int length;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];
    int length;

    printf("Enter the sender's email address: ");
    scanf("%s", from);

    printf("Enter the recipient's email address: ");
    scanf("%s", to);

    printf("Enter the email subject: ");
    scanf("%s", subject);

    printf("Enter the email body: ");
    scanf("%s", body);

    length = strlen(body);

    strcpy(emails[num_emails].from, from);
    strcpy(emails[num_emails].to, to);
    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);
    emails[num_emails].length = length;

    num_emails++;
}

void print_emails() {
    int i;

    for (i = 0; i < num_emails; i++) {
        printf("From: %s\n", emails[i].from);
        printf("To: %s\n", emails[i].to);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n", emails[i].body);
        printf("Length: %d\n\n", emails[i].length);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add email\n");
        printf("2. Print emails\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_email();
            break;
        case 2:
            print_emails();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}
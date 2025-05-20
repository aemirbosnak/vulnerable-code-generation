//Falcon-180B DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 10000

typedef struct {
    char from[MAX_EMAILS][MAX_EMAILS];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* from, char* subject, char* body) {
    strcpy(emails[num_emails].from[0], from);
    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);
    emails[num_emails].timestamp = time(NULL);
    num_emails++;
}

void print_emails() {
    for (int i = 0; i < num_emails; i++) {
        printf("From: %s\n", emails[i].from[0]);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body:\n%s\n", emails[i].body);
        printf("Timestamp: %s\n\n", ctime(&emails[i].timestamp));
    }
}

int main() {
    char input[MAX_EMAILS][MAX_EMAILS];
    char from[MAX_EMAILS][MAX_EMAILS];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int num_words = 0;
    char word[MAX_EMAILS][MAX_EMAILS];
    int i, j, k;

    printf("Welcome to the email client!\n");

    while (1) {
        printf("Enter 'r' to read emails or's' to send an email: ");
        scanf("%s", input);

        if (strcmp(input, "r") == 0) {
            print_emails();
        } else if (strcmp(input, "s") == 0) {
            printf("Enter the recipient's email address: ");
            scanf("%s", from);

            printf("Enter the subject: ");
            scanf("%s", subject);

            printf("Enter the body: ");
            fgets(body, MAX_BODY_LENGTH, stdin);

            add_email(from, subject, body);
            printf("Email sent successfully!\n");
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
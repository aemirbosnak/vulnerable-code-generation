//Falcon-180B DATASET v1.0 Category: Email Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

int main() {
    char input[MAX_EMAIL_LENGTH];
    Email emails[MAX_EMAILS];
    int num_emails = 0;

    printf("Welcome to the Medieval Email Client!\n");
    printf("Enter 'R' to read an email, 'W' to write an email, or 'Q' to quit.\n");

    while (1) {
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "R") == 0) {
            if (num_emails == 0) {
                printf("No emails to read.\n");
            } else {
                printf("Enter email number to read: ");
                scanf("%d", &num_emails);

                printf("From: %s\n", emails[num_emails-1].from);
                printf("To: %s\n", emails[num_emails-1].to);
                printf("Subject: %s\n", emails[num_emails-1].subject);
                printf("Body: %s\n", emails[num_emails-1].body);
            }
        } else if (strcmp(input, "W") == 0) {
            printf("Enter email address: ");
            scanf("%s", emails[num_emails].from);

            printf("Enter recipient email address: ");
            scanf("%s", emails[num_emails].to);

            printf("Enter subject: ");
            scanf("%s", emails[num_emails].subject);

            printf("Enter body: ");
            scanf("%s", emails[num_emails].body);

            num_emails++;
        } else if (strcmp(input, "Q") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
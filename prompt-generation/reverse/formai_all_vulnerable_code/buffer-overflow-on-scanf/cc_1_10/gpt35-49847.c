//FormAI DATASET v1.0 Category: Email Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails;

int send_email(char *sender, char *recipient, char *subject, char *body) {
    if (num_emails >= MAX_EMAILS) {
        return -1; // max emails reached
    }
    Email new_email;
    strcpy(new_email.sender, sender);
    strcpy(new_email.recipient, recipient);
    strcpy(new_email.subject, subject);
    strcpy(new_email.body, body);
    emails[num_emails] = new_email;
    num_emails++;
    return 0; // successfully sent email
}

void print_emails() {
    printf("---- Emails ----\n");
    for (int i = 0; i < num_emails; i++) {
        printf("From: %s\n", emails[i].sender);
        printf("To: %s\n", emails[i].recipient);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n", emails[i].body);
        printf("---------------\n");
    }
}

int main() {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];

    while (1) {
        printf("Enter sender (or q to quit): ");
        scanf("%s", sender);
        if (strcmp(sender, "q") == 0) {
            break;
        }

        printf("Enter recipient: ");
        scanf("%s", recipient);

        printf("Enter subject: ");
        getchar(); // consume the newline character
        fgets(subject, MAX_SUBJECT_LENGTH, stdin);
        subject[strcspn(subject, "\n")] = 0; // remove trailing newline

        printf("Enter body: ");
        fgets(body, MAX_BODY_LENGTH, stdin);
        body[strcspn(body, "\n")] = 0; // remove trailing newline

        int result = send_email(sender, recipient, subject, body);
        if (result == -1) {
            printf("Failed to send email. Maximum number of emails reached.\n");
            break;
        } else {
            printf("Email sent successfully.\n");
        }
    }

    print_emails();
    return 0;
}
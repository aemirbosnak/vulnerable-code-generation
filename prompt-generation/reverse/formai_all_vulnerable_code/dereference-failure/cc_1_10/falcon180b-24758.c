//Falcon-180B DATASET v1.0 Category: Email Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 5000

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email* createEmail() {
    Email* email = (Email*) malloc(sizeof(Email));
    strcpy(email->from, "");
    strcpy(email->to, "");
    strcpy(email->subject, "");
    strcpy(email->body, "");
    return email;
}

void printEmail(Email* email) {
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
}

int main() {
    Email* email = createEmail();

    printf("Enter the sender's email address: ");
    scanf("%s", email->from);

    printf("Enter the recipient's email address: ");
    scanf("%s", email->to);

    printf("Enter the email subject: ");
    scanf("%s", email->subject);

    printf("Enter the email body:\n");
    char ch;
    while ((ch = getchar())!= '\n') {
        if (strlen(email->body) >= MAX_BODY_LENGTH) {
            printf("Error: Body exceeded maximum length.\n");
            exit(1);
        }
        email->body[strlen(email->body)] = ch;
    }
    email->body[strlen(email->body)] = '\0';

    printEmail(email);

    free(email);
    return 0;
}
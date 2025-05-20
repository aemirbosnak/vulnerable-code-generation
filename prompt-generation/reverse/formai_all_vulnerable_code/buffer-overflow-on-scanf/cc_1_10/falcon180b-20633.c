//Falcon-180B DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 5000
#define MAX_RECIPIENTS 10
#define MAX_CC_RECIPIENTS 10
#define MAX_BCC_RECIPIENTS 10
#define MAX_ATTACHMENTS 5

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char cc[MAX_EMAIL_LENGTH];
    char bcc[MAX_EMAIL_LENGTH];
    char attachment_path[MAX_EMAIL_LENGTH];
} Email;

void send_email(Email *email) {
    FILE *fp;
    char cmd[MAX_EMAIL_LENGTH];

    sprintf(cmd, "echo \"%s\" | ssmtp %s", email->body, email->to);
    system(cmd);
}

int main() {
    Email email;
    char input[MAX_EMAIL_LENGTH];
    int i = 0;

    printf("Enter your email address: ");
    scanf("%s", email.from);

    printf("Enter the recipient's email address: ");
    scanf("%s", email.to);

    printf("Enter the subject: ");
    scanf("%s", email.subject);

    printf("Enter the body: ");
    scanf("%s", email.body);

    printf("Enter attachment path (if any): ");
    scanf("%s", email.attachment_path);

    send_email(&email);

    return 0;
}
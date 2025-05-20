//Falcon-180B DATASET v1.0 Category: Email Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10
#define MAX_FILES 10

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char to[MAX_RECIPIENTS][50];
    int num_recipients;
    char files[MAX_FILES][100];
    int num_files;
} email_t;

void send_email(email_t *email) {
    printf("Sending email...\n");
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
    printf("Recipients:\n");
    for (int i = 0; i < email->num_recipients; i++) {
        printf("%s\n", email->to[i]);
    }
    printf("Files:\n");
    for (int i = 0; i < email->num_files; i++) {
        printf("%s\n", email->files[i]);
    }
}

int main() {
    email_t email;
    memset(&email, 0, sizeof(email));

    printf("Enter the email subject: ");
    scanf("%s", email.subject);

    printf("Enter the email body:\n");
    fgets(email.body, MAX_BODY_LENGTH, stdin);
    email.body[strcspn(email.body, "\n")] = '\0';

    int num_recipients = 0;
    printf("Enter the number of recipients: ");
    scanf("%d", &num_recipients);
    for (int i = 0; i < num_recipients; i++) {
        printf("Enter recipient %d:\n", i+1);
        scanf("%s", email.to[i]);
    }

    int num_files = 0;
    printf("Enter the number of files to attach: ");
    scanf("%d", &num_files);
    for (int i = 0; i < num_files; i++) {
        printf("Enter file %d:\n", i+1);
        scanf("%s", email.files[i]);
    }

    send_email(&email);

    return 0;
}
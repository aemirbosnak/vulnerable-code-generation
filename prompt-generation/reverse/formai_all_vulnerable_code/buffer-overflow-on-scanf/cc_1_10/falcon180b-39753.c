//Falcon-180B DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_RECIPIENTS 10
#define MAX_RECIPIENT_LENGTH 256

typedef struct {
    char name[MAX_RECIPIENT_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} recipient;

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[1024];
    int num_recipients;
    recipient recipients[MAX_RECIPIENTS];
} email;

int main() {
    email email;
    char input[1024];
    int i;

    printf("Enter your email address: ");
    scanf("%s", email.from);

    printf("Enter recipient email address: ");
    scanf("%s", email.to);

    printf("Enter email subject: ");
    scanf("%s", email.subject);

    printf("Enter email body: ");
    scanf("%s", email.body);

    printf("Number of recipients: ");
    scanf("%d", &email.num_recipients);

    for (i = 0; i < email.num_recipients; i++) {
        printf("Enter recipient %d name: ", i+1);
        scanf("%s", email.recipients[i].name);
        printf("Enter recipient %d email: ", i+1);
        scanf("%s", email.recipients[i].email);
    }

    email.recipients[email.num_recipients-1].name[0] = '\0';
    email.recipients[email.num_recipients-1].email[0] = '\0';

    printf("Email:\n");
    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s", email.body);

    for (i = 0; i < email.num_recipients; i++) {
        printf("Recipient %d:\nName: %s\nEmail: %s\n", i+1, email.recipients[i].name, email.recipients[i].email);
    }

    return 0;
}
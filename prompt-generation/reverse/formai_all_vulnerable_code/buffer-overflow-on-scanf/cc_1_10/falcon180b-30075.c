//Falcon-180B DATASET v1.0 Category: Email Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char recipients[MAX_RECIPIENTS][50];
    int num_recipients;
} Email;

void send_email(Email* email) {
    printf("Sending email:\n");
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
    for (int i = 0; i < email->num_recipients; i++) {
        printf("Recipient %d: %s\n", i+1, email->recipients[i]);
    }
}

int main() {
    Email email;
    email.num_recipients = 0;

    printf("Enter the subject of the email: ");
    scanf("%[^\n]", email.subject);

    printf("Enter the body of the email:\n");
    fgets(email.body, MAX_BODY_LENGTH, stdin);

    char input[100];
    while (1) {
        printf("Enter a recipient (or type 'done' to finish): ");
        scanf("%[^\n]", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        strcpy(email.recipients[email.num_recipients], input);
        email.num_recipients++;

        if (email.num_recipients >= MAX_RECIPIENTS) {
            printf("You can only have up to %d recipients.\n", MAX_RECIPIENTS);
            break;
        }
    }

    send_email(&email);

    return 0;
}
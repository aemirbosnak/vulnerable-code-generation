//Falcon-180B DATASET v1.0 Category: Email Client ; Style: surprised
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
    char recipient[MAX_RECIPIENTS][100];
    int num_recipients;
} Email;

Email create_email() {
    Email email = {
       .subject = "",
       .body = "",
       .num_recipients = 0
    };
    return email;
}

void add_recipient(Email* email, char* recipient) {
    if (email->num_recipients >= MAX_RECIPIENTS) {
        printf("Error: Maximum number of recipients reached.\n");
        return;
    }
    strcpy(email->recipient[email->num_recipients], recipient);
    email->num_recipients++;
}

void send_email(Email email) {
    printf("Sending email:\n");
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s\n", email.body);
    printf("Recipients:\n");
    for (int i = 0; i < email.num_recipients; i++) {
        printf("%s\n", email.recipient[i]);
    }
}

int main() {
    Email email = create_email();

    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char recipient[100];

    printf("Enter email subject: ");
    scanf("%s", subject);
    strcpy(email.subject, subject);

    printf("Enter email body:\n");
    fgets(body, MAX_BODY_LENGTH, stdin);
    body[strcspn(body, "\n")] = '\0';
    strcpy(email.body, body);

    int num_recipients;
    printf("Enter number of recipients: ");
    scanf("%d", &num_recipients);

    for (int i = 0; i < num_recipients; i++) {
        printf("Enter recipient %d: ", i+1);
        scanf("%s", recipient);
        add_recipient(&email, recipient);
    }

    send_email(email);

    return 0;
}
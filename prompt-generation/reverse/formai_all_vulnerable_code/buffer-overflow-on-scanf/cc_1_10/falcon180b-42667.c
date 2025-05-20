//Falcon-180B DATASET v1.0 Category: Email Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
    int num_recipients;
    char recipients[MAX_RECIPIENTS][MAX_SUBJECT_LENGTH];
} Email;

void send_email(Email* email) {
    printf("Sending email:\n");
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
    printf("Recipients: ");
    for (int i = 0; i < email->num_recipients; i++) {
        printf("%s ", email->recipients[i]);
    }
    printf("\n");
}

int main() {
    Email email;
    memset(&email, 0, sizeof(Email));

    printf("Enter subject: ");
    fgets(email.subject, MAX_SUBJECT_LENGTH, stdin);
    email.subject[strcspn(email.subject, "\n")] = '\0';

    printf("Enter body: ");
    fgets(email.body, MAX_BODY_LENGTH, stdin);
    email.body[strcspn(email.body, "\n")] = '\0';

    printf("Enter number of recipients: ");
    scanf("%d", &email.num_recipients);

    for (int i = 0; i < email.num_recipients; i++) {
        printf("Enter recipient %d: ", i+1);
        fgets(email.recipients[i], MAX_SUBJECT_LENGTH, stdin);
        email.recipients[i][strcspn(email.recipients[i], "\n")] = '\0';
    }

    time_t now = time(NULL);
    email.timestamp = now;

    send_email(&email);

    return 0;
}
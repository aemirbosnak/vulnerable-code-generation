//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10

typedef struct {
    char subject[MAX_SUBJECT_LENGTH+1];
    char body[MAX_BODY_LENGTH+1];
    char recipients[MAX_RECIPIENTS][50];
    int num_recipients;
} Email;

Email create_email() {
    Email email;
    strcpy(email.subject, "");
    strcpy(email.body, "");
    email.num_recipients = 0;
    return email;
}

void add_recipient(Email* email, char* recipient) {
    if (email->num_recipients < MAX_RECIPIENTS) {
        strcpy(email->recipients[email->num_recipients], recipient);
        email->num_recipients++;
    }
}

void send_email(Email email) {
    printf("Sending email with subject: %s\n", email.subject);
    printf("To: ");
    for (int i = 0; i < email.num_recipients; i++) {
        printf("%s ", email.recipients[i]);
    }
    printf("\n");
    printf("Body:\n%s\n", email.body);
}

int main() {
    Email email = create_email();

    printf("Enter subject: ");
    scanf("%[^\n]", email.subject);

    printf("Enter body: ");
    fgets(email.body, MAX_BODY_LENGTH, stdin);
    email.body[strcspn(email.body, "\n")] = '\0';

    int num_recipients;
    printf("Enter number of recipients: ");
    scanf("%d", &num_recipients);

    for (int i = 0; i < num_recipients; i++) {
        char recipient[50];
        printf("Enter recipient %d: ", i+1);
        scanf("%[^\n]", recipient);
        add_recipient(&email, recipient);
    }

    send_email(email);

    return 0;
}
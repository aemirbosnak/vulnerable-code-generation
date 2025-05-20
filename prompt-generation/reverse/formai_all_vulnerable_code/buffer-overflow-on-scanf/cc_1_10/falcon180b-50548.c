//Falcon-180B DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define MAX_RECIPIENTS 10

typedef struct {
    char name[50];
    char email[100];
} Recipient;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    int num_recipients;
    Recipient recipients[MAX_RECIPIENTS];
} Email;

void add_recipient(Email *email) {
    printf("Enter recipient name: ");
    scanf("%s", email->recipients[email->num_recipients].name);
    printf("Enter recipient email: ");
    scanf("%s", email->recipients[email->num_recipients].email);
    email->num_recipients++;
}

int main() {
    Email email;
    int i;

    printf("Enter subject: ");
    scanf("%s", email.subject);

    printf("Enter message: ");
    fgets(email.message, MAX_MESSAGE_LENGTH, stdin);

    email.num_recipients = 0;

    while (1) {
        printf("Enter recipient name (or type 'done' to finish): ");
        scanf("%s", email.recipients[email.num_recipients].name);

        if (strcmp(email.recipients[email.num_recipients].name, "done") == 0) {
            break;
        }

        printf("Enter recipient email: ");
        scanf("%s", email.recipients[email.num_recipients].email);

        email.num_recipients++;
    }

    printf("Sending email...\n");

    for (i = 0; i < email.num_recipients; i++) {
        printf("Sending to %s (%s)\n", email.recipients[i].name, email.recipients[i].email);
    }

    return 0;
}
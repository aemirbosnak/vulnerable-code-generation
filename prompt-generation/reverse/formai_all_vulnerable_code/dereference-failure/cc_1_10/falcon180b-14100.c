//Falcon-180B DATASET v1.0 Category: Email Client ; Style: artistic
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
} Email;

typedef struct {
    char name[MAX_RECIPIENTS][50];
    char email[MAX_RECIPIENTS][100];
} RecipientList;

int main() {
    Email email;
    RecipientList recipientList;
    int numRecipients;

    printf("Enter the subject of the email: ");
    scanf("%s", email.subject);

    printf("Enter the body of the email: ");
    fgets(email.body, MAX_BODY_LENGTH, stdin);
    email.body[strcspn(email.body, "\n")] = '\0';

    time(&email.timestamp);

    printf("Enter the number of recipients: ");
    scanf("%d", &numRecipients);

    printf("Enter the name and email address of each recipient (separated by a space):\n");
    for (int i = 0; i < numRecipients; i++) {
        scanf("%s %s", recipientList.name[i], recipientList.email[i]);
    }

    Email* emails = malloc(numRecipients * sizeof(Email));
    memcpy(emails, &email, sizeof(Email));

    for (int i = 0; i < numRecipients; i++) {
        strcpy(emails[i].body, recipientList.name[i]);
        strcat(emails[i].body, ",\n");
        strcat(emails[i].body, recipientList.email[i]);
        strcat(emails[i].body, "\n");
        strcat(emails[i].body, email.body);
    }

    for (int i = 0; i < numRecipients; i++) {
        printf("Sending email to %s (%s)\n", recipientList.name[i], recipientList.email[i]);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body:\n%s", emails[i].body);
    }

    return 0;
}
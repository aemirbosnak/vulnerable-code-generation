//Falcon-180B DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_RECIPIENTS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char name[MAX_RECIPIENTS][50];
    char email[MAX_RECIPIENTS][100];
} RecipientList;

typedef struct {
    char from[100];
    RecipientList to;
    RecipientList cc;
    RecipientList bcc;
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

void addRecipient(Email* email, int index, char* name, char* emailAddr) {
    strcpy(email->to.name[index], name);
    strcpy(email->to.email[index], emailAddr);
}

void addCc(Email* email, int index, char* name, char* emailAddr) {
    strcpy(email->cc.name[index], name);
    strcpy(email->cc.email[index], emailAddr);
}

void addBcc(Email* email, int index, char* name, char* emailAddr) {
    strcpy(email->bcc.name[index], name);
    strcpy(email->bcc.email[index], emailAddr);
}

int main() {
    Email email;
    int numRecipients = 0;
    int i;

    printf("Enter your name: ");
    scanf("%s", email.from);

    printf("Enter number of recipients: ");
    scanf("%d", &numRecipients);

    for (i = 0; i < numRecipients; i++) {
        char name[50];
        char emailAddr[100];

        printf("Enter recipient %d's name: ", i+1);
        scanf("%s", name);

        printf("Enter recipient %d's email address: ", i+1);
        scanf("%s", emailAddr);

        addRecipient(&email, i, name, emailAddr);
    }

    printf("Enter subject: ");
    scanf("%s", email.subject);

    printf("Enter body: ");
    fgets(email.body, MAX_BODY_LENGTH, stdin);

    time_t now = time(NULL);
    email.timestamp = now;

    printf("Email sent to %s\n", email.to.name[0]);

    return 0;
}
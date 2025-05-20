//Falcon-180B DATASET v1.0 Category: Email Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_ADDRESS_LENGTH 100
#define MAX_NUM_RECIPIENTS 10

typedef struct recipient {
    char name[MAX_ADDRESS_LENGTH];
    char email[MAX_ADDRESS_LENGTH];
} Recipient;

typedef struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int num_recipients;
    Recipient recipients[MAX_NUM_RECIPIENTS];
} Email;

void read_email(Email* email) {
    printf("Subject: ");
    fgets(email->subject, MAX_SUBJECT_LENGTH, stdin);
    email->subject[strcspn(email->subject, "\n")] = '\0';

    printf("Body: ");
    fgets(email->body, MAX_BODY_LENGTH, stdin);
    email->body[strcspn(email->body, "\n")] = '\0';

    printf("Number of recipients: ");
    scanf("%d", &email->num_recipients);

    for (int i = 0; i < email->num_recipients; i++) {
        printf("Recipient %d name: ", i+1);
        fgets(email->recipients[i].name, MAX_ADDRESS_LENGTH, stdin);
        email->recipients[i].name[strcspn(email->recipients[i].name, "\n")] = '\0';

        printf("Recipient %d email: ", i+1);
        fgets(email->recipients[i].email, MAX_ADDRESS_LENGTH, stdin);
        email->recipients[i].email[strcspn(email->recipients[i].email, "\n")] = '\0';
    }
}

void send_email(Email* email) {
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s", email->body);

    for (int i = 0; i < email->num_recipients; i++) {
        printf("Recipient %d: %s (%s)\n", i+1, email->recipients[i].name, email->recipients[i].email);
    }
}

int main() {
    Email email;
    read_email(&email);
    send_email(&email);

    return 0;
}
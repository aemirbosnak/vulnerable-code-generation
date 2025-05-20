//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_EMAIL 100
#define MAX_SUBJECT 100
#define MAX_MESSAGE 1000

typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
} contact;

typedef struct {
    contact recipient;
    char subject[MAX_SUBJECT];
    char message[MAX_MESSAGE];
} email;

void add_contact(contact *contacts, int *num_contacts) {
    printf("Enter name: ");
    scanf("%s", contacts[*num_contacts].name);
    printf("Enter email: ");
    scanf("%s", contacts[*num_contacts].email);
    (*num_contacts)++;
}

void send_email(email *emails, int num_emails, contact *contacts, int num_contacts) {
    for (int i = 0; i < num_emails; i++) {
        printf("Sending email to %s...\n", emails[i].recipient.name);
        printf("Subject: %s\n", emails[i].subject);
        printf("Message:\n%s\n", emails[i].message);
        printf("\n");
    }
}

int main() {
    int num_contacts = 0;
    contact contacts[100];

    add_contact(contacts, &num_contacts);
    add_contact(contacts, &num_contacts);

    email emails[100];
    int num_emails = 0;

    num_emails = 2;

    for (int i = 0; i < num_emails; i++) {
        printf("Enter recipient name: ");
        scanf("%s", emails[i].recipient.name);
        strcpy(emails[i].recipient.email, contacts[i%num_contacts].email);

        printf("Enter subject: ");
        scanf("%s", emails[i].subject);

        printf("Enter message: ");
        scanf("%[^\n]", emails[i].message);
    }

    send_email(emails, num_emails, contacts, num_contacts);

    return 0;
}
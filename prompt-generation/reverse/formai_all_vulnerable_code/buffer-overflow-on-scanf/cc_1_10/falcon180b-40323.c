//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 200
#define MAX_MESSAGE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
} email;

void add_contact(contact *contacts, int num_contacts, char *name, char *email) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].email, email) == 0) {
            strcpy(contacts[i].name, name);
            return;
        }
    }
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].email, email);
    num_contacts++;
}

void send_email(contact *contacts, int num_contacts, char *subject, char *message) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("Sending email to %s (%s)\n", contacts[i].name, contacts[i].email);
    }
}

int main() {
    contact contacts[100];
    int num_contacts = 0;
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];

    printf("Enter contact information (name email):\n");
    while (1) {
        printf("> ");
        scanf("%s %s", name, email);
        if (strcmp(name, "quit") == 0) {
            break;
        }
        add_contact(contacts, num_contacts, name, email);
        num_contacts++;
    }

    printf("Enter email subject:\n");
    scanf("%s", subject);

    printf("Enter email message:\n");
    fgets(message, MAX_MESSAGE_LEN, stdin);
    message[strcspn(message, "\n")] = '\0';

    send_email(contacts, num_contacts, subject, message);

    return 0;
}
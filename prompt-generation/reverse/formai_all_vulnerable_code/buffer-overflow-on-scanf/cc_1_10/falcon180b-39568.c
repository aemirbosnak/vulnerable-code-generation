//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

void add_contact(Contact* contacts, int num_contacts, char* name, char* email) {
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

void send_email(Contact* contacts, int num_contacts, char* subject, char* body) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        Email email;
        strcpy(email.subject, subject);
        strcpy(email.body, body);
        printf("Sending email to %s (%s)\n", contacts[i].name, contacts[i].email);
    }
}

int main() {
    Contact contacts[100];
    int num_contacts = 0;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);
    add_contact(contacts, num_contacts, name, email);

    while (1) {
        printf("\n1. Add contact\n2. Send email\n3. Exit\n");
        scanf("%d", &num_contacts);

        switch (num_contacts) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_contact(contacts, num_contacts, name, email);
                break;
            case 2:
                printf("Enter subject: ");
                scanf("%s", subject);
                printf("Enter body: ");
                scanf("%s", body);
                send_email(contacts, num_contacts, subject, body);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}
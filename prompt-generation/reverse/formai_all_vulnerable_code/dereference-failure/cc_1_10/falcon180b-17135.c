//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact *contacts;
    int num_contacts;
} MailingList;

MailingList *create_mailing_list() {
    MailingList *list = (MailingList *) malloc(sizeof(MailingList));
    list->contacts = NULL;
    list->num_contacts = 0;
    return list;
}

void add_contact(MailingList *list, char *name, char *email) {
    Contact *contact = (Contact *) malloc(sizeof(Contact));
    strcpy(contact->name, name);
    strcpy(contact->email, email);
    list->contacts = (Contact *) realloc(list->contacts, sizeof(Contact) * (list->num_contacts + 1));
    list->contacts[list->num_contacts] = *contact;
    list->num_contacts++;
}

void remove_contact(MailingList *list, char *email) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        if (strcmp(list->contacts[i].email, email) == 0) {
            list->contacts = (Contact *) realloc(list->contacts, sizeof(Contact) * (list->num_contacts - 1));
            list->num_contacts--;
            break;
        }
    }
}

void send_email(MailingList *list, char *subject, char *body) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        printf("Sending email to %s (%s)\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    MailingList *list = create_mailing_list();
    add_contact(list, "John Doe", "johndoe@example.com");
    add_contact(list, "Jane Doe", "janedoe@example.com");
    send_email(list, "Test Email", "This is a test email.");
    remove_contact(list, "johndoe@example.com");
    send_email(list, "Another Test Email", "This is another test email.");
    return 0;
}
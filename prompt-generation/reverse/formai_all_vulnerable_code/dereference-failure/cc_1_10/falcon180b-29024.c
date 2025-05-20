//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECTS 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact* contacts;
    int num_contacts;
} MailingList;

void initialize_contact(Contact* contact) {
    strcpy(contact->name, "");
    strcpy(contact->email, "");
}

void initialize_mailing_list(MailingList* mailing_list) {
    mailing_list->contacts = NULL;
    mailing_list->num_contacts = 0;
}

void add_contact(MailingList* mailing_list, Contact contact) {
    mailing_list->contacts = realloc(mailing_list->contacts, sizeof(Contact) * (mailing_list->num_contacts + 1));
    mailing_list->contacts[mailing_list->num_contacts] = contact;
    mailing_list->num_contacts++;
}

void print_contact(Contact contact) {
    printf("Name: %s\nEmail: %s\n", contact.name, contact.email);
}

void print_mailing_list(MailingList mailing_list) {
    printf("Mailing List:\n");
    for (int i = 0; i < mailing_list.num_contacts; i++) {
        print_contact(mailing_list.contacts[i]);
    }
}

int main() {
    MailingList mailing_list;
    initialize_mailing_list(&mailing_list);

    Contact contact1;
    initialize_contact(&contact1);
    strcpy(contact1.name, "John Doe");
    strcpy(contact1.email, "johndoe@example.com");
    add_contact(&mailing_list, contact1);

    Contact contact2;
    initialize_contact(&contact2);
    strcpy(contact2.name, "Jane Doe");
    strcpy(contact2.email, "janedoe@example.com");
    add_contact(&mailing_list, contact2);

    print_mailing_list(mailing_list);

    return 0;
}
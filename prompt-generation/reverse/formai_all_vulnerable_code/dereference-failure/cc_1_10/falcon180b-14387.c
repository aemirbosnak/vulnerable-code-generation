//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
} mailing_list;

void init_contact(contact *c) {
    strcpy(c->name, "");
    strcpy(c->email, "");
}

void init_mailing_list(mailing_list *ml) {
    ml->contacts = NULL;
    ml->num_contacts = 0;
}

void add_contact(mailing_list *ml, char *name, char *email) {
    contact *c = (contact *)malloc(sizeof(contact));
    init_contact(c);
    strncpy(c->name, name, MAX_NAME_LENGTH);
    strncpy(c->email, email, MAX_EMAIL_LENGTH);
    ml->contacts = (contact *)realloc(ml->contacts, sizeof(contact) * (ml->num_contacts + 1));
    ml->contacts[ml->num_contacts] = *c;
    ml->num_contacts++;
}

void print_contact(contact c) {
    printf("Name: %s\n", c.name);
    printf("Email: %s\n", c.email);
}

void print_mailing_list(mailing_list ml) {
    for (int i = 0; i < ml.num_contacts; i++) {
        print_contact(ml.contacts[i]);
    }
}

int main() {
    mailing_list ml;
    init_mailing_list(&ml);

    add_contact(&ml, "John Doe", "johndoe@example.com");
    add_contact(&ml, "Jane Doe", "janedoe@example.com");

    print_mailing_list(ml);

    return 0;
}
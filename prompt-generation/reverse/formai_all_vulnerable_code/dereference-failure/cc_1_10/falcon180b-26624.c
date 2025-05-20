//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 1000
#define MAX_MESSAGE_LENGTH 10000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    contact* contacts;
    int num_contacts;
    int max_contacts;
} mailing_list;

void init_contact(contact* c) {
    strcpy(c->name, "");
    strcpy(c->email, "");
}

void init_mailing_list(mailing_list* ml) {
    ml->contacts = (contact*)malloc(sizeof(contact));
    ml->num_contacts = 0;
    ml->max_contacts = 1;
}

void add_contact(mailing_list* ml, char* name, char* email) {
    if (ml->num_contacts >= ml->max_contacts) {
        ml->max_contacts += 1;
        ml->contacts = (contact*)realloc(ml->contacts, sizeof(contact) * ml->max_contacts);
    }

    strcpy(ml->contacts[ml->num_contacts].name, name);
    strcpy(ml->contacts[ml->num_contacts].email, email);

    ml->num_contacts += 1;
}

void print_contact(contact c) {
    printf("name: %s\n", c.name);
    printf("email: %s\n", c.email);
}

void print_mailing_list(mailing_list ml) {
    for (int i = 0; i < ml.num_contacts; i++) {
        print_contact(ml.contacts[i]);
    }
}

int main() {
    mailing_list ml;
    init_mailing_list(&ml);

    add_contact(&ml, "john doe", "johndoe@example.com");
    add_contact(&ml, "jane doe", "janedoe@example.com");

    print_mailing_list(ml);

    return 0;
}
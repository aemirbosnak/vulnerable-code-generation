//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 200
#define MAX_BODY_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact* contacts;
    int num_contacts;
} mailing_list;

void add_contact(mailing_list* list, char* name, char* email) {
    contact* new_contact = (contact*)malloc(sizeof(contact));
    strncpy(new_contact->name, name, MAX_NAME_LEN);
    strncpy(new_contact->email, email, MAX_EMAIL_LEN);
    list->contacts = (contact*)realloc(list->contacts, (list->num_contacts + 1) * sizeof(contact));
    list->contacts[list->num_contacts] = *new_contact;
    list->num_contacts++;
}

void remove_contact(mailing_list* list, char* email) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        if (strcmp(list->contacts[i].email, email) == 0) {
            list->num_contacts--;
            list->contacts = (contact*)realloc(list->contacts, list->num_contacts * sizeof(contact));
        }
    }
}

void send_email(mailing_list* list, char* subject, char* body) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        printf("sending email to %s (%s)\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    mailing_list list;
    list.contacts = NULL;
    list.num_contacts = 0;

    add_contact(&list, "john doe", "johndoe@example.com");
    add_contact(&list, "jane doe", "janedoe@example.com");

    send_email(&list, "test email", "this is a test email");

    remove_contact(&list, "johndoe@example.com");

    send_email(&list, "another test email", "this is another test email");

    return 0;
}
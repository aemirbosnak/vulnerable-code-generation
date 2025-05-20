//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 200
#define MAX_BODY_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
} mailing_list;

void add_contact(mailing_list *list, char *name, char *email) {
    contact *new_contact = malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    list->contacts = realloc(list->contacts, sizeof(contact) * (list->num_contacts + 1));
    list->contacts[list->num_contacts] = *new_contact;
    list->num_contacts++;
}

void remove_contact(mailing_list *list, int index) {
    contact *temp_contact = malloc(sizeof(contact));
    strcpy(temp_contact->name, list->contacts[index].name);
    strcpy(temp_contact->email, list->contacts[index].email);
    free(list->contacts[index].name);
    free(list->contacts[index].email);
    list->contacts[index] = *temp_contact;
    free(temp_contact);
    list->num_contacts--;
    list->contacts = realloc(list->contacts, sizeof(contact) * list->num_contacts);
}

void send_email(mailing_list *list, int index, char *subject, char *body) {
    printf("Sending email to %s (%s)\nSubject: %s\n\n%s", list->contacts[index].name, list->contacts[index].email, subject, body);
}

int main() {
    mailing_list list;
    list.contacts = NULL;
    list.num_contacts = 0;

    add_contact(&list, "John Doe", "johndoe@example.com");
    add_contact(&list, "Jane Smith", "janesmith@example.com");

    send_email(&list, 0, "Test Email", "Hello World!");

    remove_contact(&list, 0);

    send_email(&list, 0, "Another Test Email", "How are you doing?");

    return 0;
}
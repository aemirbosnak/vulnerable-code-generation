//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact *contacts;
    int num_contacts;
} MailingList;

MailingList *create_mailing_list() {
    MailingList *list = (MailingList *)malloc(sizeof(MailingList));
    list->num_contacts = 0;
    list->contacts = NULL;
    return list;
}

void add_contact(MailingList *list, char *name, char *email) {
    Contact *contact = (Contact *)malloc(sizeof(Contact));
    strcpy(contact->name, name);
    strcpy(contact->email, email);
    list->contacts = (Contact *)realloc(list->contacts, sizeof(Contact) * (list->num_contacts + 1));
    list->contacts[list->num_contacts++] = *contact;
    free(contact);
}

void remove_contact(MailingList *list, int index) {
    list->num_contacts--;
    list->contacts = (Contact *)realloc(list->contacts, sizeof(Contact) * list->num_contacts);
}

void print_contacts(MailingList *list) {
    for (int i = 0; i < list->num_contacts; i++) {
        printf("Name: %s\nEmail: %s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

void send_email(MailingList *list, char *subject, char *message) {
    for (int i = 0; i < list->num_contacts; i++) {
        printf("Sending email to %s...\n", list->contacts[i].email);
    }
}

int main() {
    MailingList *list = create_mailing_list();
    add_contact(list, "John Doe", "john.doe@example.com");
    add_contact(list, "Jane Smith", "jane.smith@example.com");
    print_contacts(list);
    send_email(list, "Hello!", "This is a test email.");
    remove_contact(list, 0);
    print_contacts(list);
    free(list->contacts);
    free(list);
    return 0;
}
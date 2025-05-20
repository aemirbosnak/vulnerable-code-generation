//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECTS 100
#define MAX_BODY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct {
    char subject[MAX_SUBJECTS];
    char body[MAX_BODY];
    Contact* contacts;
    int num_contacts;
} MailingList;

void add_contact(MailingList* list, char* name, char* email) {
    Contact* new_contact = (Contact*)malloc(sizeof(Contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    list->contacts = (Contact*)realloc(list->contacts, sizeof(Contact) * (list->num_contacts + 1));
    list->contacts[list->num_contacts] = *new_contact;
    list->num_contacts++;
}

void remove_contact(MailingList* list, int index) {
    list->num_contacts--;
    list->contacts = (Contact*)realloc(list->contacts, sizeof(Contact) * list->num_contacts);
}

void send_email(MailingList* list, char* subject, char* body) {
    for (int i = 0; i < list->num_contacts; i++) {
        printf("Sending email to %s (%s)...\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    MailingList list = {0};
    add_contact(&list, "John Doe", "johndoe@example.com");
    add_contact(&list, "Jane Doe", "janedoe@example.com");
    send_email(&list, "Hello", "This is a test email.");
    remove_contact(&list, 0); // Remove first contact
    send_email(&list, "Goodbye", "This is a goodbye email.");
    return 0;
}
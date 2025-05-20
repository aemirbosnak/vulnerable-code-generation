//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 80
#define MAX_SUBJECT_LEN 100
#define MAX_MESSAGE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact* contacts;
    int num_contacts;
    int max_contacts;
} mailing_list;

void init_mailing_list(mailing_list* list) {
    list->contacts = (contact*)malloc(sizeof(contact));
    list->num_contacts = 0;
    list->max_contacts = 1;
}

void add_contact(mailing_list* list, char* name, char* email) {
    if (list->num_contacts >= list->max_contacts) {
        list->max_contacts += 1;
        list->contacts = (contact*)realloc(list->contacts, sizeof(contact) * list->max_contacts);
    }

    strncpy(list->contacts[list->num_contacts].name, name, MAX_NAME_LEN);
    strncpy(list->contacts[list->num_contacts].email, email, MAX_EMAIL_LEN);

    list->num_contacts += 1;
}

void send_email(mailing_list* list, char* subject, char* message) {
    for (int i = 0; i < list->num_contacts; i++) {
        printf("Sending email to %s (%s)\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    mailing_list list;
    init_mailing_list(&list);

    add_contact(&list, "John Doe", "johndoe@example.com");
    add_contact(&list, "Jane Smith", "janesmith@example.com");

    send_email(&list, "Hello World!", "This is a test email.");

    return 0;
}
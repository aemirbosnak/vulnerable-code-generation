//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    contact* contacts;
    int num_contacts;
    char* message;
    int message_length;
} mailing_list;

void add_contact(mailing_list* list, char* name, char* email) {
    contact* new_contact = (contact*)malloc(sizeof(contact));
    strncpy(new_contact->name, name, MAX_NAME_LENGTH);
    strncpy(new_contact->email, email, MAX_EMAIL_LENGTH);
    list->contacts = (contact*)realloc(list->contacts, sizeof(contact)*(list->num_contacts+1));
    list->contacts[list->num_contacts] = *new_contact;
    list->num_contacts++;
}

void remove_contact(mailing_list* list, int index) {
    contact* temp_contacts = (contact*)malloc(sizeof(contact)*(list->num_contacts-1));
    int j = 0;
    for (int i = 0; i < list->num_contacts; i++) {
        if (i!= index) {
            strncpy(temp_contacts[j].name, list->contacts[i].name, MAX_NAME_LENGTH);
            strncpy(temp_contacts[j].email, list->contacts[i].email, MAX_EMAIL_LENGTH);
            j++;
        }
    }
    free(list->contacts);
    list->contacts = temp_contacts;
    list->num_contacts--;
}

void send_message(mailing_list* list) {
    for (int i = 0; i < list->num_contacts; i++) {
        printf("Sending message to %s (%s)\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    mailing_list list;
    list.num_contacts = 0;
    list.contacts = NULL;

    add_contact(&list, "John Doe", "johndoe@example.com");
    add_contact(&list, "Jane Smith", "janesmith@example.com");

    send_message(&list);

    remove_contact(&list, 0);

    send_message(&list);

    return 0;
}
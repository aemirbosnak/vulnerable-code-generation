//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LIST_SIZE 1000
#define MAX_NAME_SIZE 50
#define MAX_EMAIL_SIZE 100
#define MAX_SUBJECT_SIZE 100
#define MAX_MESSAGE_SIZE 1000

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
} Contact;

typedef struct {
    Contact *contacts;
    int num_contacts;
    int capacity;
} MailingList;

MailingList *create_mailing_list() {
    MailingList *list = (MailingList *)malloc(sizeof(MailingList));
    list->contacts = (Contact *)malloc(MAX_LIST_SIZE * sizeof(Contact));
    list->num_contacts = 0;
    list->capacity = MAX_LIST_SIZE;
    return list;
}

void add_contact(MailingList *list, char *name, char *email) {
    if (list->num_contacts >= list->capacity) {
        printf("Error: Mailing list is full.\n");
        return;
    }
    Contact *contact = &list->contacts[list->num_contacts];
    strcpy(contact->name, name);
    strcpy(contact->email, email);
    list->num_contacts++;
}

void delete_contact(MailingList *list, char *email) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        if (strcmp(list->contacts[i].email, email) == 0) {
            memmove(&list->contacts[i], &list->contacts[i+1], (list->num_contacts - i - 1) * sizeof(Contact));
            list->num_contacts--;
            return;
        }
    }
    printf("Error: Contact not found.\n");
}

void send_email(MailingList *list, char *subject, char *message) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        printf("Sending email to %s (%s)...\n", list->contacts[i].name, list->contacts[i].email);
        // Code to send email using SMTP protocol
    }
}

int main() {
    MailingList *list = create_mailing_list();
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
    while (1) {
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter email: ");
        scanf("%s", email);
        add_contact(list, name, email);
        printf("Contact added.\n");
    }
    return 0;
}
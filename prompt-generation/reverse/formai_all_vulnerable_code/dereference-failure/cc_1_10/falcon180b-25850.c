//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact *contacts;
    int size;
    int capacity;
} MailingList;

void initMailingList(MailingList *list) {
    list->contacts = NULL;
    list->size = 0;
    list->capacity = 0;
}

void addContact(MailingList *list, Contact contact) {
    if (list->size == list->capacity) {
        list->capacity += 10;
        list->contacts = realloc(list->contacts, list->capacity * sizeof(Contact));
    }
    list->contacts[list->size++] = contact;
}

void printContacts(MailingList list) {
    for (int i = 0; i < list.size; i++) {
        printf("%s\n%s\n%s\n%s\n", list.contacts[i].name, list.contacts[i].address, list.contacts[i].phone, list.contacts[i].email);
    }
}

int main() {
    MailingList list;
    initMailingList(&list);

    Contact contact1 = {"John Doe", "123 Main St.", "555-1234", "johndoe@example.com"};
    Contact contact2 = {"Jane Smith", "456 Elm St.", "555-5678", "janesmith@example.com"};

    addContact(&list, contact1);
    addContact(&list, contact2);

    printContacts(list);

    return 0;
}
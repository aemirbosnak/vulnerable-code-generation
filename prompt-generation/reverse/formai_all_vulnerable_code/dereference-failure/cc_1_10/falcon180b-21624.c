//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact* contacts;
    int size;
} MailingList;

MailingList* createMailingList() {
    MailingList* list = (MailingList*)malloc(sizeof(MailingList));
    list->size = 0;
    list->contacts = (Contact*)malloc(MAX_LIST_SIZE * sizeof(Contact));
    return list;
}

void destroyMailingList(MailingList* list) {
    free(list->contacts);
    free(list);
}

int addContact(MailingList* list, char* name, char* email) {
    if (list->size >= MAX_LIST_SIZE) {
        printf("Error: Mailing list is full.\n");
        return -1;
    }

    strncpy(list->contacts[list->size].name, name, MAX_NAME_LENGTH);
    strncpy(list->contacts[list->size].email, email, MAX_EMAIL_LENGTH);

    list->size++;

    return 0;
}

int removeContact(MailingList* list, char* email) {
    int i;

    for (i = 0; i < list->size; i++) {
        if (strcmp(list->contacts[i].email, email) == 0) {
            memmove(&list->contacts[i], &list->contacts[i+1], (list->size - i - 1) * sizeof(Contact));
            list->size--;
            return 0;
        }
    }

    printf("Error: Contact not found.\n");
    return -1;
}

int sendEmail(MailingList* list, char* subject, char* message) {
    int i;

    for (i = 0; i < list->size; i++) {
        printf("Sending email to %s (%s)...\n", list->contacts[i].name, list->contacts[i].email);
    }

    return 0;
}

int main() {
    MailingList* list = createMailingList();

    addContact(list, "Romeo", "romeo@example.com");
    addContact(list, "Juliet", "juliet@example.com");

    removeContact(list, "juliet@example.com");

    sendEmail(list, "A message from Romeo", "Wherefore art thou, Juliet?");

    destroyMailingList(list);

    return 0;
}
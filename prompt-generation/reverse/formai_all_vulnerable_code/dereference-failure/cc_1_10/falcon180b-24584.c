//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    contact *contacts;
    int size;
    int capacity;
} mailing_list;

void init_mailing_list(mailing_list *list) {
    list->contacts = NULL;
    list->size = 0;
    list->capacity = 0;
}

void add_contact(mailing_list *list, const char *name, const char *email) {
    contact *new_contact = malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->contacts = realloc(list->contacts, list->capacity * sizeof(contact));
    }
    list->contacts[list->size++] = *new_contact;
}

void remove_contact(mailing_list *list, int index) {
    if (index >= 0 && index < list->size) {
        list->size--;
        memmove(&list->contacts[index], &list->contacts[index + 1], (list->size - index) * sizeof(contact));
    }
}

void print_contacts(mailing_list *list) {
    printf("Name\tEmail\n");
    for (int i = 0; i < list->size; i++) {
        printf("%s\t%s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

void send_message(mailing_list *list, const char *subject, const char *message) {
    printf("Sending message to %d contacts...\n", list->size);
    for (int i = 0; i < list->size; i++) {
        printf("Sending message to %s...\n", list->contacts[i].email);
    }
}

int main() {
    mailing_list list;
    init_mailing_list(&list);

    add_contact(&list, "John Doe", "johndoe@example.com");
    add_contact(&list, "Jane Smith", "janesmith@example.com");
    add_contact(&list, "Bob Johnson", "bobjohnson@example.com");

    print_contacts(&list);

    remove_contact(&list, 1);
    print_contacts(&list);

    send_message(&list, "Hello", "How are you?");

    return 0;
}
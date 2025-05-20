//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50
#define MAX_NUMBER_SIZE 20

typedef struct {
    char name[MAX_NAME_SIZE];
    char number[MAX_NUMBER_SIZE];
} contact;

contact *phonebook = NULL;
int num_contacts = 0;

void add_contact(char *name, char *number) {
    contact *new_contact = (contact *) malloc(sizeof(contact));

    strcpy(new_contact->name, name);
    strcpy(new_contact->number, number);

    phonebook = (contact *) realloc(phonebook, sizeof(contact) * (num_contacts + 1));
    phonebook[num_contacts] = *new_contact;
    free(new_contact);

    num_contacts++;
}

void delete_contact(char *name) {
    int i;

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            phonebook = (contact *) realloc(phonebook, sizeof(contact) * (num_contacts - 1));

            for (int j = i; j < num_contacts - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }

            num_contacts--;
            return;
        }
    }
}

void search_contact(char *name) {
    int i;

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    phonebook = (contact *) malloc(sizeof(contact));
    num_contacts = 0;

    add_contact("John Doe", "123-4567");
    add_contact("Jane Smith", "555-9876");

    search_contact("John Doe");

    delete_contact("John Doe");

    search_contact("John Doe");

    return 0;
}
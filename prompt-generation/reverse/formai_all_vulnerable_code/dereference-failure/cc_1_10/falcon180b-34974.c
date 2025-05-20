//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBERS_PER_CONTACT 3
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char numbers[MAX_NUMBERS_PER_CONTACT][15];
    int num_numbers;
} Contact;

void add_contact(Contact *contacts, int num_contacts, char *name, char *number) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            strcpy(contacts[i].numbers[contacts[i].num_numbers], number);
            contacts[i].num_numbers++;
            return;
        }
    }
    strcpy(contacts[num_contacts - 1].name, name);
    strcpy(contacts[num_contacts - 1].numbers[0], number);
    contacts[num_contacts - 1].num_numbers = 1;
    num_contacts++;
}

void delete_contact(Contact *contacts, int num_contacts, char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < num_contacts - 1; j++) {
                strcpy(contacts[j].name, contacts[j + 1].name);
                for (int k = 0; k < MAX_NUMBERS_PER_CONTACT; k++) {
                    strcpy(contacts[j].numbers[k], contacts[j + 1].numbers[k]);
                }
                contacts[j].num_numbers = contacts[j + 1].num_numbers;
            }
            num_contacts--;
            return;
        }
    }
}

void print_contacts(Contact *contacts, int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s:\n", contacts[i].name);
        for (int j = 0; j < contacts[i].num_numbers; j++) {
            printf("\t%s\n", contacts[i].numbers[j]);
        }
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    add_contact(contacts, num_contacts, "Alice", "123-456-7890");
    add_contact(contacts, num_contacts, "Bob", "987-654-3210");
    add_contact(contacts, num_contacts, "Charlie", "555-555-5555");

    print_contacts(contacts, num_contacts);

    delete_contact(contacts, num_contacts, "Alice");

    print_contacts(contacts, num_contacts);

    return 0;
}
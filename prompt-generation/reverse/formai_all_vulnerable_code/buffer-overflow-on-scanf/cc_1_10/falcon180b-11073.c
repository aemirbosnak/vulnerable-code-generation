//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBERS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char numbers[MAX_NUMBERS][20];
    int num_entries;
} Contact;

void add_entry(Contact *contact, char *number) {
    if (contact->num_entries >= MAX_NUMBERS) {
        printf("Error: Contact has too many numbers.\n");
        return;
    }
    strcpy(contact->numbers[contact->num_entries], number);
    contact->num_entries++;
}

void print_contact(Contact *contact) {
    printf("Name: %s\n", contact->name);
    for (int i = 0; i < contact->num_entries; i++) {
        printf("Number %d: %s\n", i + 1, contact->numbers[i]);
    }
}

int main() {
    Contact phonebook[100];
    int num_contacts = 0;
    char name[MAX_NAME_LENGTH];
    char number[20];

    while (1) {
        printf("Enter a name (leave blank to stop adding contacts):\n");
        scanf("%s", name);
        if (name[0] == '\0') {
            break;
        }
        strcpy(phonebook[num_contacts].name, name);
        num_contacts++;
    }

    while (1) {
        printf("Enter a number for %s (leave blank to stop adding numbers):\n", phonebook[num_contacts - 1].name);
        scanf("%s", number);
        if (number[0] == '\0') {
            break;
        }
        add_entry(&phonebook[num_contacts - 1], number);
    }

    while (1) {
        printf("Enter a name to search for:\n");
        scanf("%s", name);
        for (int i = 0; i < num_contacts; i++) {
            if (strcmp(phonebook[i].name, name) == 0) {
                print_contact(&phonebook[i]);
                break;
            }
        }
    }

    return 0;
}
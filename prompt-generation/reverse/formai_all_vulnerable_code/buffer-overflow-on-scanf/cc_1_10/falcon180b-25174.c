//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Contact;

void add_contact(Contact *contacts, int num_contacts) {
    printf("Enter name (up to %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", contacts[num_contacts].name);

    printf("Enter phone number (up to %d characters): ", MAX_NUMBER_LEN - 1);
    scanf("%s", contacts[num_contacts].number);

    num_contacts++;
}

void print_contact(Contact contact) {
    printf("%s: %s\n", contact.name, contact.number);
}

void print_all_contacts(Contact *contacts, int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        print_contact(contacts[i]);
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    add_contact(contacts, num_contacts);

    while (1) {
        printf("1. Add contact\n2. Print all contacts\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, num_contacts);
                break;
            case 2:
                print_all_contacts(contacts, num_contacts);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
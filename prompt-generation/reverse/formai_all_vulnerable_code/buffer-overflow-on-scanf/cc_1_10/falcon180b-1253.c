//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_CONTACTS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int add_contact(Contact* contacts, int num_contacts) {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);

    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts].number);

    num_contacts++;

    return num_contacts;
}

int search_contact(Contact* contacts, int num_contacts, char* name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", contacts[i].name, contacts[i].number);
            return 1;
        }
    }

    printf("Contact not found.\n");
    return 0;
}

int delete_contact(Contact* contacts, int num_contacts) {
    printf("Enter name of contact to delete: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < num_contacts - 1; j++) {
                strcpy(contacts[j].name, contacts[j + 1].name);
                strcpy(contacts[j].number, contacts[j + 1].number);
            }

            num_contacts--;

            return num_contacts;
        }
    }

    printf("Contact not found.\n");
    return num_contacts;
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    while (1) {
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            num_contacts = add_contact(contacts, num_contacts);
        } else if (choice == 2) {
            char name[MAX_NAME_LENGTH];
            printf("Enter name to search: ");
            scanf("%s", name);
            search_contact(contacts, num_contacts, name);
        } else if (choice == 3) {
            num_contacts = delete_contact(contacts, num_contacts);
        } else if (choice == 4) {
            break;
        }
    }

    return 0;
}
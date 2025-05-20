//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 30
#define MAX_NUMBER_LEN 15

struct contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
};

void add_contact(struct contact *phonebook, int num_contacts) {
    printf("Enter name: ");
    scanf("%s", phonebook[num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook[num_contacts].number);
}

void search_contact(struct contact *phonebook, int num_contacts, char *name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone number: %s\n", phonebook[i].number);
        }
    }
}

void delete_contact(struct contact *phonebook, int num_contacts, char *name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].number, "");
        }
    }
}

int main() {
    struct contact phonebook[MAX_CONTACTS];
    int num_contacts = 0;

    printf("Welcome to the Phone Book!\n");

    while (num_contacts < MAX_CONTACTS) {
        int choice;
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_contact(phonebook, num_contacts);
            num_contacts++;
            break;
        case 2:
            printf("Enter name to search: ");
            char name[MAX_NAME_LEN];
            scanf("%s", name);
            search_contact(phonebook, num_contacts, name);
            break;
        case 3:
            printf("Enter name to delete: ");
            char name_to_delete[MAX_NAME_LEN];
            scanf("%s", name_to_delete);
            delete_contact(phonebook, num_contacts, name_to_delete);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Phone Book ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTS 100 // maximum number of contacts that can be stored in the phone book

struct Contact {
    char name[30];
    char phone_number[15];
};

struct Contact phonebook[MAX_CONTACTS]; // initialize the phone book array

int num_contacts = 0; // initialize the number of contacts to 0

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phonebook[num_contacts].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[num_contacts].phone_number);

    num_contacts++;

    printf("Contact added successfully!\n");
}

void delete_contact() {
    if (num_contacts == 0) {
        printf("Phone book is empty!\n");
        return;
    }

    char name_to_delete[30];
    int found = 0;

    printf("Enter name to delete: ");
    scanf("%s", name_to_delete);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name_to_delete) == 0) {
            // shift all elements left to overwrite the deleted contact
            for (int j = i; j < num_contacts - 1; j++) {
                strcpy(phonebook[j].name, phonebook[j+1].name);
                strcpy(phonebook[j].phone_number, phonebook[j+1].phone_number);
            }

            num_contacts--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

void search_contact() {
    if (num_contacts == 0) {
        printf("Phone book is empty!\n");
        return;
    }

    char name_to_find[30];
    int found = 0;

    printf("Enter name to find: ");
    scanf("%s", name_to_find);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name_to_find) == 0) {
            printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone_number);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

void list_contacts() {
    if (num_contacts == 0) {
        printf("Phone book is empty!\n");
        return;
    }

    printf("Name\tPhone Number\n");

    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", phonebook[i].name, phonebook[i].phone_number);
    }
}

int main() {
    char option;

    do {
        printf("\n---------MENU----------\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. List Contacts\n");
        printf("5. Quit\n");
        printf("------------------------\n");

        printf("Enter option (1-5): ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                add_contact();
                break;
            case '2':
                delete_contact();
                break;
            case '3':
                search_contact();
                break;
            case '4':
                list_contacts();
                break;
            case '5':
                printf("Exiting phone book...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != '5');

    return 0;
}
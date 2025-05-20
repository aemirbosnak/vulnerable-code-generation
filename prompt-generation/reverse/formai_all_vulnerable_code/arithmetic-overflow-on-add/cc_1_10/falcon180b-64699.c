//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_NUMBERS_PER_CONTACT 3
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char numbers[MAX_NUMBERS_PER_CONTACT][MAX_NAME_LEN];
    int num_numbers;
} Contact;

int num_contacts = 0;
Contact contacts[MAX_CONTACTS];

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    Contact new_contact;
    strcpy(new_contact.name, "");
    new_contact.num_numbers = 0;

    printf("Enter contact name: ");
    scanf("%s", new_contact.name);

    int i;
    for (i = 0; i < MAX_NUMBERS_PER_CONTACT; i++) {
        char number[MAX_NAME_LEN];
        printf("Enter phone number %d: ", i+1);
        scanf("%s", number);
        strcpy(new_contact.numbers[i], number);
        new_contact.num_numbers++;
    }

    contacts[num_contacts] = new_contact;
    num_contacts++;

    printf("Contact added successfully.\n");
}

void search_contact() {
    char search_name[MAX_NAME_LEN];
    printf("Enter contact name to search: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_contacts; i++) {
        Contact contact = contacts[i];
        if (strcmp(contact.name, search_name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contact.name);

            int j;
            for (j = 0; j < contact.num_numbers; j++) {
                printf("Phone number %d: %s\n", j+1, contact.numbers[j]);
            }

            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    while (1) {
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_contact();
            break;
        case 2:
            search_contact();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
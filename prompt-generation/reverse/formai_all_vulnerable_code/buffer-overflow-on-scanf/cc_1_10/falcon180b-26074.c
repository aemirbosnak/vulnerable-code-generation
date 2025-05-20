//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char first_name[50];
    char last_name[50];
    char phone_number[15];
} contact_t;

void add_contact(contact_t *contacts[], int num_contacts) {
    printf("Enter first name: ");
    scanf("%s", contacts[num_contacts]->first_name);

    printf("Enter last name: ");
    scanf("%s", contacts[num_contacts]->last_name);

    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts]->phone_number);

    num_contacts++;
}

void delete_contact(contact_t *contacts[], int num_contacts) {
    char name[100];
    printf("Enter name to delete: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i]->first_name, name) == 0 || strcmp(contacts[i]->last_name, name) == 0) {
            num_contacts--;
            break;
        }
    }
}

void search_contact(contact_t *contacts[], int num_contacts) {
    char name[100];
    printf("Enter name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i]->first_name, name) == 0 || strcmp(contacts[i]->last_name, name) == 0) {
            printf("Name: %s %s\nPhone number: %s\n", contacts[i]->first_name, contacts[i]->last_name, contacts[i]->phone_number);
        }
    }
}

int main() {
    contact_t *contacts[MAX_CONTACTS];
    int num_contacts = 0;

    while (1) {
        printf("1. Add contact\n2. Delete contact\n3. Search contact\n4. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_contacts >= MAX_CONTACTS) {
                printf("Cannot add more contacts.\n");
            } else {
                add_contact(contacts, num_contacts);
            }
            break;

        case 2:
            delete_contact(contacts, num_contacts);
            break;

        case 3:
            search_contact(contacts, num_contacts);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
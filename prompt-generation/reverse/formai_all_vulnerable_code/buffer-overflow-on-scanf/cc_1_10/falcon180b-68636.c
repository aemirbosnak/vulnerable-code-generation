//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 64
#define MAX_PHONE_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} contact_t;

contact_t contacts[100];
int num_contacts = 0;

void add_contact() {
    if (num_contacts >= 100) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[num_contacts].name, MAX_NAME_LENGTH, stdin);

    printf("Enter phone number: ");
    fgets(contacts[num_contacts].phone_number, MAX_PHONE_NUMBER_LENGTH, stdin);

    num_contacts++;
}

void search_contact() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(search_name, MAX_NAME_LENGTH, stdin);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Name: %s\nPhone number: %s\n", contacts[i].name, contacts[i].phone_number);
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact() {
    printf("Enter name of contact to delete: ");
    char search_name[MAX_NAME_LENGTH];
    fgets(search_name, MAX_NAME_LENGTH, stdin);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            memset(&contacts[i], 0, sizeof(contact_t));
            printf("Contact deleted.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    printf("Phone book by Ken Thompson\n");

    while (1) {
        printf("\n1. Add contact\n2. Search contact\n3. Delete contact\n4. Exit\n");
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
                delete_contact();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
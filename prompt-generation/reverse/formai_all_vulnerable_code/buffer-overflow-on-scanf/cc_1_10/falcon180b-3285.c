//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact_t;

int num_contacts = 0;
contact_t contacts[MAX_CONTACTS];

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);

    printf("Enter number: ");
    scanf("%s", contacts[num_contacts].number);

    printf("Enter email: ");
    scanf("%s", contacts[num_contacts].email);

    num_contacts++;
}

void search_contact() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Name: %s\nNumber: %s\nEmail: %s\n", contacts[i].name, contacts[i].number, contacts[i].email);
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter name to delete: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            memmove(&contacts[i], &contacts[i+1], sizeof(contact_t) * (num_contacts - i - 1));
            num_contacts--;
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    printf("Phone Book\n");
    printf("---------\n");

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
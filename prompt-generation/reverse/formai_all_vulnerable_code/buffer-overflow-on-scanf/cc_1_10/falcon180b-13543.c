//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} contact_t;

contact_t contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts].number);
    num_contacts++;
}

void search_contact() {
    printf("Enter name to search for: ");
    char search_name[MAX_NAME_LENGTH];
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Name: %s\nPhone number: %s\n", contacts[i].name, contacts[i].number);
            found = 1;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    printf("Phone Book\n");
    printf("--------------------\n");
    int choice;
    while (1) {
        printf("1. Add contact\n2. Search contact\n3. Exit\n");
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
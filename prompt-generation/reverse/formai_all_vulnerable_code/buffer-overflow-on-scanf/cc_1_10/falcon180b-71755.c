//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct contact {
    char name[50];
    char phone_number[15];
};

int num_contacts = 0;

void add_contact(struct contact *contacts) {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts].phone_number);
    num_contacts++;
}

void search_contact(struct contact *contacts) {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Phone number: %s\n", contacts[i].phone_number);
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    struct contact contacts[MAX_CONTACTS];
    printf("Phone Book\n");
    while (1) {
        printf("1. Add contact\n2. Search contact\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_contact(contacts);
            break;
        case 2:
            search_contact(contacts);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
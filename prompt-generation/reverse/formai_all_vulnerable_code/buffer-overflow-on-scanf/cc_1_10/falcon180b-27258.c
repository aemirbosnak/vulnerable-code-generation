//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000

struct contact {
    char name[50];
    char phone[15];
};

void add_contact(struct contact *contacts, int num_contacts, char *name, char *phone) {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].phone, phone);

    num_contacts++;
}

void print_contacts(struct contact *contacts, int num_contacts) {
    printf("Phone Book:\n");

    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", contacts[i].name, contacts[i].phone);
    }
}

void search_contact(struct contact *contacts, int num_contacts, char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }

    printf("Contact not found!\n");
}

int main() {
    struct contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    char name[50];
    char phone[15];

    while (1) {
        printf("Enter 1 to add contact, 2 to print phone book, 3 to search contact, or 0 to exit:\n");
        scanf("%d", &num_contacts);

        if (num_contacts == 0) {
            break;
        }

        switch (num_contacts) {
        case 1:
            printf("Enter name:\n");
            scanf("%s", name);

            printf("Enter phone number:\n");
            scanf("%s", phone);

            add_contact(contacts, num_contacts, name, phone);
            break;

        case 2:
            print_contacts(contacts, num_contacts);
            break;

        case 3:
            printf("Enter name to search:\n");
            scanf("%s", name);

            search_contact(contacts, num_contacts, name);
            break;

        default:
            printf("Invalid option!\n");
            break;
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[15];
} Contact;

void add_contact(Contact *contacts, int num_contacts, char *name, char *phone) {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].phone, phone);
    num_contacts++;
}

void search_contact(Contact *contacts, int num_contacts, char *name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
        }
    }
}

void delete_contact(Contact *contacts, int num_contacts, char *name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            memmove(&contacts[i], &contacts[i+1], sizeof(Contact) * (num_contacts - i - 1));
            num_contacts--;
            return;
        }
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    char choice;
    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1': {
            char name[50], phone[15];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter phone: ");
            scanf("%s", phone);
            add_contact(contacts, num_contacts, name, phone);
            break;
        }
        case '2': {
            char name[50];
            printf("Enter name to search: ");
            scanf("%s", name);
            search_contact(contacts, num_contacts, name);
            break;
        }
        case '3': {
            char name[50];
            printf("Enter name to delete: ");
            scanf("%s", name);
            delete_contact(contacts, num_contacts, name);
            break;
        }
        case '4':
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
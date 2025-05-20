//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact(char* name, char* number) {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add contact.\n");
        return;
    }

    strncpy(contacts[num_contacts].name, name, MAX_NAME_LEN);
    strncpy(contacts[num_contacts].number, number, MAX_NUMBER_LEN);

    num_contacts++;
}

void search_contact(char* name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact(char* name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            memmove(&contacts[i], &contacts[i+1], (num_contacts - i - 1) * sizeof(Contact));
            num_contacts--;
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];

    do {
        printf("Phone book options:\n");
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_contact(name, number);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                search_contact(name);
                break;
            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete_contact(name);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}
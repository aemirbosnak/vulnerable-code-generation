//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Contact;

void add_contact(Contact *contacts, int num_contacts, char *name, char *number) {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Error: Phone book is full.\n");
        return;
    }

    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].number, number);

    num_contacts++;
}

void print_contacts(Contact *contacts, int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].number);
    }
}

void search_contact(Contact *contacts, int num_contacts, char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("%s: %s\n", name, contacts[i].number);
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    while (1) {
        printf("1. Add contact\n2. Print contacts\n3. Search contact\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LEN], number[MAX_NUMBER_LEN];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);

                add_contact(contacts, num_contacts, name, number);
                break;
            }
            case 2: {
                print_contacts(contacts, num_contacts);
                break;
            }
            case 3: {
                char name[MAX_NAME_LEN];
                printf("Enter name to search: ");
                scanf("%s", name);

                search_contact(contacts, num_contacts, name);
                break;
            }
            case 4: {
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}
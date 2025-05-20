//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact(const char *name, const char *number) {
    if (num_contacts == MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].number, number);
    num_contacts++;
}

void remove_contact(const char *name) {
    int i;

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_contacts) {
        printf("Contact not found!\n");
        return;
    }

    for (; i < num_contacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    num_contacts--;
}

void search_contact(const char *name) {
    int i;

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found: %s (%s)\n", contacts[i].name, contacts[i].number);
            return;
        }
    }

    printf("Contact not found!\n");
}

void print_all_contacts() {
    int i;

    for (i = 0; i < num_contacts; i++) {
        printf("%s (%s)\n", contacts[i].name, contacts[i].number);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    while (1) {
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Search contact\n");
        printf("4. Print all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter contact name: ");
                scanf("%s", name);
                printf("Enter contact number: ");
                scanf("%s", number);
                add_contact(name, number);
                break;
            case 2:
                printf("Enter contact name to remove: ");
                scanf("%s", name);
                remove_contact(name);
                break;
            case 3:
                printf("Enter contact name to search: ");
                scanf("%s", name);
                search_contact(name);
                break;
            case 4:
                print_all_contacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
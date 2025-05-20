//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} contact;

contact phonebook[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter the name of the contact: ");
    scanf("%s", phonebook[num_contacts].name);

    printf("Enter the phone number of the contact: ");
    scanf("%s", phonebook[num_contacts].number);

    num_contacts++;
}

void search_contact() {
    char name[MAX_NAME_LEN];

    printf("Enter the name of the contact to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Number: %s\n", phonebook[i].number);
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact() {
    char name[MAX_NAME_LEN];

    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            memmove(&phonebook[i], &phonebook[i + 1], sizeof(contact) * (num_contacts - i - 1));
            num_contacts--;
            return;
        }
    }

    printf("Contact not found.\n");
}

void print_phonebook() {
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", phonebook[i].name);
        printf("Number: %s\n", phonebook[i].number);
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Delete contact\n");
        printf("4. Print phone book\n");
        printf("5. Exit\n");

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
            print_phonebook();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}
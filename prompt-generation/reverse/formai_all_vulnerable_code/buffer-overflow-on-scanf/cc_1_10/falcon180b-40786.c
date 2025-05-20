//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Contact;

void add_contact(Contact *contacts, int num_contacts) {
    printf("Enter name for contact #%d: ", num_contacts + 1);
    scanf("%s", contacts[num_contacts].name);

    printf("Enter phone number for contact #%d: ", num_contacts + 1);
    scanf("%s", contacts[num_contacts].number);
}

void print_contacts(Contact *contacts, int num_contacts) {
    printf("Phone Book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].number);
    }
}

void search_contact(Contact *contacts, int num_contacts) {
    char name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("%s - %s\n", contacts[i].name, contacts[i].number);
        }
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    printf("Welcome to the Phone Book program!\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add contact\n");
        printf("2. Print phone book\n");
        printf("3. Search contact\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_contacts >= MAX_CONTACTS) {
                printf("Phone book is full. Please delete a contact first.\n");
            } else {
                add_contact(contacts, num_contacts);
                num_contacts++;
            }
            break;

        case 2:
            print_contacts(contacts, num_contacts);
            break;

        case 3:
            search_contact(contacts, num_contacts);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
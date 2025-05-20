//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 20
#define MAX_NUM_LEN 10

// Structure to store a contact
struct contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
};

// Hash table to store contacts
struct contact contacts[MAX_CONTACTS];
int num_contacts = 0;

// Function to add a contact to the phone book
void add_contact(const char* name, const char* number) {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    struct contact new_contact;
    strcpy(new_contact.name, name);
    strcpy(new_contact.number, number);

    contacts[num_contacts] = new_contact;
    num_contacts++;
    printf("Contact added successfully.\n");
}

// Function to remove a contact from the phone book
void remove_contact(const char* name) {
    int index;

    for (index = 0; index < num_contacts; index++) {
        if (strcmp(contacts[index].name, name) == 0) {
            break;
        }
    }

    if (index == num_contacts) {
        printf("Contact not found.\n");
        return;
    }

    memset(&contacts[index], 0, sizeof(struct contact));
    num_contacts--;
    printf("Contact removed successfully.\n");
}

// Function to search for a contact in the phone book
void search_contact(const char* name) {
    int index;

    for (index = 0; index < num_contacts; index++) {
        if (strcmp(contacts[index].name, name) == 0) {
            printf("Contact found: %s - %s\n", contacts[index].name, contacts[index].number);
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    printf("Phone Book\n");
    printf("---------------------\n");

    char name[MAX_NAME_LEN], number[MAX_NUM_LEN];
    char choice;

    while (true) {
        printf("Enter your choice (a/r/s/e): ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_contact(name, number);
                break;

            case 'r':
                printf("Enter name to remove: ");
                scanf("%s", name);
                remove_contact(name);
                break;

            case's':
                printf("Enter name to search: ");
                scanf("%s", name);
                search_contact(name);
                break;

            case 'e':
                printf("Bye!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
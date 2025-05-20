//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 20

typedef struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void clear_screen() {
    printf("\033[2J");
}

void print_menu() {
    clear_screen();
    printf("**************************************\n");
    printf("*** Welcome to C Phone Book! ***\n");
    printf("**************************************\n");
    printf("1. Add a new contact\n");
    printf("2. Search for a contact\n");
    printf("3. Delete a contact\n");
    printf("4. Print all contacts\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int find_contact_index(char name[]) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add contact.\n");
        return;
    }

    printf("Enter contact name: ");
    scanf("%s", contacts[num_contacts].name);

    printf("Enter contact phone number: ");
    scanf("%s", contacts[num_contacts].phone);

    num_contacts++;
}

void search_contact() {
    char name[NAME_LENGTH];
    int index;

    printf("Enter contact name to search: ");
    scanf("%s", name);

    index = find_contact_index(name);

    if (index == -1) {
        printf("Contact not found.\n");
    } else {
        printf("Contact found:\n");
        printf("Name: %s\n", contacts[index].name);
        printf("Phone: %s\n", contacts[index].phone);
    }
}

void delete_contact() {
    char name[NAME_LENGTH];
    int index;

    printf("Enter contact name to delete: ");
    scanf("%s", name);

    index = find_contact_index(name);

    if (index == -1) {
        printf("Contact not found.\n");
    } else {
        for (int i = index; i < num_contacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        num_contacts--;
        printf("Contact deleted successfully.\n");
    }
}

void print_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

int main() {
    int choice;

    while (1) {
        print_menu();
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
                print_contacts();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
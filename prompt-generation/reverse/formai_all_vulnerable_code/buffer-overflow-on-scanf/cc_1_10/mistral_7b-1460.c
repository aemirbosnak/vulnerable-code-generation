//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[15];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void print_menu() {
    printf("\nTranquil Telephone\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Search Contact\n");
    printf("4. Display All Contacts\n");
    printf("5. Exit\n");
}

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full. Please delete some contacts first.\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[num_contacts].name, sizeof(contacts[num_contacts].name), stdin);
    contacts[num_contacts].name[strlen(contacts[num_contacts].name) - 1] = '\0';

    printf("Enter phone number: ");
    fgets(contacts[num_contacts].phone, sizeof(contacts[num_contacts].phone), stdin);
    contacts[num_contacts].phone[strlen(contacts[num_contacts].phone) - 1] = '\0';

    num_contacts++;

    printf("Contact added successfully.\n");
}

void delete_contact() {
    int index = -1;

    printf("Enter contact name to delete: ");
    char name[50];
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }

    for (int i = index; i < num_contacts - 1; i++) {
        contacts[i] = contacts[i+1];
    }

    num_contacts--;

    printf("Contact deleted successfully.\n");
}

void search_contact() {
    printf("Enter contact name to search: ");
    char name[50];
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    bool found = false;

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void display_all_contacts() {
    printf("\nContacts:\n");

    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
    }
}

int main() {
    int choice;

    while (true) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                delete_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                display_all_contacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
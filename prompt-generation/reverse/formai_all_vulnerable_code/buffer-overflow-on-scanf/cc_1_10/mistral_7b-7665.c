//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char phone[15];
} Contact;

Contact contacts[MAX_ENTRIES];
int num_contacts = 0;

void display_menu();
void add_contact();
void remove_contact();
void search_contact();
void display_all_contacts();

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                display_all_contacts();
                break;
            case 5:
                printf("Exiting the phonebook application...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\nPhonebook Application\n");
    printf("----------------------\n");
    printf("1. Add a contact\n");
    printf("2. Remove a contact\n");
    printf("3. Search for a contact\n");
    printf("4. Display all contacts\n");
    printf("5. Exit\n");
}

void add_contact() {
    if (num_contacts >= MAX_ENTRIES) {
        printf("The phonebook is full. Cannot add a new contact.\n");
        return;
    }

    printf("Enter contact name: ");
    scanf("%s", contacts[num_contacts].name);

    printf("Enter contact phone number: ");
    scanf("%s", contacts[num_contacts].phone);

    num_contacts++;

    printf("Contact added successfully.\n");
}

void remove_contact() {
    int index;
    char name[NAME_LENGTH];

    printf("Enter the name of the contact to be removed: ");
    scanf("%s", name);

    for (index = 0; index < num_contacts; index++) {
        if (strcmp(contacts[index].name, name) == 0) {
            for (int i = index; i < num_contacts - 1; i++) {
                contacts[i] = contacts[i + 1];
            }
            num_contacts--;
            printf("Contact removed successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

void search_contact() {
    char name[NAME_LENGTH];
    int index;

    printf("Enter the name of the contact to be searched: ");
    scanf("%s", name);

    for (index = 0; index < num_contacts; index++) {
        if (strcmp(contacts[index].name, name) == 0) {
            printf("Name: %s\n", contacts[index].name);
            printf("Phone: %s\n", contacts[index].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void display_all_contacts() {
    printf("\nPhonebook Contacts:\n");
    printf("--------------------\n");

    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("--------------------\n");
    }
}
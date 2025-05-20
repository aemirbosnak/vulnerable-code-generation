//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 50
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char phone[12];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void print_menu() {
    printf("\nPhone Book\n");
    printf("-------------------------------\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Delete Contact\n");
    printf("4. Display All Contacts\n");
    printf("5. Exit\n");
}

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter contact name: ");
    scanf("%s", contacts[num_contacts].name);
    contacts[num_contacts].name[strlen(contacts[num_contacts].name)] = '\0';

    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts].phone);
    contacts[num_contacts].phone[strlen(contacts[num_contacts].phone)] = '\0';

    num_contacts++;
    printf("Contact added successfully.\n");
}

void search_contact() {
    char name[NAME_LENGTH];
    int i;

    printf("Enter contact name to search: ");
    scanf("%s", name);

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found:\nName: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact() {
    char name[NAME_LENGTH];
    int i, j;

    printf("Enter contact name to delete: ");
    scanf("%s", name);

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (j = i; j < num_contacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            num_contacts--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

void display_contacts() {
    int i;

    if (num_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("-------------------------------\n");
    printf("| Name           | Phone       |\n");
    printf("-------------------------------\n");

    for (i = 0; i < num_contacts; i++) {
        printf("| %-15s | %-11s |\n", contacts[i].name, contacts[i].phone);
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
                display_contacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
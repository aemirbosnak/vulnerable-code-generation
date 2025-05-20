//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a contact
struct Contact {
    char name[50];
    char phone[15];
};

// Function to add a contact to the phone book
void add_contact(struct Contact* contacts, int size, struct Contact* new_contact) {
    if (size == 0 || strcmp(new_contact->name, contacts[size - 1].name) == 0) {
        printf("Contact already exists.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, new_contact->name) == 0) {
            strcpy(contacts[i].phone, new_contact->phone);
            printf("Contact updated successfully.\n");
            return;
        }
    }
    strcpy(contacts[size].name, new_contact->name);
    strcpy(contacts[size].phone, new_contact->phone);
    size++;
}

// Function to search for a contact in the phone book
void search_contact(struct Contact* contacts, int size, char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

// Function to delete a contact from the phone book
void delete_contact(struct Contact* contacts, int size, char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < size - 1; j++) {
                strcpy(contacts[j].name, contacts[j + 1].name);
                strcpy(contacts[j].phone, contacts[j + 1].phone);
            }
            size--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    struct Contact contacts[100];
    int size = 0;

    while (1) {
        char choice;
        printf("Enter choice: (a) Add contact, (s) Search contact, (d) Delete contact, (e) Exit:\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter contact name: ");
                scanf(" %s", contacts[size].name);
                printf("Enter contact phone number: ");
                scanf(" %s", contacts[size].phone);
                add_contact(contacts, size, &contacts[size]);
                size++;
                break;
            case's':
                printf("Enter contact name: ");
                scanf(" %s", contacts[size].name);
                search_contact(contacts, size, contacts[size].name);
                break;
            case 'd':
                printf("Enter contact name: ");
                scanf(" %s", contacts[size].name);
                delete_contact(contacts, size, contacts[size].name);
                size--;
                break;
            case 'e':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
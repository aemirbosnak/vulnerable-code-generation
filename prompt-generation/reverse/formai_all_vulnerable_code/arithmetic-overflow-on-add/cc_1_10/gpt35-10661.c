//FormAI DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Contact {
    char name[50];
    char phone[20];
    char address[100];
};

struct Phonebook {
    struct Contact contacts[1000];
    int numContacts;
};

void add_contact(struct Phonebook* phonebook) {
    printf("Enter name: ");
    scanf("%s", phonebook->contacts[phonebook->numContacts].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook->contacts[phonebook->numContacts].phone);
    printf("Enter address: ");
    scanf("%s", phonebook->contacts[phonebook->numContacts].address);
    phonebook->numContacts++;
    printf("Contact added successfully!\n\n");
}

void search_contact(struct Phonebook* phonebook) {
    char name[50];
    printf("Enter name to search for: ");
    scanf("%s", name);
    for (int i = 0; i < phonebook->numContacts; i++) {
        if (strcmp(phonebook->contacts[i].name, name) == 0) {
            printf("Name: %s\n", phonebook->contacts[i].name);
            printf("Phone: %s\n", phonebook->contacts[i].phone);
            printf("Address: %s\n\n", phonebook->contacts[i].address);
            return;
        }
    }
    printf("Contact not found.\n\n");
}

void print_phonebook(struct Phonebook* phonebook) {
    printf("Phone Book: \n");
    for (int i = 0; i < phonebook->numContacts; i++) {
        printf("Name: %s\n", phonebook->contacts[i].name);
        printf("Phone: %s\n", phonebook->contacts[i].phone);
        printf("Address: %s\n\n", phonebook->contacts[i].address);
    }
}

int main() {
    struct Phonebook phonebook;
    phonebook.numContacts = 0;
    int choice = 0;
    do {
        printf("Phone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Print Phone Book\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(&phonebook);
                break;
            case 2:
                search_contact(&phonebook);
                break;
            case 3:
                print_phonebook(&phonebook);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}
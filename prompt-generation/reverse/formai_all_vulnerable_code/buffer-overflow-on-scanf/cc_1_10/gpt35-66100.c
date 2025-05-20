//FormAI DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define PHONE_LENGTH 10
#define MAX_CONTACTS 100

struct contact {
    char name[NAME_LENGTH];
    char phone_number[PHONE_LENGTH];
};

// function declarations
void print_menu();
void add_contact(struct contact* phonebook, int* num_contacts);
void display_contacts(struct contact* phonebook, int num_contacts);
void search_contacts(struct contact* phonebook, int num_contacts);

int main() {
    struct contact phonebook[MAX_CONTACTS];
    int num_contacts = 0;
    int choice;

    while(1) {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact(phonebook, &num_contacts);
                break;
            case 2:
                display_contacts(phonebook, num_contacts);
                break;
            case 3:
                search_contacts(phonebook, num_contacts);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}

/* Prints the menu of options */
void print_menu() {
    printf("\n======================\n");
    printf("C Phone Book\n");
    printf("======================\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contacts\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

/* Adds a contact to the phonebook */
void add_contact(struct contact* phonebook, int* num_contacts) {
    // check if phonebook is full
    if(*num_contacts == MAX_CONTACTS) {
        printf("Phonebook is full. Cannot add any more contacts.\n");
        return;
    }

    struct contact new_contact;

    // get contact name
    printf("Enter contact name: ");
    scanf("%s", new_contact.name);

    // get contact phone number
    printf("Enter phone number: ");
    scanf("%s", new_contact.phone_number);

    // add contact to phonebook and increment num_contacts
    phonebook[*num_contacts] = new_contact;
    (*num_contacts)++;
}

/* Displays all contacts in the phonebook */
void display_contacts(struct contact* phonebook, int num_contacts) {
    // check if phonebook is empty
    if(num_contacts == 0) {
        printf("Phonebook is empty. No contacts to display.\n");
        return;
    }

    printf("\n========== Contacts ==========\n");

    for(int i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i+1, phonebook[i].name, phonebook[i].phone_number);
    }

    printf("==============================\n");
}

/* Searches the phonebook for a contact by name or phone number */
void search_contacts(struct contact* phonebook, int num_contacts) {
    // check if phonebook is empty
    if(num_contacts == 0) {
        printf("Phonebook is empty. No contacts to search.\n");
        return;
    }

    char query[NAME_LENGTH + PHONE_LENGTH];

    // get search query
    printf("Enter a name or phone number to search: ");
    scanf("%s", query);

    int found = 0;

    for(int i = 0; i < num_contacts; i++) {
        if(strcmp(query, phonebook[i].name) == 0 || strcmp(query, phonebook[i].phone_number) == 0) {
            printf("%s - %s\n", phonebook[i].name, phonebook[i].phone_number);
            found = 1;
        }
    }

    if(!found) {
        printf("No contacts found matching that query.\n");
    }
}
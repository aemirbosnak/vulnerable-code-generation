//FormAI DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>
#include <string.h>

// max number of contacts that can be stored
#define MAX_CONTACTS 100

// struct to represent a contact
typedef struct {
    char name[50];
    long long int phone_number;
} Contact;

// function to add a contact to the phone book
void add_contact(Contact phonebook[], int *num_contacts) {
    Contact c;
    printf("Enter name: ");
    scanf("%s", c.name);
    printf("Enter phone number: ");
    scanf("%lld", &c.phone_number);
    phonebook[*num_contacts] = c;
    (*num_contacts)++;
    printf("Contact added!\n\n");
}

// function to display all contacts in the phone book
void display_contacts(Contact phonebook[], int num_contacts) {
    if (num_contacts == 0) {
        printf("No contacts in phone book.\n\n");
        return;
    }
    printf("Contacts:\n");
    for (int i=0; i<num_contacts; i++) {
        printf("Name: %s\tPhone: %lld\n", phonebook[i].name, phonebook[i].phone_number);
    }
    printf("\n");
}

// function to search and display a contact from the phone book
void search_contact(Contact phonebook[], int num_contacts) {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i=0; i<num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\tPhone: %lld\n\n", phonebook[i].name, phonebook[i].phone_number);
            return;
        }
    }
    printf("Contact not found.\n\n");
}

int main() {
    Contact phonebook[MAX_CONTACTS];
    int num_contacts = 0;
    int choice;
    do {
        printf("Choose an option:\n");
        printf("1. Add contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(phonebook, &num_contacts);
                break;
            case 2:
                display_contacts(phonebook, num_contacts);
                break;
            case 3:
                search_contact(phonebook, num_contacts);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (choice != 4);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Structure for a contact
typedef struct contact {
    char first_name[50];
    char last_name[50];
    char phone_number[20];
} Contact;

// Function to add a contact
void add_contact(Contact contacts[], int num_contacts) {
    printf("Enter first name: ");
    scanf("%s", contacts[num_contacts].first_name);
    printf("Enter last name: ");
    scanf("%s", contacts[num_contacts].last_name);
    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts].phone_number);
    num_contacts++;
}

// Function to search for a contact by name
int search_contact(Contact contacts[], int num_contacts, char* name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].first_name, name) == 0 || strcmp(contacts[i].last_name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to print a contact
void print_contact(Contact contact) {
    printf("%s %s\n", contact.first_name, contact.last_name);
    printf("Phone number: %s\n", contact.phone_number);
}

// Function to print all contacts
void print_contacts(Contact contacts[], int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        print_contact(contacts[i]);
    }
}

// Main function
int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    printf("Welcome to the Phone Book!\n");
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Print all contacts\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, num_contacts);
                break;
            case 2:
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);
                int index = search_contact(contacts, num_contacts, name);
                if (index!= -1) {
                    print_contact(contacts[index]);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 3:
                print_contacts(contacts, num_contacts);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
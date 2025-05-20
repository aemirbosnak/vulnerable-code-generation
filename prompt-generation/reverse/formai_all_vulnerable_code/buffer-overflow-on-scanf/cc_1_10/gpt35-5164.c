//FormAI DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <string.h>

// maximum number of contacts in the phone book
#define MAX_CONTACTS 100

// contact struct
struct Contact {
    char name[50];
    char phone[20];
};

// function to add a contact to the phone book
void add_contact(struct Contact contacts[], int *num_contacts) {
    char name[50];
    char phone[20];

    printf("Enter contact name: ");
    scanf("%s", name);

    printf("Enter contact phone number: ");
    scanf("%s", phone);

    // add contact to the phone book
    strcpy(contacts[*num_contacts].name, name);
    strcpy(contacts[*num_contacts].phone, phone);
    (*num_contacts)++;

    printf("Contact added successfully!\n");
}

// function to search for a contact by name
void search_contact(struct Contact contacts[], int num_contacts) {
    char name[50];
    int found = 0;

    printf("Enter contact name to search for: ");
    scanf("%s", name);

    // loop through all contacts to find the one with the matching name
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found: %s (%s)\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// function to display all contacts in the phone book
void display_contacts(struct Contact contacts[], int num_contacts) {
    printf("Phone Book\n");
    printf("-----------\n");

    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    // initialize array of contacts
    struct Contact contacts[MAX_CONTACTS];

    // initialize number of contacts to 0
    int num_contacts = 0;

    int choice;

    do {
        printf("\n");
        printf("Phone Book Menu\n");
        printf("---------------\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // add contact
                add_contact(contacts, &num_contacts);
                break;
            case 2: // search contact
                search_contact(contacts, num_contacts);
                break;
            case 3: // display all contacts
                display_contacts(contacts, num_contacts);
                break;
            case 4: // exit
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Define a structure to hold contact information
typedef struct contact {
    char name[50];
    char phone_number[15];
} Contact;

// Function to add a new contact to the phone book
void add_contact(Contact *phone_book, int num_contacts) {
    // Create a new contact struct
    Contact new_contact;
    printf("Enter contact name: ");
    scanf("%s", new_contact.name);
    printf("Enter contact phone number: ");
    scanf("%s", new_contact.phone_number);

    // Add the new contact to the array
    phone_book[num_contacts] = new_contact;
    printf("Contact added!\n");

    // Ask the user if they want to add another contact
    char choice[10];
    printf("Add another contact? (y/n): ");
    scanf("%s", choice);
    if (strcmp(choice, "y") == 0) {
        add_contact(phone_book, num_contacts + 1);
    }
}

// Function to print all contacts in the phone book
void print_contacts(Contact *phone_book, int num_contacts) {
    // Print each contact in the array
    printf("Phone Book\n");
    printf("-----------\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", phone_book[i].name);
        printf("Phone: %s\n\n", phone_book[i].phone_number);
    }
}

int main() {
    Contact phone_book[MAX_CONTACTS];
    int num_contacts = 0;

    printf("My Phone Book\n");
    printf("-------------\n");

    // Ask the user to choose an option
    int choice = 0;
    while (choice != 3) {
        printf("Choose an option:\n");
        printf("1. Add a new contact\n");
        printf("2. View all contacts\n");
        printf("3. Quit\n");

        scanf("%d", &choice);

        // Call the appropriate function depending on the user's choice
        switch(choice) {
            case 1:
                add_contact(phone_book, num_contacts);
                num_contacts++;
                break;
            case 2:
                print_contacts(phone_book, num_contacts);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

    }

    return 0;
}
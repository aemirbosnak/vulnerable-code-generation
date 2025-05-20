//FormAI DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 30
#define MAX_ADDRESS_LENGTH 50
#define MAX_RECORDS 100

// create a struct to hold contact information
typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
} Contact;

// create a global array to store the contacts
Contact contacts[MAX_RECORDS];

// initialize the global variables
int num_contacts = 0;

// function prototypes
void add_contact();
void display_all_contacts();
void search_contact();

int main() {
    int option;

    printf("Welcome to the Contact Database Simulation!\n");

    do {
        // display menu options
        printf("\nPlease choose an option:\n");
        printf("1. Add new contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Quit\n");

        // get user's choice
        scanf("%d", &option);

        // call appropriate function based on user's choice
        switch (option) {
            case 1:
                add_contact();
                break;
            case 2:
                display_all_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}

void add_contact() {
    // check if max number of contacts has been reached
    if (num_contacts >= MAX_RECORDS) {
        printf("Database is full. Cannot add more contacts.\n");
        return;
    }

    // prompt user for contact information
    Contact new_contact;

    printf("\nEnter contact name: ");
    scanf("%s", new_contact.name);

    printf("Enter contact phone number: ");
    scanf("%s", new_contact.phone);

    printf("Enter contact email address: ");
    scanf("%s", new_contact.email);

    printf("Enter contact address: ");
    scanf("%s", new_contact.address);

    // add new contact to array
    contacts[num_contacts++] = new_contact;

    printf("Contact added successfully.\n");
}

void display_all_contacts() {
    // check if any contacts have been added
    if (num_contacts == 0) {
        printf("No contacts found.\n");
        return;
    }

    // print header row
    printf("\n%-20s %-15s %-30s %-50s\n\n", "Name", "Phone", "Email", "Address");

    // print each contact
    for (int i = 0; i < num_contacts; i++) {
        Contact current_contact = contacts[i];
        printf("%-20s %-15s %-30s %-50s\n", current_contact.name,
               current_contact.phone, current_contact.email, current_contact.address);
    }
}

void search_contact() {
    // check if any contacts have been added
    if (num_contacts == 0) {
        printf("No contacts found.\n");
        return;
    }

    // prompt user for search query
    char query[MAX_NAME_LENGTH];
    printf("\nEnter name to search for: ");
    scanf("%s", query);

    // search for matching contacts
    int num_matches = 0;

    for (int i = 0; i < num_contacts; i++) {
        Contact current_contact = contacts[i];

        if (strcmp(current_contact.name, query) == 0) {
            num_matches++;

            if (num_matches == 1) {
                // print header row for search results table
                printf("\n%-20s %-15s %-30s %-50s\n\n",
                       "Name", "Phone", "Email", "Address");
            }

            // print current contact
            printf("%-20s %-15s %-30s %-50s\n", current_contact.name,
                   current_contact.phone, current_contact.email, current_contact.address);
        }
    }

    // print message if no matches were found
    if (num_matches == 0) {
        printf("No matches found for '%s'\n", query);
    }
}
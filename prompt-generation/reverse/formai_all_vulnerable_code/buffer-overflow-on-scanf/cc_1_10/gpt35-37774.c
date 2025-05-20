//FormAI DATASET v1.0 Category: Phone Book ; Style: calm
/* This C Phone Book example program stores and manages a list of phone numbers and names. 
   Users can add, delete, search and print all contacts in the phone book */

#include <stdio.h>
#include <string.h>

// Define the maximum number of contacts that can be stored
#define MAX_CONTACTS 100

// Define struct for a single contact -- each contact will have a name and a phone number
typedef struct {
    char name[50];
    char phone_number[20];
} Contact;

// Declare global array of contacts
Contact phone_book[MAX_CONTACTS];

// Declare function prototypes
void add_contact();
void delete_contact();
void search_contact();
void print_all_contacts();

// Main function
int main() {

    int choice = 0;
    int num_contacts = 0;

    // Print welcome message and menu options
    printf("Welcome to Phone Book\n");
    printf("---------------------\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Search Contact\n");
    printf("4. Print All Contacts\n");
    printf("5. Exit\n");

    // Loop until user chooses to exit
    while (choice != 5) {

        // Ask user for choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add contact
                add_contact(&num_contacts);
                break;
            case 2: // Delete contact
                delete_contact(&num_contacts);
                break;
            case 3: // Search contact
                search_contact(num_contacts);
                break;
            case 4: // Print all contacts
                print_all_contacts(num_contacts);
                break;
            case 5: // Exit program
                printf("\nThank you for using Phone Book\n");
                break;
            default: // Invalid choice
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to add contact to phone book
void add_contact(int *num_contacts) {

    // Only add contact if there is still space in the phone book
    if (*num_contacts < MAX_CONTACTS) {

        // Get name and phone number from user
        printf("\nEnter name: ");
        scanf(" %[^\n]", phone_book[*num_contacts].name);
        printf("Enter phone number: ");
        scanf(" %s", phone_book[*num_contacts].phone_number);

        // Increment number of contacts
        (*num_contacts)++;
        printf("\nContact successfully added.\n");

    } else { // Phone book is full
        printf("\nSorry, phone book is full.\n");
    }
}

// Function to delete contact from phone book
void delete_contact(int *num_contacts) {

    int i, j;
    char name[50];

    // Get name of contact to be deleted
    printf("\nEnter name of contact to delete: ");
    scanf(" %[^\n]", name);

    // Look for the contact with the given name
    for (i=0; i<*num_contacts; i++) {

        // If contact is found, remove it by shifting all contacts after it one position to the left
        if (strcmp(name, phone_book[i].name) == 0) {
            for(j=i; j<*num_contacts-1; j++) {
                strcpy(phone_book[j].name, phone_book[j+1].name);
                strcpy(phone_book[j].phone_number, phone_book[j+1].phone_number);
            }
            (*num_contacts)--;
            printf("\nContact successfully deleted.\n");
            return;
        }
    }

    // If contact is not found, display error message
    printf("\nContact not found.\n");
}

// Function to search for contact in phone book
void search_contact(int num_contacts) {

    int i;
    char name[50];

    // Get name of contact to search for
    printf("\nEnter name of contact to search for: ");
    scanf(" %[^\n]", name);

    // Look for contact with the given name
    for (i=0; i<num_contacts; i++) {

        // If contact is found, display its name and phone number
        if (strcmp(name, phone_book[i].name) == 0) {
            printf("\n%s: %s\n", phone_book[i].name, phone_book[i].phone_number);
            return;
        }
    }

    // If contact is not found, display error message
    printf("\nContact not found.\n");
}

// Function to print all contacts in phone book
void print_all_contacts(int num_contacts) {

    int i;

    // Only print contacts if there are any stored
    if (num_contacts > 0) {
        printf("\nAll contacts:\n");
        for (i=0; i<num_contacts; i++) {
            printf("%s: %s\n", phone_book[i].name, phone_book[i].phone_number);
        }
    } else {
        printf("\nThere are no contacts in the phone book.\n");
    }
}
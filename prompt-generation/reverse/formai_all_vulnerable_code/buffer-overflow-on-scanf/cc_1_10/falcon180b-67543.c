//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_CONTACTS 100

// Define the structure for a contact
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[15];
} Contact;

// Function to add a contact to the phone book
void add_contact(Contact phone_book[], int num_contacts, char name[], char phone_number[]) {
    // Check if the phone book is full
    if (num_contacts == MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    // Add the new contact to the phone book
    strcpy(phone_book[num_contacts].name, name);
    strcpy(phone_book[num_contacts].phone_number, phone_number);
    num_contacts++;
}

// Function to search for a contact in the phone book
int search_contact(Contact phone_book[], int num_contacts, char name[]) {
    // Loop through the phone book and compare names
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            // Contact found, return its index
            return i;
        }
    }

    // Contact not found, return -1
    return -1;
}

// Function to print the phone book
void print_phone_book(Contact phone_book[], int num_contacts) {
    // Loop through the phone book and print each contact
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

// Main function
int main() {
    // Initialize the phone book with an empty contact
    Contact phone_book[MAX_CONTACTS];
    strcpy(phone_book[0].name, "");
    strcpy(phone_book[0].phone_number, "");
    int num_contacts = 1;

    // Get user input for adding contacts
    char name[MAX_NAME_LENGTH];
    char phone_number[15];
    while (1) {
        printf("Enter name (or leave blank to exit): ");
        scanf("%s", name);
        if (name[0] == '\0') {
            break;
        }
        printf("Enter phone number: ");
        scanf("%s", phone_number);

        // Add the new contact to the phone book
        add_contact(phone_book, num_contacts, name, phone_number);
        num_contacts++;
    }

    // Get user input for searching contacts
    char search_name[MAX_NAME_LENGTH];
    int search_result;
    while (1) {
        printf("Enter name to search for: ");
        scanf("%s", search_name);

        // Search for the contact in the phone book
        search_result = search_contact(phone_book, num_contacts, search_name);

        // Print the contact information if found, or a message if not
        if (search_result!= -1) {
            printf("Contact found!\n");
            printf("%s: %s\n", phone_book[search_result].name, phone_book[search_result].phone_number);
        } else {
            printf("Contact not found.\n");
        }

        // Ask the user if they want to search again
        char choice[3];
        printf("Search again? (y/n): ");
        scanf("%s", choice);
        if (strcmp(choice, "n") == 0) {
            break;
        }
    }

    // Print the phone book
    printf("\nPhone book:\n");
    print_phone_book(phone_book, num_contacts);

    return 0;
}
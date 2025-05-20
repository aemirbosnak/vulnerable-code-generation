//FormAI DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of contacts for the phone book
#define MAX_CONTACTS 100

// Declare a struct for storing contact details
struct Contact {
    char name[50];
    char phone_number[20];
    char email[50];
};

// Declare an array of contacts to store multiple contacts in the phone book
struct Contact phone_book[MAX_CONTACTS];

// Declare global variables to keep track of the number of contacts in the phone book
int num_contacts = 0;

// Function prototypes
void add_contact();
void search_contact();
void display_all();
void delete_contact();
void clear_phone_book();

int main() {
    int choice;

    do {
        // Display phone book menu
        printf("\n\nPHONE BOOK MENU\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Delete Contact\n");
        printf("5. Clear Phone Book\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                display_all();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                clear_phone_book();
                break;
            case 6:
                // Exit program
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a valid choice (1-6).\n");
        }
    } while (choice != 6);

    return 0;
}

void add_contact() {
    // Check if phone book is already full
    if (num_contacts == MAX_CONTACTS) {
        printf("\nCannot add new contact - phone book is already full!\n");
        return;
    }

    // Declare a temporary contact to store data before adding it to phone book
    struct Contact temp_contact;

    // Get name input from user
    printf("\nEnter name: ");
    scanf("%s", temp_contact.name);

    // Get phone number input from user
    printf("Enter phone number: ");
    scanf("%s", temp_contact.phone_number);

    // Get email input from user
    printf("Enter email: ");
    scanf("%s", temp_contact.email);

    // Add contact to phone book
    phone_book[num_contacts] = temp_contact;
    num_contacts++;

    printf("\nContact added successfully!\n");
}

void search_contact() {
    // Declare variables for storing search query and results
    char query[50];
    struct Contact results[MAX_CONTACTS];
    int num_results = 0;

    // Get search query from user
    printf("\nEnter search query: ");
    scanf("%s", query);

    // Search phone book for contacts matching search query
    for (int i = 0; i < num_contacts; i++) {
        if (strstr(phone_book[i].name, query) != NULL || strstr(phone_book[i].phone_number, query) != NULL || strstr(phone_book[i].email, query) != NULL) {
            results[num_results] = phone_book[i];
            num_results++;
        }
    }

    // Print search results
    if (num_results > 0) {
        printf("\nSearch results:\n");
        for (int i = 0; i < num_results; i++) {
            printf("%d. Name: %s\n", i+1, results[i].name);
            printf("   Phone number: %s\n", results[i].phone_number);
            printf("   Email: %s\n", results[i].email);
        }
    } else {
        printf("\nNo contacts found matching search query.\n");
    }
}

void display_all() {
    // Check if any contacts exist in phone book
    if (num_contacts == 0) {
        printf("\nPhone book is empty!\n");
        return;
    }

    printf("\nAll contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. Name: %s\n", i+1, phone_book[i].name);
        printf("   Phone number: %s\n", phone_book[i].phone_number);
        printf("   Email: %s\n", phone_book[i].email);
    }
}

void delete_contact() {
    // Check if any contacts exist in phone book
    if (num_contacts == 0) {
        printf("\nPhone book is empty - nothing to delete!\n");
        return;
    }

    // Declare variable for storing index of contact to delete
    int index;

    // Get index of contact to delete from user
    printf("\nEnter index of contact to delete: ");
    scanf("%d", &index);

    // Check if index is valid
    if (index < 1 || index > num_contacts) {
        printf("\nInvalid index - please enter a valid index between 1 and %d.\n", num_contacts);
        return;
    }

    // Shift all contacts after deleted contact one index to the left
    for (int i = index; i < num_contacts; i++) {
        phone_book[i-1] = phone_book[i];
    }

    // Decrement number of contacts in phone book
    num_contacts--;

    printf("\nContact deleted successfully!\n");
}

void clear_phone_book() {
    // Initialize phone book to empty
    memset(phone_book, 0, sizeof(phone_book));
    num_contacts = 0;
    printf("\nPhone book cleared successfully!\n");
}
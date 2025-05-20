//FormAI DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of name and phone number
#define MAX_NAME_LEN 20
#define MAX_PHONE_LEN 15

// Define the maximum number of contacts in the phone book
#define MAX_CONTACTS 100

// Define struct for a contact in the phone book
typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} Contact;

// Declare the phone book array of contacts
Contact phone_book[MAX_CONTACTS];

// Declare the number of contacts currently in the phone book
int num_contacts = 0;

// Declare function prototypes
void add_contact();
void delete_contact();
void search_contact();
void print_phone_book();

int main() {
    int choice;
    do {
        // Print main menu
        printf("\nPhone Book Menu\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Print Phone Book\n");
        printf("5. Exit\n");

        // Prompt the user for their choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Execute the appropriate action based on the user's choice
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                delete_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                print_phone_book();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void add_contact() {
    // Check if the phone book is full
    if (num_contacts == MAX_CONTACTS) {
        printf("The phone book is full. Please delete a contact before adding a new one.\n");
        return;
    }

    // Prompt the user for the new contact's name and phone number
    printf("\nEnter the new contact's name (up to %d characters): ", MAX_NAME_LEN-1);
    scanf("%s", phone_book[num_contacts].name);
    printf("Enter the new contact's phone number (up to %d characters): ", MAX_PHONE_LEN-1);
    scanf("%s", phone_book[num_contacts].phone);

    // Increment the number of contacts in the phone book
    num_contacts++;

    printf("Contact added successfully!\n");
}

void delete_contact() {
    // Prompt the user for the name of the contact to delete
    char name_to_delete[MAX_NAME_LEN];
    printf("\nEnter the name of the contact to delete: ");
    scanf("%s", name_to_delete);

    // Search for the contact in the phone book
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name_to_delete) == 0) {
            // Shift all contacts after the deleted contact back by one position
            int j;
            for (j = i; j < num_contacts-1; j++) {
                phone_book[j] = phone_book[j+1];
            }

            // Decrement the number of contacts in the phone book
            num_contacts--;

            printf("Contact deleted successfully!\n");
            return;
        }
    }

    // If the contact was not found in the phone book
    printf("Contact not found. Please try again.\n");
}

void search_contact() {
    // Prompt the user for the name of the contact to search for
    char name_to_search[MAX_NAME_LEN];
    printf("\nEnter the name of the contact to search for: ");
    scanf("%s", name_to_search);

    // Search for the contact in the phone book
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name_to_search) == 0) {
            printf("Contact found:\nName: %s\nPhone: %s\n", phone_book[i].name, phone_book[i].phone);
            return;
        }
    }

    // If the contact was not found in the phone book
    printf("Contact not found. Please try again.\n");
}

void print_phone_book() {
    // Print the header row of the phone book table
    printf("\nPhone Book:\n");
    printf("Name\tPhone\n");

    // Print each contact in the phone book
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", phone_book[i].name, phone_book[i].phone);
    }
}
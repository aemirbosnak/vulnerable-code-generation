//FormAI DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_NAME_LEN 20
#define MAX_NUM_LEN 15
#define MAX_CONTACTS 100

// Structure to hold contact information
typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} Contact;

// Global Variables
Contact phone_book[MAX_CONTACTS];
int num_of_contacts = 0;

// Function Prototypes
void add_contact();
void search_contact();
void display_contacts();
int compare(const void* a, const void* b);

// Main Function
int main() {
    int choice;

    printf("Welcome to the C Phone Book!\n");

    do {
        // Display menu
        printf("\nMenu\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Quit\n");

        // Prompt user for choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user's choice
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                display_contacts();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to add a new contact to the phone book
void add_contact() {
    if (num_of_contacts >= MAX_CONTACTS) {
        printf("The phone book is full!\n");
    } else {
        Contact new_contact;

        // Prompt user for name and number
        printf("\nEnter name: ");
        scanf("%s", new_contact.name);
        printf("Enter number: ");
        scanf("%s", new_contact.number);

        // Add new contact to phone book
        phone_book[num_of_contacts] = new_contact;
        num_of_contacts++;

        printf("Contact added!\n");
    }
}

// Function to search the phone book for a contact
void search_contact() {
    char search_name[MAX_NAME_LEN];
    int i;

    // Prompt user for name to search
    printf("\nEnter name to search: ");
    scanf("%s", search_name);

    // Search for the contact in the phone book
    for (i = 0; i < num_of_contacts; i++) {
        if (strcmp(search_name, phone_book[i].name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\nNumber: %s\n", phone_book[i].name, phone_book[i].number);
            return;
        }
    }

    printf("Contact not found!\n");
}

// Function to display all contacts in the phone book
void display_contacts() {
    int i;

    // Sort contacts by name
    qsort(phone_book, num_of_contacts, sizeof(Contact), compare);

    // Display contacts
    printf("\nContacts\n");
    for (i = 0; i < num_of_contacts; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
    }
}

// Function to compare two contacts by name
int compare(const void* a, const void* b) {
    return strcmp(((Contact*)a)->name, ((Contact*)b)->name);
}
//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct contact {
    char name[50];
    char number[20];
} contact;

// Function to compare two contacts by name
int compare_contacts(const void *a, const void *b) {
    const contact *contact1 = (const contact *)a;
    const contact *contact2 = (const contact *)b;
    return strcmp(contact1->name, contact2->name);
}

// Function to print a contact
void print_contact(const contact *contact) {
    printf("%s: %s\n", contact->name, contact->number);
}

// Function to add a contact to the phone book
void add_contact(contact **phone_book, int *num_contacts) {
    // Allocate memory for the new contact
    contact *new_contact = (contact *)malloc(sizeof(contact));

    // Get the name and number of the new contact
    printf("Enter the name of the new contact: ");
    scanf(" %[^\n]", new_contact->name);
    printf("Enter the number of the new contact: ");
    scanf(" %[^\n]", new_contact->number);

    // Add the new contact to the phone book
    phone_book[*num_contacts] = new_contact;
    (*num_contacts)++;
}

// Function to search for a contact in the phone book
void search_contact(contact **phone_book, int num_contacts) {
    // Get the name of the contact to search for
    char search_name[50];
    printf("Enter the name of the contact to search for: ");
    scanf(" %[^\n]", search_name);

    // Search for the contact using binary search
    int low = 0;
    int high = num_contacts - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int comparison = strcmp(search_name, phone_book[mid]->name);

        if (comparison == 0) {
            // Contact found
            printf("Contact found:\n");
            print_contact(phone_book[mid]);
            return;
        } else if (comparison < 0) {
            // Search the left half
            high = mid - 1;
        } else {
            // Search the right half
            low = mid + 1;
        }
    }

    // Contact not found
    printf("Contact not found.\n");
}

// Function to delete a contact from the phone book
void delete_contact(contact **phone_book, int *num_contacts) {
    // Get the name of the contact to delete
    char delete_name[50];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", delete_name);

    // Search for the contact using binary search
    int low = 0;
    int high = *num_contacts - 1;
    int contact_index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int comparison = strcmp(delete_name, phone_book[mid]->name);

        if (comparison == 0) {
            // Contact found
            contact_index = mid;
            break;
        } else if (comparison < 0) {
            // Search the left half
            high = mid - 1;
        } else {
            // Search the right half
            low = mid + 1;
        }
    }

    // Contact not found
    if (contact_index == -1) {
        printf("Contact not found.\n");
        return;
    }

    // Delete the contact from the phone book
    free(phone_book[contact_index]);
    for (int i = contact_index + 1; i < *num_contacts; i++) {
        phone_book[i - 1] = phone_book[i];
    }
    (*num_contacts)--;

    // Contact deleted
    printf("Contact deleted.\n");
}

// Function to print the phone book
void print_phone_book(contact **phone_book, int num_contacts) {
    printf("Phone book:\n");
    for (int i = 0; i < num_contacts; i++) {
        print_contact(phone_book[i]);
    }
}

// Main function
int main() {
    // Initialize the phone book
    contact *phone_book[100];
    int num_contacts = 0;

    // Main loop
    int choice;
    do {
        // Print the menu
        printf("\n1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Print the phone book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_contact(phone_book, &num_contacts);
                qsort(phone_book, num_contacts, sizeof(contact *), compare_contacts);
                break;
            case 2:
                search_contact(phone_book, num_contacts);
                break;
            case 3:
                delete_contact(phone_book, &num_contacts);
                break;
            case 4:
                print_phone_book(phone_book, num_contacts);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    // Free the memory allocated for the contacts
    for (int i = 0; i < num_contacts; i++) {
        free(phone_book[i]);
    }

    return 0;
}
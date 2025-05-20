//FormAI DATASET v1.0 Category: Phone Book ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 15
#define PHONEBOOK_SIZE 100

// Structure to hold phone book entries
typedef struct phonebook_entry {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} phonebook_entry_t;

// Array to hold phone book entries
phonebook_entry_t phonebook[PHONEBOOK_SIZE];

// Current size of phone book
int phonebook_size = 0;

// Function declarations
void add_entry(char* name, char* phone);
void delete_entry(char* name);
void search_entry(char* name);
void print_phonebook();
void print_menu();
int validate_phone_number(char* phone);

// Main program loop
int main() {

    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int choice = 0;

    // Display menu and get user input
    while (choice != 5) {

        print_menu();
        scanf("%d", &choice);

        switch (choice) {

            case 1:  // Add new entry
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter phone (XXX-XXX-XXXX format only): ");
                scanf("%s", phone);

                if (validate_phone_number(phone)) {
                    // Add entry if phone number is valid
                    add_entry(name, phone);
                    printf("\nEntry added successfully!\n");
                } else {
                    printf("\nInvalid phone number format, please try again.\n");
                }
                break;

            case 2:  // Delete entry
                printf("\nEnter name: ");
                scanf("%s", name);

                // Delete entry if it exists
                delete_entry(name);
                break;

            case 3:  // Search for entry
                printf("\nEnter name: ");
                scanf("%s", name);

                // Search for entry if it exists
                search_entry(name);
                break;

            case 4:  // Print phone book
                print_phonebook();
                break;

            case 5:  // Quit
                printf("\nGoodbye!\n");
                break;

            default:  // Invalid choice
                printf("\nInvalid choice, please try again.\n");
                break;

        }

    }

    return 0;
}

// Add a new entry to the phone book
void add_entry(char* name, char* phone) {

    // Create new phone book entry and add it to the array
    phonebook_entry_t new_entry;
    strcpy(new_entry.name, name);
    strcpy(new_entry.phone, phone);
    phonebook[phonebook_size++] = new_entry;
}

// Delete an entry from the phone book
void delete_entry(char* name) {

    // Search for the entry
    int index = -1;
    for (int i = 0; i < phonebook_size; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Delete the entry if it was found
    if (index != -1) {
        // Shift elements to fill the gap
        for (int i = index; i < phonebook_size - 1; i++) {
            phonebook[i] = phonebook[i + 1];
        }

        // Decrement phone book size
        phonebook_size--;
        printf("\nEntry deleted successfully!\n");
    } else {
        printf("\nEntry not found.\n");
    }

}

// Search for an entry in the phone book
void search_entry(char* name) {

    // Search for the entry
    int index = -1;
    for (int i = 0; i < phonebook_size; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Print the entry if it was found
    if (index != -1) {
        printf("\n%s: %s\n", phonebook[index].name, phonebook[index].phone);
    } else {
        printf("\nEntry not found.\n");
    }

}

// Print the entire phone book
void print_phonebook() {
    printf("\n%-20s%s\n", "Name", "Phone Number");
    for (int i = 0; i < phonebook_size; i++) {
        printf("%-20s%s\n", phonebook[i].name, phonebook[i].phone);
    }
}

// Print menu options
void print_menu() {
    printf("\n=== PHONE BOOK ===\n");
    printf("1. Add new entry\n");
    printf("2. Delete entry\n");
    printf("3. Search for entry\n");
    printf("4. Print phone book\n");
    printf("5. Quit\n");
    printf("Enter choice (1-5): ");
}

// Validate phone number format
int validate_phone_number(char* phone) {

    int count = 0;

    // Check length of string
    if (strlen(phone) != 12) {
        return 0;
    }

    // Check format of string
    for (int i = 0; i < 12; i++) {
        if (i == 3 || i == 7) {
            if (phone[i] != '-') {
                return 0;
            }
        } else if (phone[i] < '0' || phone[i] > '9') {
            return 0;
        } else {
            count++;
        }
    }

    // Check number of digits in string
    if (count != 10) {
        return 0;
    }

    return 1;

}
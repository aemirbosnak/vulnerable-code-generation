//FormAI DATASET v1.0 Category: Phone Book ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY 100

// Structure definition
struct phonebook_entry {
    char name[50];
    char phone_number[20];
};

// Global variables
struct phonebook_entry phonebook[MAX_ENTRY];
int num_entries = 0;

// Function prototypes
void print_banner();
void add_entry();
void print_entries();
void search_entry();
int is_valid_phone_number(char *phone_number);

// Main function
int main() {
    char choice;

    while (1) {
        print_banner();

        printf("\nPlease enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_entry();
                break;
            case '2':
                print_entries();
                break;
            case '3':
                search_entry();
                break;
            case '0':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function that prints the program's banner
void print_banner() {
    printf("------------------------------------\n");
    printf("        C Phone Book Program        \n");
    printf("------------------------------------\n");
    printf("1. Add an entry\n");
    printf("2. Print phone book\n");
    printf("3. Search for an entry\n");
    printf("0. Quit\n");
    printf("------------------------------------\n");
}

// Function that adds an entry to the phone book
void add_entry() {
    if (num_entries >= MAX_ENTRY) {
        printf("Phone book full. Cannot add more entries.\n");
        return;
    }

    struct phonebook_entry new_entry;

    printf("\nEnter name: ");
    scanf(" %s", new_entry.name);

    printf("Enter phone number: ");
    scanf(" %s", new_entry.phone_number);

    // Validate phone number
    if (!is_valid_phone_number(new_entry.phone_number)) {
        printf("Invalid phone number. Please enter a valid phone number.\n");
        return;
    }

    phonebook[num_entries] = new_entry;
    num_entries++;

    printf("Entry added successfully!\n");
}

// Function that prints all entries in the phone book
void print_entries() {
    if (num_entries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("\nPhone Book\n----------\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", phonebook[i].name, phonebook[i].phone_number);
    }

    printf("\n");
}

// Function that searches for an entry in the phone book
void search_entry() {
    if (num_entries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char search_name[50];

    printf("\nEnter name to search: ");
    scanf(" %s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Found: %s - %s\n", phonebook[i].name, phonebook[i].phone_number);
            return;
        }
    }

    printf("Entry not found.\n");
}

// Function that validates phone numbers
int is_valid_phone_number(char *phone_number) {
    int len = strlen(phone_number);

    // Phone number must have only digits and be of length 10
    for (int i = 0; i < len; i++) {
        if (!(isdigit(phone_number[i]))) {
            return 0;
        }
    }

    return (len == 10);
}
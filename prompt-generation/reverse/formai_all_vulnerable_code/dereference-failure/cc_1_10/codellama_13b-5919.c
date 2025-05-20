//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: light-weight
/*
 * C Phone Book Example Program
 *
 * This program allows the user to add, remove, and search for entries in a phone book.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about a person
typedef struct {
    char name[50];
    char phone[15];
} Entry;

// Global variables
int num_entries = 0;
Entry *phone_book = NULL;

// Function prototypes
void print_menu();
void add_entry(Entry *entry);
void remove_entry(Entry *entry);
void search_entry(Entry *entry);

int main() {
    int choice;

    // Allocate memory for the phone book
    phone_book = (Entry *) malloc(sizeof(Entry) * 100);

    // Print the menu
    print_menu();

    // Loop until the user quits
    while (1) {
        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Add an entry
        if (choice == 1) {
            Entry entry;
            printf("Enter the name: ");
            scanf("%s", entry.name);
            printf("Enter the phone number: ");
            scanf("%s", entry.phone);
            add_entry(&entry);
        }

        // Remove an entry
        else if (choice == 2) {
            Entry entry;
            printf("Enter the name: ");
            scanf("%s", entry.name);
            remove_entry(&entry);
        }

        // Search for an entry
        else if (choice == 3) {
            Entry entry;
            printf("Enter the name: ");
            scanf("%s", entry.name);
            search_entry(&entry);
        }

        // Quit the program
        else if (choice == 4) {
            break;
        }

        // Invalid choice
        else {
            printf("Invalid choice.\n");
        }
    }

    // Free the memory allocated for the phone book
    free(phone_book);

    return 0;
}

// Function to print the menu
void print_menu() {
    printf("Phone Book\n");
    printf("1. Add an entry\n");
    printf("2. Remove an entry\n");
    printf("3. Search for an entry\n");
    printf("4. Quit\n");
}

// Function to add an entry to the phone book
void add_entry(Entry *entry) {
    // Check if the phone book is full
    if (num_entries == 100) {
        printf("Phone book is full.\n");
        return;
    }

    // Add the entry to the phone book
    phone_book[num_entries] = *entry;
    num_entries++;
}

// Function to remove an entry from the phone book
void remove_entry(Entry *entry) {
    // Check if the entry exists in the phone book
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, entry->name) == 0) {
            break;
        }
    }

    // If the entry does not exist, return
    if (i == num_entries) {
        printf("Entry not found.\n");
        return;
    }

    // Remove the entry from the phone book
    for (; i < num_entries - 1; i++) {
        phone_book[i] = phone_book[i + 1];
    }
    num_entries--;
}

// Function to search for an entry in the phone book
void search_entry(Entry *entry) {
    // Check if the entry exists in the phone book
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, entry->name) == 0) {
            break;
        }
    }

    // If the entry does not exist, return
    if (i == num_entries) {
        printf("Entry not found.\n");
        return;
    }

    // Print the entry's information
    printf("Name: %s\nPhone number: %s\n", phone_book[i].name, phone_book[i].phone);
}
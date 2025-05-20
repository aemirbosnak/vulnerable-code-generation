//FormAI DATASET v1.0 Category: Phone Book ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a maximum size for the phone book
#define MAX_SIZE 100

// Define a struct to hold an entry in the phone book
struct PhoneBookEntry {
    char name[50];
    char phone_number[15];
};

// Define the phone book as an array of PhoneBookEntry structs
struct PhoneBookEntry phone_book[MAX_SIZE];

// Define a variable to keep track of the number of entries in the phone book
int num_entries = 0;

// Function to add a new entry to the phone book
void add_entry() {
    // Check if the phone book is already at max capacity
    if (num_entries == MAX_SIZE) {
        printf("Phone book is at maximum capacity.\n");
        return;
    }

    // Prompt the user for the name and phone number
    char name[50];
    char phone_number[15];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phone_number);

    // Add the new entry to the phone book and increment the number of entries
    strcpy(phone_book[num_entries].name, name);
    strcpy(phone_book[num_entries].phone_number, phone_number);
    num_entries++;

    printf("Entry added successfully.\n");
}

// Function to search for an entry in the phone book
void search_entry() {
    // If the phone book is empty, there is nothing to search for
    if (num_entries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    // Prompt the user for the name to search for
    char search_name[50];
    printf("Enter name to search for: ");
    scanf("%s", search_name);

    // Loop through the phone book to find the name
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phone_book[i].name, phone_book[i].phone_number);
            found = 1;
            break;
        }
    }

    // If the name was not found, print an error message
    if (!found) {
        printf("Entry not found.\n");
    }
}

// Function to print all entries in the phone book
void print_book() {
    // If the phone book is empty, there is nothing to print
    if (num_entries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Name\t\tPhone Number\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t\t%s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

// Function to show the menu and prompt for user input
void show_menu() {
    printf("\n");
    printf("1. Add new entry\n");
    printf("2. Search for an entry\n");
    printf("3. Print phone book\n");
    printf("4. Exit\n");
    printf("\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            search_entry();
            break;
        case 3:
            print_book();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    show_menu();
}

// Main function to run the phone book program
int main() {
    printf("*** C Phone Book Example Program ***\n");
    show_menu();
    return 0;
}
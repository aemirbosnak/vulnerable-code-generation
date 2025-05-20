//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the structure of a diary entry
typedef struct diary_entry {
    char date[11];
    char title[50];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the array of diary entries
diary_entry entries[MAX_ENTRIES];

// Define the current number of diary entries
int num_entries = 0;

// Function to add a new diary entry
void add_entry(char *date, char *title, char *entry) {
    // Check if the array of diary entries is full
    if (num_entries == MAX_ENTRIES) {
        printf("The diary is full. No more entries can be added.\n");
        return;
    }

    // Copy the date, title, and entry into the array of diary entries
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].title, title);
    strcpy(entries[num_entries].entry, entry);

    // Increment the current number of diary entries
    num_entries++;
}

// Function to read a diary entry
void read_entry(int index) {
    // Check if the index is valid
    if (index < 0 || index >= num_entries) {
        printf("Invalid index. No such diary entry exists.\n");
        return;
    }

    // Print the date, title, and entry of the diary entry
    printf("Date: %s\n", entries[index].date);
    printf("Title: %s\n", entries[index].title);
    printf("Entry: %s\n", entries[index].entry);
}

// Function to delete a diary entry
void delete_entry(int index) {
    // Check if the index is valid
    if (index < 0 || index >= num_entries) {
        printf("Invalid index. No such diary entry exists.\n");
        return;
    }

    // Shift the remaining diary entries down one index
    for (int i = index + 1; i < num_entries; i++) {
        entries[i - 1] = entries[i];
    }

    // Decrement the current number of diary entries
    num_entries--;
}

// Function to print the menu
void print_menu() {
    printf("Sherlock Holmes's Digital Diary\n");
    printf("============================\n");
    printf("1. Add a new entry\n");
    printf("2. Read an entry\n");
    printf("3. Delete an entry\n");
    printf("4. Quit\n");
    printf("> ");
}

// Function to get the user's choice
int get_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Function to main loop
int main() {
    // Print the menu
    print_menu();

    // Get the user's choice
    int choice = get_choice();

    // While the user does not choose to quit
    while (choice != 4) {
        // Add a new entry
        if (choice == 1) {
            // Get the date, title, and entry from the user
            char date[11];
            char title[50];
            char entry[MAX_ENTRY_LENGTH];
            printf("Enter the date: ");
            scanf("%s", date);
            printf("Enter the title: ");
            scanf(" %[^\n]", title); // To allow spaces in the title
            printf("Enter the entry: ");
            gets(entry); // To allow multiple lines in the entry
            add_entry(date, title, entry);
        }

        // Read an entry
        else if (choice == 2) {
            // Get the index of the entry from the user
            int index;
            printf("Enter the index of the entry: ");
            scanf("%d", &index);
            read_entry(index);
        }

        // Delete an entry
        else if (choice == 3) {
            // Get the index of the entry from the user
            int index;
            printf("Enter the index of the entry: ");
            scanf("%d", &index);
            delete_entry(index);
        }

        // Print the menu again
        print_menu();

        // Get the user's choice
        choice = get_choice();
    }

    // Quit the program
    printf("Thank you for using Sherlock Holmes's Digital Diary.\n");
    return 0;
}
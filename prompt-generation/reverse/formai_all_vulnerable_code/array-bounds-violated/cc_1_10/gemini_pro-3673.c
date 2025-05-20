//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1024

// Entry structure
typedef struct {
    char date[11];
    char time[9];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

// Global variables
Entry entries[MAX_ENTRIES];
int num_entries = 0;

// Function to display the main menu
void display_main_menu() {
    printf("\nWhat do you want to do?\n");
    printf("1. Add a new entry\n");
    printf("2. List all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Delete an entry\n");
    printf("5. Quit\n");
}

// Function to add a new entry
void add_new_entry() {
    // Get the current date and time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(entries[num_entries].date, sizeof(entries[num_entries].date), "%Y-%m-%d", tm);
    strftime(entries[num_entries].time, sizeof(entries[num_entries].time), "%H:%M:%S", tm);

    // Get the entry from the user
    printf("Enter your entry: ");
    fgets(entries[num_entries].entry, sizeof(entries[num_entries].entry), stdin);

    // Increment the number of entries
    num_entries++;
}

// Function to list all entries
void list_all_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n", entries[i].date, entries[i].time);
        printf("%s\n", entries[i].entry);
        printf("\n");
    }
}

// Function to search for an entry
void search_for_entry() {
    char search_term[MAX_ENTRY_LENGTH];

    // Get the search term from the user
    printf("Enter the search term: ");
    fgets(search_term, sizeof(search_term), stdin);

    // Search for the entry
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, search_term) != NULL) {
            printf("%s %s\n", entries[i].date, entries[i].time);
            printf("%s\n", entries[i].entry);
            printf("\n");
        }
    }
}

// Function to delete an entry
void delete_entry() {
    int entry_number;

    // Get the entry number from the user
    printf("Enter the entry number: ");
    scanf("%d", &entry_number);

    // Delete the entry
    for (int i = entry_number; i < num_entries; i++) {
        entries[i] = entries[i + 1];
    }

    // Decrement the number of entries
    num_entries--;
}

// Main function
int main() {
    int choice;

    // Display the main menu
    do {
        display_main_menu();

        // Get the user's choice
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                add_new_entry();
                break;
            case 2:
                list_all_entries();
                break;
            case 3:
                search_for_entry();
                break;
            case 4:
                delete_entry();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
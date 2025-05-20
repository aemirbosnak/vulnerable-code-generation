//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare the diary structure
typedef struct diary {
    char date[11];
    char time[9];
    char entry[1000];
} diary;

// Declare the diary array
diary diaries[100];

// Initialize the diary array
int diary_count = 0;

// Display the main menu
void main_menu() {
    printf("Welcome to your digital diary!\n");
    printf("1. Add a new entry\n");
    printf("2. View all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Delete an entry\n");
    printf("5. Exit\n");
    printf("Please enter your choice: ");
}

// Add a new entry to the diary array
void add_entry() {
    // Get the current date and time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(diaries[diary_count].date, sizeof(diaries[diary_count].date), "%Y-%m-%d", tm);
    strftime(diaries[diary_count].time, sizeof(diaries[diary_count].time), "%H:%M:%S", tm);

    // Get the entry from the user
    printf("Please enter your entry: ");
    fgets(diaries[diary_count].entry, sizeof(diaries[diary_count].entry), stdin);

    // Increment the diary count
    diary_count++;
}

// View all entries in the diary array
void view_entries() {
    // Check if the diary array is empty
    if (diary_count == 0) {
        printf("No entries to display.\n");
    } else {
        // Iterate over the diary array and print each entry
        for (int i = 0; i < diary_count; i++) {
            printf("Date: %s\n", diaries[i].date);
            printf("Time: %s\n", diaries[i].time);
            printf("Entry: %s\n\n", diaries[i].entry);
        }
    }
}

// Search for an entry in the diary array
void search_entry() {
    // Get the search term from the user
    char search_term[100];
    printf("Please enter the search term: ");
    fgets(search_term, sizeof(search_term), stdin);

    // Iterate over the diary array and search for the search term
    int found = 0;
    for (int i = 0; i < diary_count; i++) {
        if (strstr(diaries[i].entry, search_term) != NULL) {
            // Search term found
            printf("Date: %s\n", diaries[i].date);
            printf("Time: %s\n", diaries[i].time);
            printf("Entry: %s\n\n", diaries[i].entry);
            found = 1;
        }
    }

    // Check if the search term was not found
    if (!found) {
        printf("No entries found.\n");
    }
}

// Delete an entry from the diary array
void delete_entry() {
    // Get the entry number from the user
    int entry_number;
    printf("Please enter the entry number: ");
    scanf("%d", &entry_number);

    // Check if the entry number is valid
    if (entry_number < 1 || entry_number > diary_count) {
        printf("Invalid entry number.\n");
    } else {
        // Shift the entries after the deleted entry to the left
        for (int i = entry_number; i < diary_count; i++) {
            diaries[i - 1] = diaries[i];
        }

        // Decrement the diary count
        diary_count--;
    }
}

// Exit the program
void exit_program() {
    printf("Thank you for using your digital diary!\n");
    exit(0);
}

// Main function
int main() {
    // Display the main menu
    main_menu();

    // Get the user's choice
    int choice;
    scanf("%d", &choice);

    // Handle the user's choice
    switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            view_entries();
            break;
        case 3:
            search_entry();
            break;
        case 4:
            delete_entry();
            break;
        case 5:
            exit_program();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    // Return to the main menu
    main_menu();

    return 0;
}
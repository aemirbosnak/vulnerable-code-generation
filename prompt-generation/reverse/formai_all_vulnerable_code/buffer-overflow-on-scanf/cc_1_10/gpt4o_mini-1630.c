//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100  // Maximum number of diary entries
#define MAX_LENGTH 256   // Maximum length for a diary entry

typedef struct {
    char date[11];      // Date in format YYYY-MM-DD
    char entry[MAX_LENGTH]; // Diary entry text
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

// Function to add a new entry to the diary
void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }
    
    DiaryEntry new_entry;
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%10s", new_entry.date);
    getchar(); // Clear the newline character from input buffer
    printf("Enter your diary entry: ");
    fgets(new_entry.entry, MAX_LENGTH, stdin);
    new_entry.entry[strcspn(new_entry.entry, "\n")] = 0; // Remove trailing newline

    diary[entry_count++] = new_entry; // add new_entry to the diary
    printf("Entry added successfully!\n");
}

// Function to view all diary entries
void view_entries() {
    if (entry_count == 0) {
        printf("No entries found! Your diary is empty.\n");
    } else {
        printf("\n--- Your Diary Entries ---\n");
        for (int i = 0; i < entry_count; i++) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n", diary[i].entry);
            printf("------------------------------\n");
        }
    }
}

// Function to search for entries by date
void search_entry() {
    char search_date[11];
    printf("Enter the date to search (YYYY-MM-DD): ");
    scanf("%10s", search_date);

    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(diary[i].date, search_date) == 0) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n", diary[i].entry);
            printf("------------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found for the date: %s\n", search_date);
    }
}

// Function to display menu
void display_menu() {
    printf("\n----- Digital Diary Menu -----\n");
    printf("1. Add Diary Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entry by Date\n");
    printf("4. Exit\n");
    printf("------------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);
        
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
                printf("Exiting the diary. Thank you for using the Digital Diary! Bye!\n");
                break;
            default:
                printf("Invalid option! Please choose a valid menu item.\n");
        }
    } while (choice != 4);

    return 0;
}
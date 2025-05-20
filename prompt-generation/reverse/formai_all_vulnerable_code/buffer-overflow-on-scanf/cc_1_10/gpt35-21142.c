//FormAI DATASET v1.0 Category: Digital Diary ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_SIZE 500
#define MAX_ENTRIES 100

// Data structure to store diary entries
typedef struct {
    char date[20];
    char entry[MAX_ENTRY_SIZE];
} DiaryEntry;

// Function to get current date as a string
char* get_date_string() {
    time_t now = time(NULL);
    struct tm *time_info = localtime(&now);
    static char date_str[20];
    strftime(date_str, sizeof(date_str), "%d-%m-%Y", time_info);
    return date_str;
}

// Function to add a new entry to the diary
void add_entry(DiaryEntry entries[], int* num_entries) {
    // Get current date and time
    char* date_str = get_date_string();
    
    // Prompt user to enter diary entry
    printf("Enter your diary entry for %s: ", date_str);
    char entry[MAX_ENTRY_SIZE];
    fgets(entry, MAX_ENTRY_SIZE, stdin);

    // Create new diary entry and add to the list of entries
    DiaryEntry new_entry;
    strcpy(new_entry.date, date_str);
    strcpy(new_entry.entry, entry);

    entries[*num_entries] = new_entry;
    (*num_entries)++;

    // Confirm to user that entry has been added
    printf("Entry added successfully!\n\n");
}

// Function to print all diary entries
void print_entries(DiaryEntry entries[], int num_entries) {
    // Print header
    printf("\n--- ALL ENTRIES ---\n\n");

    // Loop through all entries and print each one
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n%s\n\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;

    // Loop to display menu and handle user input
    char choice;
    do {
        printf("DIARY MENU\n");
        printf("1. Add new entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        printf("\n");

        switch (choice) {
            case '1':
                add_entry(entries, &num_entries);
                break;
            case '2':
                print_entries(entries, num_entries);
                break;
            case '3':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    while (choice != '3');

    return 0;
}
//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: creative
// C Digital Diary Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define structure for diary entries
typedef struct {
    int day;
    int month;
    int year;
    char* entry;
} DiaryEntry;

// Function to print diary entry
void print_diary_entry(DiaryEntry* entry) {
    printf("Day: %d\nMonth: %d\nYear: %d\nEntry: %s\n", entry->day, entry->month, entry->year, entry->entry);
}

// Function to add diary entry
void add_diary_entry(DiaryEntry* entry) {
    // Get current date and time
    time_t current_time;
    time(&current_time);
    struct tm* current_date = localtime(&current_time);

    // Set diary entry fields
    entry->day = current_date->tm_mday;
    entry->month = current_date->tm_mon;
    entry->year = current_date->tm_year;

    // Get diary entry text
    char* entry_text = (char*)malloc(100 * sizeof(char));
    printf("Enter diary entry: ");
    fgets(entry_text, 100, stdin);
    entry->entry = entry_text;
}

// Function to delete diary entry
void delete_diary_entry(DiaryEntry* entry) {
    free(entry->entry);
    entry->entry = NULL;
}

// Function to print diary entries
void print_diary_entries(DiaryEntry* entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        print_diary_entry(&entries[i]);
    }
}

// Main function
int main() {
    // Create diary entries array
    DiaryEntry* entries = (DiaryEntry*)malloc(10 * sizeof(DiaryEntry));
    int num_entries = 0;

    // Loop until user exits
    while (1) {
        // Print menu
        printf("Menu:\n");
        printf("1. Add diary entry\n");
        printf("2. Delete diary entry\n");
        printf("3. Print diary entries\n");
        printf("4. Exit\n");

        // Get user input
        int choice;
        scanf("%d", &choice);

        // Perform action based on user input
        switch (choice) {
            case 1:
                add_diary_entry(&entries[num_entries]);
                num_entries++;
                break;
            case 2:
                delete_diary_entry(&entries[num_entries - 1]);
                num_entries--;
                break;
            case 3:
                print_diary_entries(entries, num_entries);
                break;
            case 4:
                free(entries);
                return 0;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
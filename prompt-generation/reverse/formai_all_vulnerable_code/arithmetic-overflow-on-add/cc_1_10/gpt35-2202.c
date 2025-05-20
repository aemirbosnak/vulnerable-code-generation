//FormAI DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A digital diary entry struct
typedef struct DiaryEntry {
    char date[11];  // Date of the entry in "MM/DD/YYYY" format
    char time[6];   // Time of the entry in "HH:MM" format
    char *title;    // A dynamic string for the title of the entry
    char *content;  // A dynamic string for the content of the entry
} DiaryEntry;

// Function for creating a new diary entry
DiaryEntry *new_entry() {
    DiaryEntry *entry = malloc(sizeof(DiaryEntry));
    
    // Get current date and time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(entry->date, "%02d/%02d/%d", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900);
    sprintf(entry->time, "%02d:%02d", tm.tm_hour, tm.tm_min);
    
    // Allocate memory for title and content
    entry->title = malloc(50 * sizeof(char));
    entry->content = malloc(1000 * sizeof(char));
    
    // Ask for user input for title and content
    printf("Enter a title for your entry:\n");
    fgets(entry->title, 50, stdin);
    printf("Enter the content of your entry:\n");
    fgets(entry->content, 1000, stdin);
    
    return entry;
}

// Main function for the digital diary program
int main() {
    DiaryEntry *entries = malloc(100 * sizeof(DiaryEntry));  // An array for storing up to 100 entries
    int num_entries = 0;  // Number of entries currently in the array
    int choice;
    
    do {
        printf("\nDIGITAL DIARY\n");
        printf("1. Create a new entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3):\n");
        scanf("%d", &choice);
        getchar();  // Consume the newline character left in the input stream
        
        switch (choice) {
            case 1:
                if (num_entries == 100) {
                    printf("Error: Maximum number of entries reached.\n");
                } else {
                    entries[num_entries] = *new_entry();
                    num_entries++;
                    printf("Entry created successfully.\n");
                }
                break;
            case 2:
                if (num_entries == 0) {
                    printf("There are no entries yet.\n");
                } else {
                    printf("All entries:\n");
                    for (int i = 0; i < num_entries; i++) {
                        printf("Entry #%d\n", i + 1);
                        printf("Date and time: %s %s\n", entries[i].date, entries[i].time);
                        printf("Title: %s", entries[i].title);
                        printf("Content: %s\n", entries[i].content);
                    }
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);
    
    // Free memory used by the entries and their title and content strings
    for (int i = 0; i < num_entries; i++) {
        free(entries[i].title);
        free(entries[i].content);
    }
    free(entries);
    
    return 0;
}
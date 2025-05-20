//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants and variables
#define DIARY_NAME "My Digital Diary"
#define MAX_ENTRIES 100
#define ENTRY_SIZE 256
#define DATE_FORMAT "%d-%m-%Y"

// Structure to store diary entries
typedef struct {
    char date[20];
    char entry[ENTRY_SIZE];
} diary_entry_t;

// Function to read and write diary entries
void read_diary(diary_entry_t *entries, int max_entries) {
    // Open the diary file in read-write mode
    FILE *diary_file = fopen(DIARY_NAME, "rw");
    
    // Check if the file exists and is readable
    if (!diary_file) {
        printf("Error: Diary file not found or not readable\n");
        return;
    }
    
    // Read the diary entries from the file
    for (int i = 0; i < max_entries; i++) {
        fscanf(diary_file, "%s %s", entries[i].date, entries[i].entry);
    }
    
    // Close the diary file
    fclose(diary_file);
}

// Function to add a new diary entry
void add_entry(diary_entry_t *entries, int max_entries) {
    // Get the current date and time
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    
    // Format the date and time for the diary entry
    char date[20];
    strftime(date, sizeof(date), DATE_FORMAT, current_time);
    
    // Allocate memory for the new diary entry
    diary_entry_t *new_entry = (diary_entry_t *)malloc(sizeof(diary_entry_t));
    
    // Set the date and entry for the new diary entry
    strcpy(new_entry->date, date);
    gets(new_entry->entry);
    
    // Add the new diary entry to the array
    int index = 0;
    for (int i = 0; i < max_entries; i++) {
        if (strcmp(entries[i].date, new_entry->date) < 0) {
            index = i;
            break;
        }
    }
    memmove(&entries[index + 1], &entries[index], (max_entries - index) * sizeof(diary_entry_t));
    entries[index] = *new_entry;
    
    // Increment the number of entries
    max_entries++;
}

// Function to print the diary entries
void print_diary(diary_entry_t *entries, int max_entries) {
    for (int i = 0; i < max_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    // Create an array to store the diary entries
    diary_entry_t entries[MAX_ENTRIES];
    
    // Read the diary entries from the file
    read_diary(entries, MAX_ENTRIES);
    
    // Add a new diary entry
    add_entry(entries, MAX_ENTRIES);
    
    // Print the diary entries
    print_diary(entries, MAX_ENTRIES);
    
    return 0;
}
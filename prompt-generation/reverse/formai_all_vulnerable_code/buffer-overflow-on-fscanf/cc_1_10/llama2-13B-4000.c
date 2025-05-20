//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of entries
#define MAX_ENTRIES 100

// Define the structure for each entry
typedef struct {
    char date[20];  // Date in the format "dd-mm-yyyy"
    char entry[100]; // Entry text
} entry_t;

// Define an array to store all the entries
entry_t entries[MAX_ENTRIES];

// Function to read and write to the diary file
void read_diary(void) {
    // Open the diary file in read mode
    FILE *file = fopen("diary.txt", "r");

    // Check if the file is empty
    if (feof(file)) {
        // If the file is empty, create a new entry
        entries[0].date[0] = '\0';
        entries[0].entry[0] = '\0';
    } else {
        // Read the first entry from the file
        fscanf(file, "%s %s", entries[0].date, entries[0].entry);
    }

    // Close the file
    fclose(file);
}

// Function to write to the diary file
void write_diary(void) {
    // Open the diary file in write mode
    FILE *file = fopen("diary.txt", "w");

    // Write the current entry to the file
    fprintf(file, "%s %s\n", entries[0].date, entries[0].entry);

    // Close the file
    fclose(file);
}

// Function to add a new entry
void add_entry(void) {
    // Get the current date and time
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    strftime(entries[0].date, sizeof(entries[0].date), "%d-%m-%Y", current_time);

    // Get the entry text from the user
    printf("What's your entry for today? ");
    scanf("%99s", entries[0].entry);

    // Add the entry to the array
    entries[0] = (entry_t) {
        .date = entries[0].date,
        .entry = entries[0].entry
    };

    // Write the entry to the diary file
    write_diary();
}

int main(void) {
    // Read the diary file on startup
    read_diary();

    // Display the current entry
    printf("Today's entry: %s\n", entries[0].entry);

    // Ask the user if they want to add a new entry
    printf("Do you want to add a new entry? (y/n): ");
    char answer = getchar();

    // If the user wants to add a new entry, add it and display it
    if (answer == 'y' || answer == 'Y') {
        add_entry();
        printf("Today's entry: %s\n", entries[0].entry);
    }

    return 0;
}
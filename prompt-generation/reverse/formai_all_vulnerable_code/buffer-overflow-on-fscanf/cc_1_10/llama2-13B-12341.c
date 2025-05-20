//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants and variables
#define DIARY_SIZE 500
#define DAY_SIZE 30
#define MAX_ENTRIES 30
#define ENTRY_SIZE 200

// Structure to store diary entries
typedef struct {
    char date[DAY_SIZE];
    char entry[ENTRY_SIZE];
} diary_entry_t;

// Array to store diary entries
diary_entry_t diary[MAX_ENTRIES];

// Function to read and write diary entries
void read_diary() {
    // Open diary file in read mode
    FILE *diary_file = fopen("diary.txt", "r");

    // Check if file is empty
    if (feof(diary_file)) {
        // If file is empty, create a new entry
        diary[0].date[0] = '\0';
        diary[0].entry[0] = '\0';
    } else {
        // Read existing entries
        fscanf(diary_file, "%s %s", diary[0].date, diary[0].entry);
    }

    // Close diary file
    fclose(diary_file);
}

void write_diary() {
    // Open diary file in write mode
    FILE *diary_file = fopen("diary.txt", "w");

    // Write current entry
    fprintf(diary_file, "%s %s\n", diary[0].date, diary[0].entry);

    // Close diary file
    fclose(diary_file);
}

// Function to add a new entry
void add_entry() {
    // Check if diary is full
    if (++diary[MAX_ENTRIES - 1].date[0] == '\0') {
        // If diary is full, clear oldest entry
        for (int i = 0; i < MAX_ENTRIES - 1; i++) {
            diary[i].date[0] = '\0';
            diary[i].entry[0] = '\0';
        }
    }

    // Get current date and entry
    getdate(&diary[MAX_ENTRIES - 1].date);
    gets(diary[MAX_ENTRIES - 1].entry);

    // Add new entry to diary
    diary[MAX_ENTRIES - 1].date[0] = '\0';
    diary[MAX_ENTRIES - 1].entry[0] = '\0';
}

// Function to display diary entries
void display_diary() {
    for (int i = 0; i < MAX_ENTRIES; i++) {
        printf("%s %s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    // Read diary on startup
    read_diary();

    // Display diary entries
    display_diary();

    // Add new entry
    add_entry();

    // Display diary entries again
    display_diary();

    return 0;
}
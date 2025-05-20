//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: thoughtful
/*
 * A Digital Diary Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

// Struct to store a single entry
typedef struct {
    char title[100];
    char content[1000];
    time_t date;
} entry;

// Array to store all entries
entry entries[MAX_ENTRIES];

// Function to add a new entry
void add_entry(char* title, char* content) {
    // Get the current time
    time_t current_time = time(NULL);

    // Get the current date
    struct tm* current_date = localtime(&current_time);

    // Get the current month, day, and year
    int month = current_date->tm_mon + 1;
    int day = current_date->tm_mday;
    int year = current_date->tm_year + 1900;

    // Format the date
    char date[100];
    sprintf(date, "%d-%d-%d", month, day, year);

    // Add the entry to the array
    strcpy(entries[MAX_ENTRIES - 1].title, title);
    strcpy(entries[MAX_ENTRIES - 1].content, content);
    entries[MAX_ENTRIES - 1].date = current_time;

    // Print a confirmation message
    printf("Entry added successfully!\n");
}

// Function to display all entries
void display_entries() {
    // Iterate through all entries
    for (int i = 0; i < MAX_ENTRIES; i++) {
        // Check if the entry is empty
        if (entries[i].title[0] == '\0' && entries[i].content[0] == '\0') {
            break;
        }

        // Get the current date
        struct tm* current_date = localtime(&entries[i].date);

        // Get the current month, day, and year
        int month = current_date->tm_mon + 1;
        int day = current_date->tm_mday;
        int year = current_date->tm_year + 1900;

        // Format the date
        char date[100];
        sprintf(date, "%d-%d-%d", month, day, year);

        // Display the entry
        printf("%s: %s\n", date, entries[i].title);
        printf("%s\n", entries[i].content);
        printf("\n");
    }
}

// Function to search for an entry by title
void search_entry(char* title) {
    // Iterate through all entries
    for (int i = 0; i < MAX_ENTRIES; i++) {
        // Check if the entry is empty
        if (entries[i].title[0] == '\0' && entries[i].content[0] == '\0') {
            break;
        }

        // Check if the title matches
        if (strcmp(entries[i].title, title) == 0) {
            // Get the current date
            struct tm* current_date = localtime(&entries[i].date);

            // Get the current month, day, and year
            int month = current_date->tm_mon + 1;
            int day = current_date->tm_mday;
            int year = current_date->tm_year + 1900;

            // Format the date
            char date[100];
            sprintf(date, "%d-%d-%d", month, day, year);

            // Display the entry
            printf("%s: %s\n", date, entries[i].title);
            printf("%s\n", entries[i].content);
            printf("\n");
            return;
        }
    }

    // If the entry is not found, display a message
    printf("Entry not found.\n");
}

int main() {
    // Add a few sample entries
    add_entry("Hello, world!", "This is my first entry.");
    add_entry("Goodbye, world!", "This is my last entry.");

    // Display all entries
    display_entries();

    // Search for an entry by title
    search_entry("Goodbye, world!");

    return 0;
}
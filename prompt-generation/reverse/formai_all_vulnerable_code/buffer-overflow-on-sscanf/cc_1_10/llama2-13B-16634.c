//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure for storing diary entries
struct diary_entry {
    int day;
    int month;
    int year;
    char entry[100];
};

// Define a function to read and store diary entries
void read_diary(struct diary_entry *entries, int max_entries) {
    int i = 0;
    char line[100];

    while (fgets(line, 100, stdin) != NULL) {
        // Parse the line into day, month, and year
        sscanf(line, "%d-%d-%d", &entries[i].day, &entries[i].month, &entries[i].year);
        // Store the entry in the struct
        strcpy(entries[i].entry, line);
        i++;

        // Check if we've reached the maximum number of entries
        if (i >= max_entries) {
            break;
        }
    }
}

// Define a function to print the diary entries
void print_diary(struct diary_entry entries[], int num_entries) {
    int i = 0;

    while (i < num_entries) {
        printf("%d-%d-%d: %s\n", entries[i].day, entries[i].month, entries[i].year, entries[i].entry);
        i++;
    }
}

int main() {
    // Define the maximum number of diary entries
    int max_entries = 10;

    // Create an array of diary entries
    struct diary_entry entries[max_entries];

    // Read and store diary entries
    read_diary(entries, max_entries);

    // Print the diary entries
    print_diary(entries, max_entries);

    return 0;
}
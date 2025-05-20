//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

// Struct to store an entry
typedef struct {
    char date[11];
    char time[9];
    char entry[500];
} entry_t;

// Function to compare two entries based on their dates
int compare_entries(const void *a, const void *b) {
    entry_t *entry1 = (entry_t *)a;
    entry_t *entry2 = (entry_t *)b;

    // Compare the dates in YYYY-MM-DD format
    return strcmp(entry1->date, entry2->date);
}

// Function to write an entry to a file
void write_entry(FILE *file, const entry_t *entry) {
    fprintf(file, "%s %s: %s\n", entry->date, entry->time, entry->entry);
}

// Function to read an entry from a file
entry_t read_entry(FILE *file) {
    entry_t entry;
    fscanf(file, "%s %s: %[^\n]", entry.date, entry.time, entry.entry);
    return entry;
}

// Function to sort the entries array
void sort_entries(entry_t entries[], int num_entries) {
    qsort(entries, num_entries, sizeof(entry_t), compare_entries);
}

int main() {
    FILE *diary_file;
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[50] = "diary.txt";

    // Open the diary file
    diary_file = fopen(filename, "a+");
    if (diary_file == NULL) {
        printf("Error: could not open diary file.\n");
        return 1;
    }

    // Read the existing entries from the file
    rewind(diary_file);
    while (fscanf(diary_file, "%s %s: %[^\n]", entries[num_entries].date, entries[num_entries].time, entries[num_entries].entry)!= EOF) {
        num_entries++;
    }

    // Sort the entries by date
    sort_entries(entries, num_entries);

    // Print the sorted entries
    printf("Sorted diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        write_entry(stdout, &entries[i]);
    }

    // Close the diary file
    fclose(diary_file);

    return 0;
}
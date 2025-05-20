//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_FILE "digital_diary.txt"

// Structure to store diary entries
typedef struct {
    char date[20];
    char entry[100];
} diary_entry_t;

// Function to write diary entries to file
void write_diary(diary_entry_t *entries, int num_entries) {
    FILE *file = fopen(DIARY_FILE, "w");
    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%s - %s\n", entries[i].date, entries[i].entry);
    }
    fclose(file);
}

// Function to read diary entries from file
diary_entry_t *read_diary(int *num_entries) {
    FILE *file = fopen(DIARY_FILE, "r");
    diary_entry_t *entries = calloc(1, sizeof(diary_entry_t) * *num_entries);
    int i = 0;
    while (fscanf(file, "%19s %99s\n", entries[i].date, entries[i].entry) == 2) {
        i++;
    }
    fclose(file);
    *num_entries = i;
    return entries;
}

// Function to add a new diary entry
void add_entry(diary_entry_t *entries, char *date, char *entry) {
    diary_entry_t new_entry;
    strcpy(new_entry.date, date);
    strcpy(new_entry.entry, entry);
    int num_entries = 0;
    entries = realloc(entries, (num_entries + 1) * sizeof(diary_entry_t));
    memcpy(&entries[num_entries], &new_entry, sizeof(diary_entry_t));
    num_entries++;
}

// Function to display diary entries
void display_diary(diary_entry_t *entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    diary_entry_t *entries = NULL;
    int num_entries = 0;

    // Read diary entries from file
    entries = read_diary(&num_entries);

    // Add a new diary entry
    add_entry(entries, "Today", "Went to the park and played fetch with my dog.");

    // Display diary entries
    display_diary(entries, num_entries);

    // Write diary entries to file
    write_diary(entries, num_entries);

    return 0;
}
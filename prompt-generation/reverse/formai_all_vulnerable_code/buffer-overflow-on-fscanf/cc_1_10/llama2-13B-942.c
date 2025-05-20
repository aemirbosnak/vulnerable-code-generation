//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DIARY_ENTRY_SIZE 1024
#define DIARY_FILENAME "digital_diary.dat"

// Structure to hold a diary entry
typedef struct {
    int day;
    int month;
    int year;
    char entry[DIARY_ENTRY_SIZE];
} diary_entry_t;

// Function to read and write diary entries
void read_diary(diary_entry_t *entries, int num_entries) {
    FILE *file = fopen(DIARY_FILENAME, "r");
    if (file == NULL) {
        printf("Error: Could not open diary file %s\n", DIARY_FILENAME);
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        fscanf(file, "%d%d%d%s", &entries[i].day, &entries[i].month, &entries[i].year, entries[i].entry);
    }

    fclose(file);
}

void write_diary(diary_entry_t *entries, int num_entries) {
    FILE *file = fopen(DIARY_FILENAME, "w");
    if (file == NULL) {
        printf("Error: Could not open diary file %s\n", DIARY_FILENAME);
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%d%d%d%s", entries[i].day, entries[i].month, entries[i].year, entries[i].entry);
    }

    fclose(file);
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // Create an array of diary entries
    diary_entry_t entries[10];

    // Read the diary entries from the file
    read_diary(entries, 10);

    // Add a new entry to the diary
    int day = rand() % 31 + 1;
    int month = rand() % 12 + 1;
    int year = rand() % 100 + 2000;
    char entry[DIARY_ENTRY_SIZE];
    snprintf(entry, DIARY_ENTRY_SIZE, "Today I woke up feeling %s", (rand() % 2) ? "happy" : "grumpy");

    // Add the new entry to the array
    entries[9].day = day;
    entries[9].month = month;
    entries[9].year = year;
    strcpy(entries[9].entry, entry);

    // Write the diary entries back to the file
    write_diary(entries, 10);

    return 0;
}
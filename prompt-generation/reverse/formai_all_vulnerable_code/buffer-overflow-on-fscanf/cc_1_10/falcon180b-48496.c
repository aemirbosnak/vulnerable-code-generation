//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define maximum length of diary entry
#define MAX_LENGTH 500

// Define structure for diary entry
typedef struct {
    time_t timestamp;
    char entry[MAX_LENGTH];
} DiaryEntry;

// Function to write diary entry to file
void write_entry(FILE *diary_file, DiaryEntry entry) {
    fprintf(diary_file, "%s - %s\n", ctime(&entry.timestamp), entry.entry);
}

// Function to read diary entries from file
void read_entries(FILE *diary_file, DiaryEntry *entries, int num_entries) {
    rewind(diary_file);
    for (int i = 0; i < num_entries; i++) {
        fscanf(diary_file, "%s - %[^\n]", &entries[i].timestamp, entries[i].entry);
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Open diary file
    FILE *diary_file = fopen("diary.txt", "a+");
    if (diary_file == NULL) {
        printf("Error: Could not open diary file.\n");
        return 1;
    }

    // Initialize diary entries
    DiaryEntry entries[10];
    for (int i = 0; i < 10; i++) {
        entries[i].timestamp = time(NULL);
        sprintf(entries[i].entry, "Entry %d", i + 1);
        write_entry(diary_file, entries[i]);
    }

    // Read diary entries
    read_entries(diary_file, entries, 10);

    // Print diary entries
    for (int i = 0; i < 10; i++) {
        printf("%s - %s\n", ctime(&entries[i].timestamp), entries[i].entry);
    }

    // Close diary file
    fclose(diary_file);

    return 0;
}
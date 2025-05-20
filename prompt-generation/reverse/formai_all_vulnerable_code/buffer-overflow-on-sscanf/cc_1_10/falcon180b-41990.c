//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary;
    char filename[100];
    int numEntries = 0;
    Entry entries[MAX_ENTRIES];
    time_t currentTime;

    // Get the current date and time
    time(&currentTime);

    // Prompt the user for the filename
    printf("Enter the filename for your diary: ");
    scanf("%s", filename);

    // Open the diary file
    diary = fopen(filename, "a+");

    // Check if the diary file exists
    if (diary == NULL) {
        printf("Diary file not found. Creating new file.\n");

        // Create a new diary file
        diary = fopen(filename, "w");

        // Write the header to the diary file
        fprintf(diary, "Diary of %s\n", getlogin());
        fprintf(diary, "Entries:\n");

        // Initialize the entries array with empty entries
        for (int i = 0; i < MAX_ENTRIES; i++) {
            entries[i].timestamp = 0;
            strcpy(entries[i].entry, "");
        }
    } else {
        // Read the entries from the diary file
        rewind(diary);
        while (fgets(filename, sizeof(filename), diary)!= NULL) {
            if (sscanf(filename, "%s %lu", entries[numEntries].entry, &entries[numEntries].timestamp) == 2) {
                numEntries++;
            } else {
                break;
            }
        }

        // Initialize the remaining entries with empty entries
        for (int i = numEntries; i < MAX_ENTRIES; i++) {
            entries[i].timestamp = 0;
            strcpy(entries[i].entry, "");
        }
    }

    // Prompt the user for a new entry
    printf("Enter your entry: ");
    fgets(entries[numEntries].entry, MAX_ENTRY_LENGTH, stdin);

    // Get the current date and time
    time(&currentTime);

    // Add the new entry to the diary
    entries[numEntries].timestamp = currentTime;
    numEntries++;

    // Write the new entry to the diary file
    fprintf(diary, "%s %lu\n", entries[numEntries-1].entry, entries[numEntries-1].timestamp);

    // Close the diary file
    fclose(diary);

    // Print the diary entries
    printf("Diary of %s\n", getlogin());
    printf("Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s %s\n", ctime(&entries[i].timestamp), entries[i].entry);
    }

    return 0;
}
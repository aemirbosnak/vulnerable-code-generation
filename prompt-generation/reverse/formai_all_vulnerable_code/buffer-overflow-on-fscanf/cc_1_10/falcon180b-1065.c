//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

// Struct to store each diary entry
typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Function to print the diary entries
void printEntries(DiaryEntry entries[], int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

// Function to write a diary entry to a file
void writeEntry(FILE *file, DiaryEntry entry) {
    fprintf(file, "%s: %s\n", entry.date, entry.entry);
}

// Function to read diary entries from a file
int readEntries(FILE *file, DiaryEntry entries[]) {
    int numEntries = 0;
    while (fscanf(file, "%s: %s\n", entries[numEntries].date, entries[numEntries].entry)!= EOF) {
        numEntries++;
        if (numEntries >= MAX_ENTRIES) {
            break;
        }
    }
    return numEntries;
}

int main() {
    // Initialize the diary entries
    DiaryEntry entries[MAX_ENTRIES];
    memset(entries, 0, sizeof(entries));

    // Open the diary file
    FILE *file = fopen("diary.txt", "a+");
    if (file == NULL) {
        printf("Error: Could not open diary file.\n");
        return 1;
    }

    // Read the existing diary entries from the file
    int numEntries = readEntries(file, entries);

    // Print the existing diary entries
    printf("Existing diary entries:\n");
    printEntries(entries, numEntries);

    // Prompt the user to write a new diary entry
    printf("Enter a new diary entry:\n");
    scanf("%s", entries[numEntries].entry);
    strcpy(entries[numEntries].date, "Today");

    // Write the new diary entry to the file
    writeEntry(file, entries[numEntries]);

    // Print the updated diary entries
    printf("Updated diary entries:\n");
    printEntries(entries, numEntries + 1);

    // Close the diary file
    fclose(file);

    return 0;
}
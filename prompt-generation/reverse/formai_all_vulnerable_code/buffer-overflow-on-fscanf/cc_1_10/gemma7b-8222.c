//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of days in the month
#define NUM_DAYS 31

// Define the maximum number of entries per day
#define MAX_ENTRIES 10

// Define the structure of an entry
typedef struct Entry {
    char name[50];
    int date;
    int hour;
    int minute;
    char text[1000];
} Entry;

// Define the function to read entries from a file
void readEntries(Entry *entries, int *numEntries) {
    FILE *file = fopen("entries.txt", "r");
    if (file) {
        int i = 0;
        entries = malloc(NUM_DAYS * MAX_ENTRIES * sizeof(Entry));
        *numEntries = 0;
        while (fscanf(file, "%s %d %d %d %[^\n]", entries[*numEntries].name, &entries[*numEntries].date, &entries[*numEntries].hour, &entries[*numEntries].minute, entries[*numEntries].text) != EOF) {
            (*numEntries)++;
            i++;
        }
        fclose(file);
    }
}

// Define the function to write entries to a file
void writeEntries(Entry *entries, int numEntries) {
    FILE *file = fopen("entries.txt", "w");
    if (file) {
        for (int i = 0; i < numEntries; i++) {
            fprintf(file, "%s %d %d %d %s\n", entries[i].name, entries[i].date, entries[i].hour, entries[i].minute, entries[i].text);
        }
        fclose(file);
    }
}

// Define the function to calculate statistics
void calculateStatistics(Entry *entries, int numEntries) {
    int totalTime = 0;
    for (int i = 0; i < numEntries; i++) {
        int hours = entries[i].hour;
        int minutes = entries[i].minute;
        totalTime += hours * 60 + minutes;
    }
    printf("Total time spent: %d hours", totalTime / 60);
    printf(", %d minutes", totalTime % 60);
}

int main() {
    Entry *entries = NULL;
    int numEntries = 0;

    readEntries(entries, &numEntries);
    writeEntries(entries, numEntries);
    calculateStatistics(entries, numEntries);

    return 0;
}
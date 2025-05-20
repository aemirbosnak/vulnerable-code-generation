//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000 // Maximum number of diary entries
#define MAX_ENTRY_LENGTH 500 // Maximum length of each diary entry

typedef struct {
    char date[20]; // Date of the entry
    char entry[MAX_ENTRY_LENGTH]; // Entry content
} DiaryEntry;

void addEntry(DiaryEntry* entries, int numEntries, char* date, char* entry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[numEntries].date, date);
    strcpy(entries[numEntries].entry, entry);
    numEntries++;
}

void deleteEntry(DiaryEntry* entries, int numEntries, char* date) {
    int i;

    for (i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            memmove(&entries[i], &entries[i+1], sizeof(DiaryEntry) * (numEntries - i - 1));
            numEntries--;
            break;
        }
    }
}

void viewEntries(DiaryEntry* entries, int numEntries) {
    int i;

    for (i = 0; i < numEntries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;

    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter entry:\n");
        fgets(entry, MAX_ENTRY_LENGTH, stdin);
        entry[strcspn(entry, "\n")] = '\0'; // Remove newline character

        addEntry(entries, numEntries, date, entry);

        printf("Do you want to view your entries? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y') {
            viewEntries(entries, numEntries);
        }
    }

    return 0;
}
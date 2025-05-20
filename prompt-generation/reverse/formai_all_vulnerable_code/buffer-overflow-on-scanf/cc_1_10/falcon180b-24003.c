//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry(char* newEntry) {
    if (entryCount >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        return;
    }

    time_t currentTime = time(NULL);
    strncpy(entries[entryCount].entry, newEntry, MAX_ENTRY_LENGTH-1);
    entries[entryCount].entry[MAX_ENTRY_LENGTH-1] = '\0';
    entries[entryCount].timestamp = currentTime;

    entryCount++;
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("%s (%ld)\n", entries[i].entry, entries[i].timestamp);
    }
}

void searchEntries(char* searchTerm) {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        if (strstr(entries[i].entry, searchTerm)!= NULL) {
            printf("%s (%ld)\n", entries[i].entry, entries[i].timestamp);
        }
    }
}

int main() {
    srand(time(NULL));

    int choice;
    char newEntry[MAX_ENTRY_LENGTH];

    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your new entry (maximum %d characters): ", MAX_ENTRY_LENGTH-1);
                scanf("%[^\n]", newEntry);
                addEntry(newEntry);
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                printf("Enter your search term: ");
                scanf("%s", newEntry);
                searchEntries(newEntry);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char* newEntry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Max entries reached, cannot add more.\n");
        return;
    }
    time_t now = time(NULL);
    struct tm* timeInfo = localtime(&now);
    char timestamp[26];
    strftime(timestamp, 26, "%Y-%m-%d %H:%M:%S", timeInfo);
    strcat(newEntry, " ");
    strcat(newEntry, timestamp);
    entries[numEntries] = (Entry) {
       .timestamp = now,
       .entry = newEntry
    };
    numEntries++;
}

void viewEntries() {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }
    for (int i = 0; i < numEntries; i++) {
        printf("%s\n", entries[i].entry);
    }
}

void searchEntries(char* keyword) {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }
    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s\n", entries[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));
    char* entriesArray[MAX_ENTRIES];
    for (int i = 0; i < 10; i++) {
        char* newEntry = (char*) malloc(sizeof(char) * (rand() % MAX_ENTRY_LENGTH + 1));
        sprintf(newEntry, "Entry %d", i+1);
        addEntry(newEntry);
        entriesArray[i] = newEntry;
    }
    viewEntries();
    char* keyword = "Entry";
    searchEntries(keyword);
    for (int i = 0; i < 10; i++) {
        free(entriesArray[i]);
    }
    return 0;
}
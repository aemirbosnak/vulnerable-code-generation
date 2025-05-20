//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char entry[200];
} DiaryEntry;

void addEntry(DiaryEntry* diary, int numEntries, char* date, char* entry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }

    strcpy(diary[numEntries].date, date);
    strcpy(diary[numEntries].entry, entry);

    numEntries++;
}

void viewEntry(DiaryEntry* diary, int numEntries, int entryNum) {
    if (entryNum >= numEntries) {
        printf("Entry not found.\n");
        return;
    }

    printf("Date: %s\n", diary[entryNum].date);
    printf("Entry: %s\n", diary[entryNum].entry);
}

void deleteEntry(DiaryEntry* diary, int* numEntries, int entryNum) {
    if (entryNum >= *numEntries) {
        printf("Entry not found.\n");
        return;
    }

    for (int i = entryNum; i < *numEntries - 1; i++) {
        diary[i] = diary[i + 1];
    }

    (*numEntries)--;
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int numEntries = 0;

    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char date[20];
    strftime(date, 20, "%Y-%m-%d", t);

    addEntry(diary, numEntries, date, "First entry.");
    addEntry(diary, numEntries, date, "Second entry.");
    addEntry(diary, numEntries, date, "Third entry.");

    viewEntry(diary, numEntries, 0);
    viewEntry(diary, numEntries, 1);
    viewEntry(diary, numEntries, 2);

    deleteEntry(diary, &numEntries, 1);

    viewEntry(diary, numEntries, 0);
    viewEntry(diary, numEntries, 1);

    return 0;
}
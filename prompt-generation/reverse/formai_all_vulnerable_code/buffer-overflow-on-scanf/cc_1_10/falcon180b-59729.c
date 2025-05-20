//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

void addEntry(DiaryEntry* diary, int numEntries, char* newEntry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add new entry.\n");
        return;
    }

    strcpy(diary[numEntries].entry, newEntry);
    diary[numEntries].timestamp = time(NULL);
    numEntries++;
}

void viewEntries(DiaryEntry* diary, int numEntries) {
    printf("Diary Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", ctime(&diary[i].timestamp), diary[i].entry);
    }
}

void searchEntry(DiaryEntry* diary, int numEntries, char* searchTerm) {
    for (int i = 0; i < numEntries; i++) {
        if (strstr(diary[i].entry, searchTerm)!= NULL) {
            printf("%s - %s\n", ctime(&diary[i].timestamp), diary[i].entry);
        }
    }
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int numEntries = 0;

    addEntry(diary, numEntries, "Dear Diary, today I wrote my first C program!");
    addEntry(diary, numEntries, "I am excited to learn more about programming.");

    viewEntries(diary, numEntries);

    char searchTerm[MAX_ENTRY_LENGTH];
    printf("Enter a search term: ");
    scanf("%s", searchTerm);
    searchEntry(diary, numEntries, searchTerm);

    return 0;
}
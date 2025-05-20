//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char entry[1000];
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int numEntries;
} Diary;

void addEntry(Diary *diary, const char *date, const char *entry) {
    if (diary->numEntries >= MAX_ENTRIES) {
        fprintf(stderr, "Diary is full\n");
        return;
    }

    Entry newEntry;
    strncpy(newEntry.date, date, sizeof(newEntry.date));
    strncpy(newEntry.entry, entry, sizeof(newEntry.entry));

    diary->entries[diary->numEntries] = newEntry;
    diary->numEntries++;
}

void deleteEntry(Diary *diary, int index) {
    if (index < 0 || index >= diary->numEntries) {
        fprintf(stderr, "Invalid entry index\n");
        return;
    }

    memmove(diary->entries + index, diary->entries + (index + 1), sizeof(Entry) * (diary->numEntries - index - 1));
    diary->numEntries--;
}

void printDiary(Diary diary) {
    for (int i = 0; i < diary.numEntries; i++) {
        printf("%s: %s\n", diary.entries[i].date, diary.entries[i].entry);
    }
}

int main() {
    srand(time(NULL));

    Diary diary;
    diary.numEntries = 0;

    Entry entry;
    char date[20];
    char entryStr[1000];

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date);
    printf("Enter entry: ");
    fgets(entryStr, sizeof(entryStr), stdin);
    strcpy(entry.date, date);
    strcpy(entry.entry, entryStr);

    addEntry(&diary, date, entryStr);
    printDiary(diary);

    char delDate[20];
    printf("Delete entry? (Y/n): ");
    scanf("%s", delDate);
    if (tolower(delDate[0]) == 'y') {
        int index;
        printf("Enter index: ");
        scanf("%d", &index);
        deleteEntry(&diary, index);
        printDiary(diary);
    }

    return 0;
}
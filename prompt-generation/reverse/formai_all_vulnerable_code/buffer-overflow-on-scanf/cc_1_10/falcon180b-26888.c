//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int numEntries;
} Diary;

void createDiary(Diary* diary) {
    diary->numEntries = 0;
}

void addEntry(Diary* diary, char* date, char* entry) {
    if (diary->numEntries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    strncpy(diary->entries[diary->numEntries].date, date, 20);
    strncpy(diary->entries[diary->numEntries].entry, entry, MAX_ENTRY_LENGTH);

    diary->numEntries++;
}

void viewEntries(Diary* diary) {
    if (diary->numEntries == 0) {
        printf("Diary is empty!\n");
        return;
    }

    printf("Entries:\n");
    for (int i = 0; i < diary->numEntries; i++) {
        printf("%s - %s\n", diary->entries[i].date, diary->entries[i].entry);
    }
}

void searchEntry(Diary* diary, char* date) {
    for (int i = 0; i < diary->numEntries; i++) {
        if (strcmp(diary->entries[i].date, date) == 0) {
            printf("%s - %s\n", diary->entries[i].date, diary->entries[i].entry);
            return;
        }
    }

    printf("Entry not found!\n");
}

int main() {
    Diary diary;
    createDiary(&diary);

    char date[20];
    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);

        if (strcmp(date, "exit") == 0) {
            break;
        }

        char entry[MAX_ENTRY_LENGTH];
        printf("Enter entry:\n");
        if (fgets(entry, MAX_ENTRY_LENGTH, stdin) == NULL) {
            printf("Error reading entry!\n");
            continue;
        }

        entry[strcspn(entry, "\n")] = '\0';

        addEntry(&diary, date, entry);
    }

    return 0;
}
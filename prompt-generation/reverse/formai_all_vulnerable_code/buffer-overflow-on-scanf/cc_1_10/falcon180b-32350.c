//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

void addEntry(DiaryEntry* diary, int entryCount, char* date, char* entry) {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    strcpy(diary[entryCount].date, date);
    strcpy(diary[entryCount].entry, entry);

    entryCount++;
}

void displayEntry(DiaryEntry* diary, int entryCount, int index) {
    if (index >= entryCount) {
        printf("No entry found.\n");
        return;
    }

    printf("Date: %s\n", diary[index].date);
    printf("Entry:\n%s\n", diary[index].entry);
}

void displayAllEntries(DiaryEntry* diary, int entryCount) {
    int i;

    for (i = 0; i < entryCount; i++) {
        displayEntry(diary, entryCount, i);
    }
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int entryCount = 0;
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    srand(time(NULL));

    while (1) {
        printf("1. Add entry\n2. Display all entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", date);

            printf("Enter entry:\n");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            entry[strcspn(entry, "\n")] = '\0';

            addEntry(diary, entryCount, date, entry);
            break;

        case 2:
            displayAllEntries(diary, entryCount);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
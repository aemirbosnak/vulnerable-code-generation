//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char entry[MAX_ENTRY_LENGTH];
    time_t timestamp;
} DiaryEntry;

void addEntry(DiaryEntry* diary, int numEntries, const char* entry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }
    strcpy(diary[numEntries].entry, entry);
    diary[numEntries].timestamp = time(NULL);
    numEntries++;
}

void printEntries(DiaryEntry* diary, int numEntries) {
    printf("Diary entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\n", diary[i].entry);
        printf("Timestamp: %s\n\n", ctime(&diary[i].timestamp));
    }
}

void deleteEntry(DiaryEntry* diary, int numEntries) {
    printf("Enter entry number to delete: ");
    int entryNum;
    scanf("%d", &entryNum);
    if (entryNum < 0 || entryNum >= numEntries) {
        printf("Invalid entry number.\n");
        return;
    }
    for (int i = entryNum; i < numEntries - 1; i++) {
        strcpy(diary[i].entry, diary[i + 1].entry);
        diary[i].timestamp = diary[i + 1].timestamp;
    }
    numEntries--;
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int numEntries = 0;
    char choice;
    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. Print entries\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter entry: ");
                char entry[MAX_ENTRY_LENGTH];
                scanf("%[^\n]", entry);
                addEntry(diary, numEntries, entry);
                break;
            case '2':
                printEntries(diary, numEntries);
                break;
            case '3':
                deleteEntry(diary, numEntries);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');
    return 0;
}
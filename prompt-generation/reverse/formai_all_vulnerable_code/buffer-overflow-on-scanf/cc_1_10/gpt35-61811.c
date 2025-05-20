//FormAI DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 1000

struct DiaryEntry {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
    struct DiaryEntry *next;
};

typedef struct DiaryEntry DiaryEntry;

DiaryEntry *diaryHead = NULL;

void displayMenu() {
    printf("\n\nDigital Diary Menu:\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Exit\n\n");
}

void addEntry() {
    char entry[MAX_ENTRY_LENGTH];
    time_t timestamp = time(NULL);

    printf("Enter your diary entry here:\n");
    fgets(entry, MAX_ENTRY_LENGTH, stdin);

    DiaryEntry *newEntry = (DiaryEntry *) malloc(sizeof(DiaryEntry));
    newEntry->timestamp = timestamp;
    strcpy(newEntry->entry, entry);
    newEntry->next = diaryHead;

    diaryHead = newEntry;

    printf("Entry added successfully!\n");
}

void viewEntries() {
    int entryCount = 0;

    printf("\n\nDiary Entries:\n\n");

    DiaryEntry *currentEntry = diaryHead;

    while (currentEntry != NULL) {
        printf("%d. %s\n\n", entryCount + 1, currentEntry->entry);
        currentEntry = currentEntry->next;
        entryCount++;
    }

    if (entryCount == 0) {
        printf("No entries found.\n");
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
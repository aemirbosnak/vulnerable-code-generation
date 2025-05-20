//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define DIARY_MAX_ENTRIES 100
#define ENTRY_MAX_LEN 256

typedef struct {
    char title[ENTRY_MAX_LEN];
    char content[ENTRY_MAX_LEN];
    time_t timestamp;
} DiaryEntry;

DiaryEntry diary[DIARY_MAX_ENTRIES];
int currentEntry = 0;

void printMenu() {
    printf("\nDigital Diary Menu:\n");
    printf("1. Add new entry\n");
    printf("2. Display all entries\n");
    printf("3. Display latest entry\n");
    printf("4. Delete latest entry\n");
    printf("5. Exit\n");
}

void addEntry() {
    if (currentEntry >= DIARY_MAX_ENTRIES) {
        printf("Diary is full. Cannot add new entry.\n");
        return;
    }

    printf("Enter entry title: ");
    scanf("%s", diary[currentEntry].title);

    printf("Enter entry content: ");
    scanf("%[^\n]", diary[currentEntry].content);

    diary[currentEntry].timestamp = time(NULL);
    printf("Entry added successfully.\n");
    currentEntry++;
}

void displayAllEntries() {
    int i;

    if (currentEntry == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    printf("\nDiary Entries:\n");

    for (i = 0; i < currentEntry; i++) {
        printf("\nEntry %d\n", i + 1);
        printf("Title: %s\n", diary[i].title);
        printf("Content: %s\n", diary[i].content);
        printf("Timestamp: %s", ctime(&diary[i].timestamp));
    }
}

void displayLatestEntry() {
    if (currentEntry == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    printf("\nLatest Entry:\n");
    printf("Title: %s\n", diary[currentEntry - 1].title);
    printf("Content: %s\n", diary[currentEntry - 1].content);
    printf("Timestamp: %s", ctime(&diary[currentEntry - 1].timestamp));
}

void deleteLatestEntry() {
    if (currentEntry == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    currentEntry--;
    printf("Entry deleted successfully.\n");
}

int main() {
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayAllEntries();
                break;
            case 3:
                displayLatestEntry();
                break;
            case 4:
                deleteLatestEntry();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_TITLE 100
#define MAX_CONTENT 1000
#define DATE_SIZE 20

typedef struct {
    char title[MAX_TITLE];
    char content[MAX_CONTENT];
    char date[DATE_SIZE];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void getCurrentDate(char *dateStr) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(dateStr, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    
    printf("Enter the title for the entry: ");
    fgets(diary[entryCount].title, MAX_TITLE, stdin);
    diary[entryCount].title[strcspn(diary[entryCount].title, "\n")] = 0; // Remove newline

    printf("Enter the content for the entry: ");
    fgets(diary[entryCount].content, MAX_CONTENT, stdin);
    diary[entryCount].content[strcspn(diary[entryCount].content, "\n")] = 0; // Remove newline

    getCurrentDate(diary[entryCount].date);
    entryCount++;

    printf("Diary entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Title: %s\n", diary[i].title);
        printf("Content: %s\n", diary[i].content);
        printf("Date: %s\n", diary[i].date);
        printf("-------------------------\n");
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int index;
    printf("Enter the entry number to delete (1 - %d): ", entryCount);
    scanf("%d", &index);
    getchar(); // Clear newline after number input

    if (index < 1 || index > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    // Shift entries to fill the gap
    for (int i = index - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }

    entryCount--;
    printf("Diary entry deleted successfully!\n");
}

void diaryMenu() {
    int choice;
    do {
        printf("\n--- Digital Diary Menu ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                printf("Exiting the Digital Diary. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    diaryMenu();
    return 0;
}
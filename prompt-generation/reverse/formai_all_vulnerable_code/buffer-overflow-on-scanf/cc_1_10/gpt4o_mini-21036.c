//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256
#define DATE_LENGTH 11

typedef struct {
    char date[DATE_LENGTH];
    char entry[ENTRY_LENGTH];
} DiaryEntry;

void addEntry();
void viewEntries();
void searchEntry();
void displayEntry(DiaryEntry diaryEntry);

int main() {
    int choice;
    
    while (1) {
        printf("\nDigital Diary Menu:\n");
        printf("1. Add Entry\n");
        printf("2. View All Entries\n");
        printf("3. Search Entry by Date\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character after choice input

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                printf("Exiting the diary. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void addEntry() {
    DiaryEntry entry;
    FILE *file = fopen("diary_entries.txt", "a");

    if (!file) {
        printf("Could not open diary file for writing.\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    fgets(entry.date, DATE_LENGTH, stdin);
    entry.date[strcspn(entry.date, "\n")] = 0; // remove newline after fgets

    printf("Write your diary entry: ");
    fgets(entry.entry, ENTRY_LENGTH, stdin);
    entry.entry[strcspn(entry.entry, "\n")] = 0; // remove newline after fgets

    fwrite(&entry, sizeof(DiaryEntry), 1, file);
    fclose(file);
    printf("Diary entry added!\n");
}

void viewEntries() {
    DiaryEntry entry;
    FILE *file = fopen("diary_entries.txt", "r");

    if (!file) {
        printf("Could not open diary file for reading.\n");
        return;
    }

    printf("\nYour Diary Entries:\n");
    while (fread(&entry, sizeof(DiaryEntry), 1, file)) {
        displayEntry(entry);
    }
    fclose(file);
}

void searchEntry() {
    char searchDate[DATE_LENGTH];
    DiaryEntry entry;
    int found = 0;
    
    FILE *file = fopen("diary_entries.txt", "r");
    if (!file) {
        printf("Could not open diary file for reading.\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD) to search for: ");
    fgets(searchDate, DATE_LENGTH, stdin);
    searchDate[strcspn(searchDate, "\n")] = 0; // remove newline after fgets

    while (fread(&entry, sizeof(DiaryEntry), 1, file)) {
        if (strcmp(searchDate, entry.date) == 0) {
            displayEntry(entry);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No entries found for date %s.\n", searchDate);
    }

    fclose(file);
}

void displayEntry(DiaryEntry diaryEntry) {
    printf("Date: %s\n", diaryEntry.date);
    printf("Entry: %s\n", diaryEntry.entry);
    printf("----------------------\n");
}
//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 250

typedef struct {
    char entry[MAX_LENGTH];
    time_t timestamp;
} DiaryEntry;

typedef struct {
    DiaryEntry entries[MAX_ENTRIES];
    int count;
} DigitalDiary;

// Function to initialize the diary
void initializeDiary(DigitalDiary *diary) {
    diary->count = 0;
}

// Function to add a new entry to the diary
void addEntry(DigitalDiary *diary, const char *entry) {
    if (diary->count < MAX_ENTRIES) {
        strncpy(diary->entries[diary->count].entry, entry, MAX_LENGTH);
        diary->entries[diary->count].timestamp = time(NULL);
        diary->count++;
        printf("Entry added successfully!\n");
    } else {
        printf("Diary is full! Unable to add new entry.\n");
    }
}

// Function to view all diary entries
void viewEntries(DigitalDiary *diary) {
    printf("\n--- Diary Entries ---\n");
    for (int i = 0; i < diary->count; i++) {
        printf("Entry %d: %s", i + 1, diary->entries[i].entry);
        printf("Date: %s", ctime(&diary->entries[i].timestamp));
    }
}

// Function to search for specific entries
void searchEntries(DigitalDiary *diary, const char *keyword) {
    printf("\n--- Search Results for '%s' ---\n", keyword);
    int found = 0;
    for (int i = 0; i < diary->count; i++) {
        if (strstr(diary->entries[i].entry, keyword) != NULL) {
            printf("Entry %d: %s", i + 1, diary->entries[i].entry);
            printf("Date: %s", ctime(&diary->entries[i].timestamp));
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found containing '%s'.\n", keyword);
    }
}

// Function to delete the last entry
void deleteLastEntry(DigitalDiary *diary) {
    if (diary->count > 0) {
        diary->count--;
        printf("Last entry deleted successfully!\n");
    } else {
        printf("Diary is empty! No entry to delete.\n");
    }
}

int main() {
    DigitalDiary myDiary;
    initializeDiary(&myDiary);
    int choice;
    char entry[MAX_LENGTH];
    char keyword[MAX_LENGTH];

    do {
        printf("\n--- Digital Diary Menu ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Search Entries\n");
        printf("4. Delete Last Entry\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after number input

        switch (choice) {
            case 1:
                printf("Enter your diary entry: ");
                fgets(entry, MAX_LENGTH, stdin);
                addEntry(&myDiary, entry);
                break;
            case 2:
                viewEntries(&myDiary);
                break;
            case 3:
                printf("Enter keyword to search: ");
                fgets(keyword, MAX_LENGTH, stdin);
                strtok(keyword, "\n");  // Remove the trailing newline character
                searchEntries(&myDiary, keyword);
                break;
            case 4:
                deleteLastEntry(&myDiary);
                break;
            case 5:
                printf("Exiting the diary. Till next time!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
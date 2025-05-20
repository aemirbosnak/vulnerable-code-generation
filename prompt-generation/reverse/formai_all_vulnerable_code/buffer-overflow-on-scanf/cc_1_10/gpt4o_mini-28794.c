//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY_LENGTH 256
#define INITIAL_CAPACITY 2

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char content[MAX_ENTRY_LENGTH];
} DiaryEntry;

typedef struct {
    DiaryEntry *entries;
    int size;
    int capacity;
} Diary;

// Function Prototypes
Diary* createDiary();
void addEntry(Diary *diary);
void viewEntries(Diary *diary);
void searchEntry(Diary *diary);
void freeDiary(Diary *diary);

int main() {
    Diary *diary = createDiary();
    int choice;

    while (1) {
        printf("\n--- Digital Diary ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Search Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                addEntry(diary);
                break;
            case 2:
                viewEntries(diary);
                break;
            case 3:
                searchEntry(diary);
                break;
            case 4:
                freeDiary(diary);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

Diary* createDiary() {
    Diary *diary = (Diary *)malloc(sizeof(Diary));
    diary->size = 0;
    diary->capacity = INITIAL_CAPACITY;
    diary->entries = (DiaryEntry *)malloc(sizeof(DiaryEntry) * diary->capacity);
    return diary;
}

void addEntry(Diary *diary) {
    if (diary->size >= diary->capacity) {
        diary->capacity *= 2;
        diary->entries = (DiaryEntry *)realloc(diary->entries, sizeof(DiaryEntry) * diary->capacity);
    }

    printf("Enter date (YYYY-MM-DD): ");
    fgets(diary->entries[diary->size].date, 11, stdin);
    diary->entries[diary->size].date[strcspn(diary->entries[diary->size].date, "\n")] = '\0'; // Remove newline

    printf("Enter your diary entry: ");
    fgets(diary->entries[diary->size].content, MAX_ENTRY_LENGTH, stdin);
    diary->entries[diary->size].content[strcspn(diary->entries[diary->size].content, "\n")] = '\0'; // Remove newline

    diary->size++;
    printf("Entry added successfully!\n");
}

void viewEntries(Diary *diary) {
    if (diary->size == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\n--- Diary Entries ---\n");
    for (int i = 0; i < diary->size; i++) {
        printf("Date: %s\n", diary->entries[i].date);
        printf("Entry: %s\n", diary->entries[i].content);
        printf("--------------------------\n");
    }
}

void searchEntry(Diary *diary) {
    char searchDate[11];
    printf("Enter date to search (YYYY-MM-DD): ");
    fgets(searchDate, 11, stdin);
    searchDate[strcspn(searchDate, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < diary->size; i++) {
        if (strcmp(diary->entries[i].date, searchDate) == 0) {
            printf("Entry found on %s:\n", diary->entries[i].date);
            printf("%s\n", diary->entries[i].content);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No entry found for the date %s.\n", searchDate);
    }
}

void freeDiary(Diary *diary) {
    free(diary->entries);
    free(diary);
}
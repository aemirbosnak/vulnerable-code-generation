//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11]; // YYYY-MM-DD
    char entry[MAX_LENGTH];
} DiaryEntry;

void initializeDiary(DiaryEntry diary[], int *size) {
    *size = 0;
}

void addEntry(DiaryEntry diary[], int *size) {
    if (*size >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }
    printf("Enter the diary entry: ");
    getchar(); // Eat newline character
    fgets(diary[*size].entry, MAX_LENGTH, stdin);
    diary[*size].entry[strcspn(diary[*size].entry, "\n")] = 0; // Remove newline

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(diary[*size].date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    (*size)++;
    printf("Entry added on %s\n", diary[*size-1].date);
}

void displayEntries(DiaryEntry diary[], int size) {
    if (size == 0) {
        printf("No entries found.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("[%s] %s\n", diary[i].date, diary[i].entry);
    }
}

void searchEntries(DiaryEntry diary[], int size) {
    char term[MAX_LENGTH];
    printf("Enter search term: ");
    getchar(); // Eat newline character
    fgets(term, MAX_LENGTH, stdin);
    term[strcspn(term, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strstr(diary[i].entry, term) != NULL) {
            printf("[%s] %s\n", diary[i].date, diary[i].entry);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries match the search term \"%s\".\n", term);
    }
}

void deleteEntry(DiaryEntry diary[], int *size) {
    if (*size == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int index;
    printf("Enter the entry number to delete (1 to %d): ", *size);
    scanf("%d", &index);
    
    if (index < 1 || index > *size) {
        printf("Invalid entry number!\n");
        return;
    }
    
    for (int i = index - 1; i < *size - 1; i++) {
        diary[i] = diary[i + 1];
    }
    (*size)--; // Decrease size after deletion
    printf("Entry %d deleted.\n", index);
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int size = 0;
    int choice;

    while (1) {
        printf("\n=== Digital Diary ===\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Search Entries\n");
        printf("4. Delete Entry\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(diary, &size);
                break;
            case 2:
                displayEntries(diary, size);
                break;
            case 3:
                searchEntries(diary, size);
                break;
            case 4:
                deleteEntry(diary, &size);
                break;
            case 5:
                printf("Exiting the diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please choose again!\n");
                break;
        }
    }
    return 0;
}
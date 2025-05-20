//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11];
    char entry[MAX_LENGTH];
} DiaryEntry;

void addEntry(DiaryEntry *diary, int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    sprintf(diary[*count].date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    printf("Enter your diary entry for %s:\n", diary[*count].date);
    getchar(); // clear newline character from buffer
    fgets(diary[*count].entry, MAX_LENGTH, stdin);
    diary[*count].entry[strcspn(diary[*count].entry, "\n")] = 0; // remove newline character

    (*count)++;
    printf("Entry added!\n");
}

void viewEntries(const DiaryEntry *diary, int count) {
    if (count == 0) {
        printf("No diary entries available.\n");
        return;
    }

    printf("\n*** Diary Entries ***\n");
    for (int i = 0; i < count; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n\n", diary[i].entry);
    }
}

void deleteEntry(DiaryEntry *diary, int *count) {
    if (*count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int entryNum;
    printf("Enter the entry number to delete (1 to %d): ", *count);
    scanf("%d", &entryNum);

    if (entryNum < 1 || entryNum > *count) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = entryNum - 1; i < *count - 1; i++) {
        diary[i] = diary[i + 1]; // shift entries left
    }
    
    (*count)--;
    printf("Entry %d deleted!\n", entryNum);
}

void saveEntries(const DiaryEntry *diary, int count) {
    FILE *file = fopen("diary_entries.txt", "w");
    if (!file) {
        printf("Error saving entries!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "Date: %s\n", diary[i].date);
        fprintf(file, "Entry: %s\n", diary[i].entry);
        fprintf(file, "-------------------\n");
    }

    fclose(file);
    printf("Entries saved to diary_entries.txt\n");
}

void loadEntries(DiaryEntry *diary, int *count) {
    FILE *file = fopen("diary_entries.txt", "r");
    if (!file) {
        printf("No saved diary found. Start adding entries!\n");
        return;
    }

    while (fscanf(file, "Date: %[^\n]\nEntry: %[^\n]\n-------------------\n", diary[*count].date, diary[*count].entry) != EOF) {
        (*count)++;
    }

    fclose(file);
    printf("Diary loaded! You have %d entries.\n", *count);
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int entryCount = 0;
    int choice;

    loadEntries(diary, &entryCount);
    
    do {
        printf("\n--- Digital Diary ---\n");
        printf("1. Add a Diary Entry\n");
        printf("2. View Diary Entries\n");
        printf("3. Delete a Diary Entry\n");
        printf("4. Save Diary Entries\n");
        printf("5. Load Diary Entries\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addEntry(diary, &entryCount);
                break;
            case 2: 
                viewEntries(diary, entryCount);
                break;
            case 3: 
                deleteEntry(diary, &entryCount);
                break;
            case 4: 
                saveEntries(diary, entryCount);
                break;
            case 5: 
                loadEntries(diary, &entryCount);
                break;
            case 6: 
                printf("Exiting the diary. Goodbye!\n");
                break;
            default: 
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
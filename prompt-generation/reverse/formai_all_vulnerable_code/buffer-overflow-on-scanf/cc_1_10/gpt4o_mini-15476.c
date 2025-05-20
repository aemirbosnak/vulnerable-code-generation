//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256

typedef struct {
    time_t date;
    char entry[ENTRY_LENGTH];
} DiaryEntry;

typedef struct {
    DiaryEntry entries[MAX_ENTRIES];
    int count;
} Diary;

void initializeDiary(Diary *diary) {
    diary->count = 0;
}

void addEntry(Diary *diary) {
    if (diary->count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    DiaryEntry newEntry;
    time(&newEntry.date);

    printf("Enter your diary entry: ");
    getchar();  // To consume the newline character
    fgets(newEntry.entry, ENTRY_LENGTH, stdin);
    
    // Remove newline character from entry if present
    newEntry.entry[strcspn(newEntry.entry, "\n")] = '\0';     

    diary->entries[diary->count] = newEntry;
    diary->count++;
    printf("Entry added successfully!\n");
}

void viewEntries(Diary *diary) {
    if (diary->count == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < diary->count; i++) {
        char timeString[20];
        struct tm *tm_info;

        tm_info = localtime(&diary->entries[i].date);
        strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", tm_info);

        printf("Entry #%d: %s\nDate: %s\n", i + 1, diary->entries[i].entry, timeString);
    }
}

void deleteEntry(Diary *diary) {
    if (diary->count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int entryNumber;
    printf("Enter the entry number to delete (1-%d): ", diary->count);
    scanf("%d", &entryNumber);

    if (entryNumber < 1 || entryNumber > diary->count) {
        printf("Invalid entry number.\n");
        return;
    }

    // Shift entries to remove the selected one
    for (int i = entryNumber - 1; i < diary->count - 1; i++) {
        diary->entries[i] = diary->entries[i + 1];
    }
    
    diary->count--;
    printf("Entry deleted successfully!\n");
}

void saveDiary(Diary *diary) {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    fwrite(diary, sizeof(Diary), 1, file);
    fclose(file);
    printf("Diary saved successfully!\n");
}

void loadDiary(Diary *diary) {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No saved diary found, starting a new one.\n");
        return;
    }

    fread(diary, sizeof(Diary), 1, file);
    fclose(file);
    printf("Diary loaded successfully with %d entries.\n", diary->count);
}

int main() {
    Diary myDiary;
    initializeDiary(&myDiary);
    loadDiary(&myDiary);

    int choice;
    
    do {
        printf("\nDigital Diary Menu:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Save Diary\n");
        printf("5. Load Diary\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(&myDiary);
                break;
            case 2:
                viewEntries(&myDiary);
                break;
            case 3:
                deleteEntry(&myDiary);
                break;
            case 4:
                saveDiary(&myDiary);
                break;
            case 5:
                loadDiary(&myDiary);
                break;
            case 6:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
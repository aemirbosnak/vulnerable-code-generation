//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256
#define DATE_LENGTH 20

typedef struct {
    char date[DATE_LENGTH];
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter your diary entry: \n");
    getchar(); // to consume the newline character left by previous input
    fgets(diary[entryCount].entry, ENTRY_LENGTH, stdin);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(diary[entryCount].date, "%02d-%02d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    entryCount++;
    printf("Entry added on %s\n", diary[entryCount - 1].date);
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Your Diary Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%s: %s", diary[i].date, diary[i].entry);
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }

    printf("Enter the index of the entry you wish to delete (0 to %d): ", entryCount - 1);
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= entryCount) {
        printf("Invalid index! Entry cannot be deleted.\n");
        return;
    }

    for (int i = index; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }

    entryCount--;
    printf("Entry deleted successfully!\n");
}

void saveDiary() {
    FILE *file = fopen("diary.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s: %s", diary[i].date, diary[i].entry);
    }

    fclose(file);
    printf("Diary saved to diary.txt\n");
}

void loadDiary() {
    FILE *file = fopen("diary.txt", "r");
    if (!file) {
        printf("No saved diary found. Starting fresh!\n");
        return;
    }

    while (fgets(diary[entryCount].entry, ENTRY_LENGTH, file) && entryCount < MAX_ENTRIES) {
        strncpy(diary[entryCount].date, diary[entryCount].entry, DATE_LENGTH);
        diary[entryCount].date[10] = '\0'; // Keep only the date part (10 chars)
        entryCount++;
    }

    fclose(file);
    printf("Diary loaded from diary.txt\n");
}

int main() {
    printf("Welcome to your Digital Diary!\n");
    loadDiary();

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Save Diary\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);

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
                saveDiary();
                break;
            case 5:
                printf("Exiting the diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
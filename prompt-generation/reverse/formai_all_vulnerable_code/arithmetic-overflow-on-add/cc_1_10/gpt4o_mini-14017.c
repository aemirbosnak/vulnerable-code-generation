//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: mind-bending
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

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    sprintf(diary[entryCount].date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    printf("Enter your diary entry: ");
    getchar(); // consume previous newline
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);
    
    // Remove newline character
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0;

    printf("Entry added on %s\n", diary[entryCount].date);
    entryCount++;
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries in your diary.\n");
        return;
    }

    printf("\n--- Your Diary Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("[%d] %s: %s\n", i + 1, diary[i].date, diary[i].entry);
    }
    printf("--------------------------\n");
}

void deleteEntry() {
    viewEntries();
    printf("Enter the entry number to delete: ");
    
    int index;
    scanf("%d", &index);
    
    if (index < 1 || index > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = index - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    
    entryCount--;
    printf("Entry deleted successfully.\n");
}

void saveDiary() {
    FILE *file = fopen("diary.txt", "w");
    if (!file) {
        printf("Error opening file to save diary.\n");
        return;
    }
  
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s\n%s\n", diary[i].date, diary[i].entry);
    }

    fclose(file);
    printf("Diary saved to diary.txt\n");
}

void loadDiary() {
    FILE *file = fopen("diary.txt", "r");
    if (!file) {
        printf("No saved diary found.\n");
        return;
    }

    while (fscanf(file, "%10s\n", diary[entryCount].date) != EOF) {
        fgets(diary[entryCount].entry, MAX_LENGTH, file);
        diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0; // Remove newline
        entryCount++;
    }

    fclose(file);
    printf("Diary loaded successfully. You have %d entries.\n", entryCount);
}

void displayMenu() {
    printf("\n---- Digital Diary ----\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Save Diary\n");
    printf("5. Load Diary\n");
    printf("6. Exit\n");
    printf("-----------------------\n");
}

int main() {
    int choice;

    loadDiary();

    do {
        displayMenu();
        printf("Choose an option: ");
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
                loadDiary();
                break;
            case 6:
                printf("Exiting the diary... Remember your thoughts!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 6);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_CONTENT 256
#define DATE_FORMAT "%Y-%m-%d %H:%M:%S"

typedef struct {
    char timestamp[20];
    char content[MAX_CONTENT];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void getCurrentTime(char *buffer) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, 20, DATE_FORMAT, tm_info);
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    char timestamp[20];
    getCurrentTime(timestamp);

    printf("Enter your diary entry: ");
    getchar();  // clear the newline from input buffer
    fgets(diary[entryCount].content, MAX_CONTENT, stdin);
    diary[entryCount].content[strcspn(diary[entryCount].content, "\n")] = 0;  // remove newline

    strcpy(diary[entryCount].timestamp, timestamp);
    entryCount++;
    printf("Entry added successfully on %s.\n", timestamp);
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found in your diary.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Date: %s\n", diary[i].timestamp);
        printf("Entry: %s\n\n", diary[i].content);
    }
}

void deleteEntry() {
    int entryNumber;
    printf("Enter the entry number to delete: ");
    scanf("%d", &entryNumber);

    if (entryNumber < 1 || entryNumber > entryCount) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = entryNumber - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entryCount--;
    printf("Entry %d deleted successfully.\n", entryNumber);
}

void saveDiary() {
    FILE *file = fopen("diary.txt", "w");
    if (!file) {
        printf("Could not open diary file for writing.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s|%s\n", diary[i].timestamp, diary[i].content);
    }
    fclose(file);
    printf("Diary saved successfully!\n");
}

void loadDiary() {
    FILE *file = fopen("diary.txt", "r");
    if (!file) {
        printf("No saved diary found. Starting fresh.\n");
        return;
    }
    
    while (fscanf(file, "%19[^|]|%255[^\n]\n", diary[entryCount].timestamp, diary[entryCount].content) != EOF) {
        entryCount++;
    }
    fclose(file);
    printf("Diary loaded successfully! %d entries found.\n", entryCount);
}

void displayMenu() {
    printf("\n--- Retro Diary Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Save Diary\n");
    printf("5. Load Diary\n");
    printf("6. Exit\n");
    printf("------------------------\n");
}

int main() {
    loadDiary();
    int choice;
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
                printf("Exiting Diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
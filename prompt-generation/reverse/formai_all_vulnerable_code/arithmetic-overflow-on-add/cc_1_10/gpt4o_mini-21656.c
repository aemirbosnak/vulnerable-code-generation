//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[20];
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
    
    printf("Enter your diary entry (Max %d characters):\n", MAX_LENGTH - 1);
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);
    
    snprintf(diary[entryCount].date, sizeof(diary[entryCount].date), "%02d-%02d-%04d %02d:%02d:%02d", 
             tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    entryCount++;
    printf("Entry added successfully!\n");
}

void showEntries() {
    if (entryCount == 0) {
        printf("No entries in the diary yet.\n");
        return;
    }
    for (int i = 0; i < entryCount; ++i) {
        printf("Entry %d (%s):\n%s\n", i + 1, diary[i].date, diary[i].entry);
    }
}

void saveToFile() {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Error saving diary to file.\n");
        return;
    }
    for (int i = 0; i < entryCount; ++i) {
        fprintf(file, "Entry %d (%s):\n%s\n", i + 1, diary[i].date, diary[i].entry);
    }
    fclose(file);
    printf("Diary saved to diary.txt successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No existing diary file found.\n");
        return;
    }
    
    while (fgets(diary[entryCount].date, sizeof(diary[entryCount].date), file) != NULL && entryCount < MAX_ENTRIES) {
        fgets(diary[entryCount].entry, sizeof(diary[entryCount].entry), file);
        entryCount++;
    }
    fclose(file);
    printf("%d entries loaded from diary.txt.\n", entryCount);
}

void displayMenu() {
    printf("\n");
    printf("========== Digital Diary ==========\n");
    printf("1. Add a new entry\n");
    printf("2. Show all entries\n");
    printf("3. Save diary to file\n");
    printf("4. Load diary from file\n");
    printf("5. Exit\n");
    printf("===================================\n");
    printf("Choose an option: ");
}

int main() {
    loadFromFile();
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear input buffer
        
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                showEntries();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                loadFromFile();
                break;
            case 5:
                saveToFile();
                printf("Exiting the digital diary. Have a great day!\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}
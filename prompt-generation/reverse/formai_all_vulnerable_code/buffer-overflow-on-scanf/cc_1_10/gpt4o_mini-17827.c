//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256

typedef struct {
    char date[11];  // Format: YYYY-MM-DD
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

// Function to get the current date as a string
void getCurrentDate(char *dateStr) {
    time_t t = time(NULL);
    struct tm *tmInfo = localtime(&t);
    strftime(dateStr, 11, "%Y-%m-%d", tmInfo);
}

// Function to add a diary entry
void addDiaryEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    
    char dateStr[11];
    getCurrentDate(dateStr);
    
    printf("Writing a new entry for %s\n", dateStr);
    printf("Enter your diary entry (max %d characters):\n", ENTRY_LENGTH - 1);
    fgets(diary[entryCount].entry, ENTRY_LENGTH, stdin);
    
    // Remove the newline character from the input
    size_t len = strlen(diary[entryCount].entry);
    if (len > 0 && diary[entryCount].entry[len - 1] == '\n') {
        diary[entryCount].entry[len - 1] = '\0';
    }
    
    strcpy(diary[entryCount].date, dateStr);
    entryCount++;
    printf("Entry saved!\n");
}

// Function to view all diary entries
void viewDiaryEntries() {
    if (entryCount == 0) {
        printf("No entries found in the diary.\n");
        return;
    }
    
    printf("\n--- Diary Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].entry);
        printf("---------------------\n");
    }
}

// Function to clear all diary entries
void clearDiary() {
    entryCount = 0;
    printf("All diary entries have been cleared!\n");
}

// Function to save diary entries to a file
void saveDiaryToFile() {
    FILE *file = fopen("diary_entries.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "Date: %s\nEntry: %s\n", diary[i].date, diary[i].entry);
        fprintf(file, "------------------------\n");
    }
    
    fclose(file);
    printf("Diary entries have been saved to 'diary_entries.txt'.\n");
}

// Function to load diary entries from a file
void loadDiaryFromFile() {
    FILE *file = fopen("diary_entries.txt", "r");
    if (file == NULL) {
        printf("No existing diary file found. Starting fresh!\n");
        return;
    }
    
    while (fscanf(file, "Date: %[^\n]\nEntry: %[^\n]\n", diary[entryCount].date, diary[entryCount].entry) == 2) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) break;
        fscanf(file, "------------------------\n");
    }
    
    fclose(file);
    printf("Diary entries loaded successfully!\n");
}

// Main menu function
void displayMenu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Clear Diary\n");
    printf("4. Save Diary to File\n");
    printf("5. Load Diary from File\n");
    printf("6. Exit\n");
    printf("--------------------------\n");
}

int main() {
    loadDiaryFromFile();
    
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character left in the input buffer

        switch(choice) {
            case 1:
                addDiaryEntry();
                break;
            case 2:
                viewDiaryEntries();
                break;
            case 3:
                clearDiary();
                break;
            case 4:
                saveDiaryToFile();
                break;
            case 5:
                loadDiaryFromFile();
                break;
            case 6:
                printf("Exiting the diary. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
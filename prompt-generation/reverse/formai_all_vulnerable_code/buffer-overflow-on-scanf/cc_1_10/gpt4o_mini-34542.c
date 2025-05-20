//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char content[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

// Function prototypes
void addEntry();
void viewEntries();
void saveDiary();
void loadDiary();
void displayMenu();
void clearScreen();

int main() {
    loadDiary();
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character from input buffer

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                saveDiary();
                break;
            case 4:
                printf("Exiting the diary program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    clearScreen();
    printf("=== Digital Diary ===\n");
    printf("1. Add a new entry\n");
    printf("2. View diary entries\n");
    printf("3. Save diary to file\n");
    printf("4. Exit\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter your diary entry: ");
    fgets(diary[entryCount].content, MAX_LENGTH, stdin);
    diary[entryCount].content[strcspn(diary[entryCount].content, "\n")] = 0; // Remove newline

    // Get current date
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    snprintf(diary[entryCount].date, sizeof(diary[entryCount].date), "%04d-%02d-%02d", 
             t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
    
    entryCount++;
    printf("Entry added successfully!\n");
    getchar(); // Wait for user input before continuing
}

void viewEntries() {
    clearScreen();
    if (entryCount == 0) {
        printf("No entries found in the diary.\n");
    } else {
        printf("=== Diary Entries ===\n");
        for (int i = 0; i < entryCount; i++) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n\n", diary[i].content);
        }
    }
    getchar(); // Wait for user input before continuing
}

void saveDiary() {
    FILE *file = fopen("diary_entries.txt", "w");
    if (!file) {
        printf("Unable to save diary. Please check your permissions.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s\n%s\n\n", diary[i].date, diary[i].content);
    }
    fclose(file);
    printf("Diary saved successfully to diary_entries.txt!\n");
    getchar(); // Wait for user input before continuing
}

void loadDiary() {
    FILE *file = fopen("diary_entries.txt", "r");
    if (!file) {
        printf("No previous diary entries found. Starting fresh!\n");
        return;
    }
    
    while (fscanf(file, "%10s\n%255[^\n]\n", diary[entryCount].date, diary[entryCount].content) == 2) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) break;
    }
    fclose(file);
    printf("Diary entries loaded successfully!\n");
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}
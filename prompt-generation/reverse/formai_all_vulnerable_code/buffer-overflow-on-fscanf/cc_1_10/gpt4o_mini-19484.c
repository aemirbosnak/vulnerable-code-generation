//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256

typedef struct {
    char date[11];  // Format YYYY-MM-DD
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

// Function prototypes
void addEntry();
void viewEntries();
void searchEntry();
void saveDiary();
void loadDiary();
void showMenu();

int main() {
    loadDiary();
    int choice;

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: searchEntry(); break;
            case 4: saveDiary(); break;
            case 5: printf("Exiting the diary. Have a great day!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void showMenu() {
    printf("\n=== Digital Diary Menu ===\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Search Diary Entry\n");
    printf("4. Save Diary\n");
    printf("5. Exit\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add new entry.\n");
        return;
    }
    
    printf("Enter your diary entry: ");
    fgets(diary[entryCount].entry, ENTRY_LENGTH, stdin);
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0; // Remove newline
    
    // Get current date
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(diary[entryCount].date, sizeof(diary[entryCount].date), "%Y-%m-%d", t);
    
    entryCount++;
    printf("Diary entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries in the diary.\n");
        return;
    }
    
    printf("\n=== Diary Entries ===\n");
    for (int i = 0; i < entryCount; i++) {
        printf("[%s] %s\n", diary[i].date, diary[i].entry);
    }
}

void searchEntry() {
    if (entryCount == 0) {
        printf("No entries in the diary.\n");
        return;
    }
    
    char keyword[ENTRY_LENGTH];
    printf("Enter keyword to search: ");
    fgets(keyword, ENTRY_LENGTH, stdin);
    keyword[strcspn(keyword, "\n")] = 0; // Remove newline

    printf("\n=== Search Results ===\n");
    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].entry, keyword) != NULL) {
            printf("[%s] %s\n", diary[i].date, diary[i].entry);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found containing '%s'.\n", keyword);
    }
}

void saveDiary() {
    FILE *file = fopen("diary.txt", "w");
    if (!file) {
        printf("Error saving the diary.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "[%s] %s\n", diary[i].date, diary[i].entry);
    }
    fclose(file);
    printf("Diary saved successfully!\n");
}

void loadDiary() {
    FILE *file = fopen("diary.txt", "r");
    if (!file) {
        printf("No existing diary found. Starting a new diary.\n");
        return;
    }
    
    while (fscanf(file, "[%10[^]]] %[^\n]\n", diary[entryCount].date, diary[entryCount].entry) != EOF) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) {
            printf("Maximum entries reached. Stopping loading.\n");
            break;
        }
    }
    fclose(file);
    printf("Diary loaded successfully! You have %d entries.\n", entryCount);
}
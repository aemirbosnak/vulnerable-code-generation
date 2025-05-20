//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11]; // format: YYYY-MM-DD
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void displayMenu();
void addEntry();
void viewEntries();
void findRandomEntry();
void saveDiary();
void loadDiary();
void displayEntry(DiaryEntry entry);

int main() {
    loadDiary();
    int choice;
    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the number input
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                findRandomEntry();
                break;
            case 4:
                saveDiary();
                break;
            case 5:
                printf("Exiting the diary program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

void displayMenu() {
    printf("\n=== Digital Diary Menu ===\n");
    printf("1. Add a new entry\n");
    printf("2. View all entries\n");
    printf("3. Find a random entry\n");
    printf("4. Save diary to file\n");
    printf("5. Exit\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full, cannot add more entries.\n");
        return;
    }
    
    // Get the current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(diary[entryCount].date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    printf("Enter your diary entry (max %d characters): ", MAX_LENGTH - 1);
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = '\0'; // Remove the newline character

    entryCount++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }
    
    printf("\n=== Diary Entries ===\n");
    for (int i = 0; i < entryCount; i++) {
        displayEntry(diary[i]);
    }
}

void findRandomEntry() {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }
    
    srand(time(NULL));
    int randomIndex = rand() % entryCount;
    printf("\n=== Random Diary Entry ===\n");
    displayEntry(diary[randomIndex]);
}

void saveDiary() {
    FILE *file = fopen("diary.txt", "w");
    if (!file) {
        printf("Could not open diary.txt for writing.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s\n%s\n", diary[i].date, diary[i].entry);
    }
    fclose(file);
    printf("Diary saved successfully to diary.txt.\n");
}

void loadDiary() {
    FILE *file = fopen("diary.txt", "r");
    if (!file) {
        printf("No existing diary found, starting fresh.\n");
        return;
    }
    
    while (fscanf(file, "%10s\n%255[^\n]\n", diary[entryCount].date, diary[entryCount].entry) == 2) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) break;
    }
    fclose(file);
    printf("Diary loaded successfully with %d entries.\n", entryCount);
}

void displayEntry(DiaryEntry entry) {
    printf("Date: %s\n", entry.date);
    printf("Entry: %s\n\n", entry.entry);
}
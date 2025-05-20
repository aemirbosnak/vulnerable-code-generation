//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 500

typedef struct {
    char date[11];
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void viewEntries();
void searchEntry();
void displayMenu();
void saveEntriesToFile(const char *filename);
void loadEntriesFromFile(const char *filename);

int main() {
    loadEntriesFromFile("diary_entries.txt");
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                saveEntriesToFile("diary_entries.txt");
                printf("All entries saved to diary_entries.txt\n");
                break;
            case 5:
                printf("Exiting the diary. Thank you for sharing your thoughts!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add an Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search for an Entry\n");
    printf("4. Save Entries to File\n");
    printf("5. Exit\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    snprintf(diary[entryCount].date, sizeof(diary[entryCount].date), "%04d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

    printf("\nWrite your diary entry (max %d characters):\n", MAX_LENGTH - 1);
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);
    
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0; // Remove trailing newline
    entryCount++;
    printf("Your entry has been added successfully!\n");
}

void viewEntries() {
    printf("\n====== Your Diary Entries ======\n");
    for (int i = 0; i < entryCount; i++) {
        printf("[%s] %s\n", diary[i].date, diary[i].entry);
    }
    if (entryCount == 0) {
        printf("No entries found.\n");
    }
}

void searchEntry() {
    char keyword[MAX_LENGTH];
    printf("Enter a keyword to search for: ");
    fgets(keyword, MAX_LENGTH, stdin);
    keyword[strcspn(keyword, "\n")] = 0; // Remove trailing newline

    int found = 0;
    printf("\nSearch Results for '%s':\n", keyword);
    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].entry, keyword) != NULL) {
            printf("[%s] %s\n", diary[i].date, diary[i].entry);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found containing the keyword '%s'.\n", keyword);
    }
}

void saveEntriesToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error saving entries to file.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "[%s] %s\n", diary[i].date, diary[i].entry);
    }
    fclose(file);
}

void loadEntriesFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No previous entries found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "[%10[^]]] %499[^\n]\n", diary[entryCount].date, diary[entryCount].entry) == 2) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) break;
    }
    fclose(file);
}
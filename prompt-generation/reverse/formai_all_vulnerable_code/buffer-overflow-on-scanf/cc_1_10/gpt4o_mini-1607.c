//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256

typedef struct {
    char date[20];
    char content[ENTRY_LENGTH];
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
    
    printf("Enter your diary entry:\n");
    getchar(); // Consume newline leftover
    fgets(diary[entryCount].content, ENTRY_LENGTH, stdin);
    diary[entryCount].content[strcspn(diary[entryCount].content, "\n")] = 0; // Strip newline

    sprintf(diary[entryCount].date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    entryCount++;

    printf("Entry added on %s!\n", diary[entryCount - 1].date);
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries found.\n");
        return;
    }

    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < entryCount; ++i) {
        printf("%s: %s\n", diary[i].date, diary[i].content);
    }
    printf("\n");
}

void saveDiary() {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < entryCount; ++i) {
        fprintf(file, "%s: %s\n", diary[i].date, diary[i].content);
    }

    fclose(file);
    printf("Diary saved to diary.txt!\n");
}

void loadDiary() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No saved diary found.\n");
        return;
    }

    char buffer[ENTRY_LENGTH + 20]; // Extra for date
    entryCount = 0;

    while (fgets(buffer, sizeof(buffer), file) && entryCount < MAX_ENTRIES) {
        sscanf(buffer, "%19[^:]: %[^\n]", diary[entryCount].date, diary[entryCount].content);
        entryCount++;
    }

    fclose(file);
    printf("Diary loaded from diary.txt!\n");
}

void displayMenu() {
    printf("\nWelcome to Your Digital Diary!\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Save Diary\n");
    printf("4. Load Diary\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    loadDiary(); // Load any saved diary at the start

    do {
        displayMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

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
                loadDiary();
                break;
            case 5:
                printf("Exiting Digital Diary. Stay inspired!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
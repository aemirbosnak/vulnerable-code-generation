//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: decentralized
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
int totalEntries = 0;

void addEntry();
void viewEntries();
void deleteEntry();
void saveEntries();
void loadEntries();
void displayMenu();

int main() {
    loadEntries();
    displayMenu();
    return 0;
}

void displayMenu() {
    int choice;
    do {
        printf("\n=== Digital Diary ===\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Save Entries\n");
        printf("5. Load Entries\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        getchar(); // Consume trailing newline character

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
                saveEntries();
                break;
            case 5:
                loadEntries();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 6);
}

void addEntry() {
    if (totalEntries >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    DiaryEntry newEntry;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(newEntry.date, sizeof(newEntry.date), "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    
    printf("Enter your diary entry: ");
    fgets(newEntry.entry, MAX_LENGTH, stdin);
    newEntry.entry[strcspn(newEntry.entry, "\n")] = 0; // Remove newline character

    diary[totalEntries] = newEntry;
    totalEntries++;
    printf("Entry added!\n");
}

void viewEntries() {
    if (totalEntries == 0) {
        printf("No entries found!\n");
        return;
    }

    printf("\n=== Diary Entries ===\n");
    for (int i = 0; i < totalEntries; i++) {
        printf("%d. %s: %s\n", i + 1, diary[i].date, diary[i].entry);
    }
}

void deleteEntry() {
    if (totalEntries == 0) {
        printf("No entries to delete!\n");
        return;
    }

    int index;
    printf("Enter the entry number to delete (1 to %d): ", totalEntries);
    scanf("%d", &index);
    getchar(); // Consume trailing newline

    if (index < 1 || index > totalEntries) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = index - 1; i < totalEntries - 1; i++) {
        diary[i] = diary[i + 1];
    }
    totalEntries--;
    printf("Entry deleted!\n");
}

void saveEntries() {
    FILE *file = fopen("diary_entries.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < totalEntries; i++) {
        fprintf(file, "%s\n%s\n", diary[i].date, diary[i].entry);
    }
    fclose(file);
    printf("Entries saved!\n");
}

void loadEntries() {
    FILE *file = fopen("diary_entries.txt", "r");
    if (file == NULL) {
        printf("No saved diary found. Starting fresh!\n");
        return;
    }

    while (fscanf(file, "%10s\n%255[^\n]\n", diary[totalEntries].date, diary[totalEntries].entry) != EOF) {
        totalEntries++;
        if (totalEntries >= MAX_ENTRIES) {
            printf("Maximum entries reached while loading from file.\n");
            break;
        }
    }
    fclose(file);
    printf("Entries loaded! Total entries: %d\n", totalEntries);
}
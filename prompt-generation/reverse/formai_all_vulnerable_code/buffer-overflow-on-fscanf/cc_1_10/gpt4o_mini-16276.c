//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[20];
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Sorry, diary is full! Can't add more entries.\n");
        return;
    }
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    printf("Grateful Diary Entry on %02d/%02d/%d:\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("What are you grateful for today?\n");
    
    printf("Your Entry: ");
    getchar(); // to consume newline
    fgets(entries[entryCount].entry, MAX_LENGTH, stdin);
    entries[entryCount].entry[strcspn(entries[entryCount].entry, "\n")] = 0; // remove newline
    
    sprintf(entries[entryCount].date, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    entryCount++;

    printf("Your entry has been saved! Thank you for sharing your thoughts.\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries to display yet. Start adding to your gratitude list!\n");
        return;
    }

    printf("\n--- Your Grateful Diary Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", entries[i].date);
        printf("Entry: %s\n", entries[i].entry);
        printf("---------------------------------\n");
    }
}

void saveEntriesToFile() {
    FILE *file = fopen("diary_entries.txt", "w");
    if (!file) {
        printf("Failed to open file for saving entries.\n");
        return;
    }
    
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "Date: %s\nEntry: %s\n", entries[i].date, entries[i].entry);
        fprintf(file, "---------------------------------\n");
    }

    fclose(file);
    printf("Entries saved to diary_entries.txt. What a wonderful record of your gratitude!\n");
}

void loadEntriesFromFile() {
    FILE *file = fopen("diary_entries.txt", "r");
    if (!file) {
        printf("No previous diary entries found. Let's create new memories!\n");
        return;
    }

    while (fscanf(file, "Date: %s\nEntry: %[^\n]\n", entries[entryCount].date, entries[entryCount].entry) == 2) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) break;
    }

    fclose(file);
    printf("Previous entries loaded successfully! Embrace the gratitude of yesterday.\n");
}

void displayMenu() {
    printf("\n--- Grateful Digital Diary Menu ---\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Save Entries to File\n");
    printf("4. Load Entries from File\n");
    printf("5. Exit\n");
    printf("Please choose an option (1-5): ");
}

int main() {
    printf("Welcome to Your Grateful Digital Diary!\n");
    
    loadEntriesFromFile();

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                saveEntriesToFile();
                break;
            case 4:
                loadEntriesFromFile();
                break;
            case 5:
                printf("Thank you for using the Grateful Digital Diary! Embrace your future days with gratitude.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
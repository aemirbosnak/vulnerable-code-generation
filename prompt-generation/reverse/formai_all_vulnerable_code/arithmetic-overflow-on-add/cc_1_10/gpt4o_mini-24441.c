//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 512

typedef struct {
    char date[20];
    char content[ENTRY_SIZE];
} DiaryEntry;

void displayMenu();
void addEntry();
void viewEntries();
void searchEntries();
void saveEntry(DiaryEntry entry);
void loadEntries(DiaryEntry entries[], int *numEntries);

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character left by scanf()

        switch (choice) {
            case 1: 
                addEntry();
                break;
            case 2: 
                viewEntries();
                break;
            case 3: 
                searchEntries();
                break;
            case 4: 
                printf("Exiting the diary. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nWelcome to Your Digital Diary!\n");
    printf("1. Add a new diary entry\n");
    printf("2. View all diary entries\n");
    printf("3. Search diary entries\n");
    printf("4. Exit\n");
}

void addEntry() {
    DiaryEntry entry;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Prepare the date string
    sprintf(entry.date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    // Get the diary content
    printf("Enter your diary entry (max %d characters):\n", ENTRY_SIZE - 1);
    fgets(entry.content, ENTRY_SIZE, stdin);
    entry.content[strcspn(entry.content, "\n")] = '\0'; // Remove the newline character

    // Save the entry to the file
    saveEntry(entry);
    printf("Your diary entry has been saved!\n");
}

void viewEntries() {
    DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;

    // Load entries from the file
    loadEntries(entries, &numEntries);

    if (numEntries == 0) {
        printf("No diary entries found!\n");
    } else {
        printf("\nYour Diary Entries:\n");
        for (int i = 0; i < numEntries; i++) {
            printf("Date: %s\n", entries[i].date);
            printf("Entry: %s\n\n", entries[i].content);
        }
    }
}

void searchEntries() {
    DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    char keyword[100];

    // Load entries from the file
    loadEntries(entries, &numEntries);

    if (numEntries == 0) {
        printf("No diary entries found to search!\n");
        return;
    }

    printf("Enter a keyword to search for: ");
    fgets(keyword, 100, stdin);
    keyword[strcspn(keyword, "\n")] = '\0'; // Remove the newline character

    printf("\nSearch Results:\n");
    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].content, keyword) != NULL) {
            printf("Date: %s\n", entries[i].date);
            printf("Entry: %s\n\n", entries[i].content);
        }
    }
}

void saveEntry(DiaryEntry entry) {
    FILE *file = fopen("diary.txt", "a");
    if (file) {
        fprintf(file, "%s\n%s\n", entry.date, entry.content);
        fclose(file);
    } else {
        printf("Could not save the entry.\n");
    }
}

void loadEntries(DiaryEntry entries[], int *numEntries) {
    FILE *file = fopen("diary.txt", "r");
    if (file) {
        while (fscanf(file, "%[^\n]\n%[^\n]\n", entries[*numEntries].date, entries[*numEntries].content) != EOF) {
            (*numEntries)++;
            if (*numEntries >= MAX_ENTRIES) {
                break;
            }
        }
        fclose(file);
    }
}
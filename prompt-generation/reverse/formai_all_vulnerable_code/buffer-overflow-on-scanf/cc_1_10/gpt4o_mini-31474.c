//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000
#define DIARY_FILE "diary.txt"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} DiaryEntry;

void addEntry();
void viewEntries();
void clearEntries();
void displayMenu();
void loadEntries(int *entryCount, DiaryEntry *entries);

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // clear the newline character from buffer

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                clearEntries();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add New Entry\n");
    printf("2. View Entries\n");
    printf("3. Clear All Entries\n");
    printf("4. Exit\n");
}

void addEntry() {
    DiaryEntry entry;
    FILE *file = fopen(DIARY_FILE, "a");
    
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("Enter entry title: ");
    fgets(entry.title, MAX_TITLE_LENGTH, stdin);
    entry.title[strcspn(entry.title, "\n")] = 0; // Remove newline

    printf("Enter entry content: ");
    fgets(entry.content, MAX_CONTENT_LENGTH, stdin);
    entry.content[strcspn(entry.content, "\n")] = 0; // Remove newline

    fprintf(file, "%s\n%s\n\n", entry.title, entry.content);
    fclose(file);
    printf("Entry added successfully!\n");
}

void viewEntries() {
    FILE *file = fopen(DIARY_FILE, "r");
    char buffer[1024];

    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("\n--- Diary Entries ---\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
    printf("---------------------\n");
}

void clearEntries() {
    FILE *file = fopen(DIARY_FILE, "w");
    
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }
    
    fclose(file);
    printf("All entries cleared successfully!\n");
}

void loadEntries(int *entryCount, DiaryEntry *entries) {
    FILE *file = fopen(DIARY_FILE, "r");
    char title[MAX_TITLE_LENGTH], content[MAX_CONTENT_LENGTH];
    
    if (file == NULL) {
        *entryCount = 0;
        return;
    }

    *entryCount = 0;
    while (fgets(title, sizeof(title), file) != NULL && *entryCount < MAX_ENTRIES) {
        strcpy(entries[*entryCount].title, title);
        title[strcspn(title, "\n")] = 0;

        fgets(content, sizeof(content), file);
        strcpy(entries[*entryCount].content, content);
        content[strcspn(content, "\n")] = 0;

        (*entryCount)++;
        fgets(content, sizeof(content), file);  // Read the empty line
    }
    fclose(file);
}
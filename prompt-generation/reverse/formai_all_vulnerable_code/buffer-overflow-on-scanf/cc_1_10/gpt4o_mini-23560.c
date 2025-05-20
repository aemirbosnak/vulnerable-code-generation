//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 50
#define MAX_CONTENT_LENGTH 500
#define FILE_NAME "diary_entries.txt"

// Structure to represent a diary entry
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} DiaryEntry;

// Function prototypes
void addEntry(DiaryEntry diary[], int *entryCount);
void viewEntries(DiaryEntry diary[], int entryCount);
void saveEntriesToFile(DiaryEntry diary[], int entryCount);
void loadEntriesFromFile(DiaryEntry diary[], int *entryCount);
void displayMenu();

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int entryCount = 0;
    int choice;

    // Load existing entries from file at the start
    loadEntriesFromFile(diary, &entryCount);

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after integer input

        switch (choice) {
            case 1:
                addEntry(diary, &entryCount);
                saveEntriesToFile(diary, entryCount);
                break;
            case 2:
                viewEntries(diary, entryCount);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void displayMenu() {
    printf("\n=== Digital Diary Menu ===\n");
    printf("1. Add a new diary entry\n");
    printf("2. View all diary entries\n");
    printf("3. Exit\n");
}

void addEntry(DiaryEntry diary[], int *entryCount) {
    if (*entryCount >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }

    printf("Enter title: ");
    fgets(diary[*entryCount].title, MAX_TITLE_LENGTH, stdin);
    diary[*entryCount].title[strcspn(diary[*entryCount].title, "\n")] = '\0'; // Remove newline

    printf("Enter content (end with a blank line):\n");
    char line[MAX_CONTENT_LENGTH];
    diary[*entryCount].content[0] = '\0'; // Initialize content
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (line[0] == '\n') { // Blank line indicates end of content
            break;
        }
        strcat(diary[*entryCount].content, line);
    }

    (*entryCount)++;
    printf("Diary entry added successfully!\n");
}

void viewEntries(DiaryEntry diary[], int entryCount) {
    if (entryCount == 0) {
        printf("No diary entries available.\n");
        return;
    }

    printf("\n=== Diary Entries ===\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Title: %s\n", diary[i].title);
        printf("Content:\n%s\n", diary[i].content);
        printf("-----------------------\n");
    }
}

void saveEntriesToFile(DiaryEntry diary[], int entryCount) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error saving entries to file!\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "Title: %s\n", diary[i].title);
        fprintf(file, "Content:\n%s\n", diary[i].content);
        fprintf(file, "-----------------------\n");
    }

    fclose(file);
    printf("Diary entries saved successfully!\n");
}

void loadEntriesFromFile(DiaryEntry diary[], int *entryCount) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No previous entries found. Starting fresh.\n");
        return;
    }

    while (fgets(diary[*entryCount].title, MAX_TITLE_LENGTH, file) != NULL) {
        diary[*entryCount].title[strcspn(diary[*entryCount].title, "\n")] = '\0'; // Remove newline
        fgets(diary[*entryCount].content, MAX_CONTENT_LENGTH, file);
        (*entryCount)++;
    }

    fclose(file);
    printf("Diary entries loaded successfully!\n");
}
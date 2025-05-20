//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000
#define DIARY_FILE "diary.txt"

// Structure to hold diary entry
typedef struct {
    char date[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} DiaryEntry;

// Function prototypes
void addEntry();
void viewEntries();
void searchByDate();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("==== Digital Diary ====\n");
        printf("1. Add Diary Entry\n");
        printf("2. View Diary Entries\n");
        printf("3. Search Entry by Date\n");
        printf("4. Exit\n");
        printf("=======================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the input buffer

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchByDate();
                break;
            case 4:
                printf("Exiting the diary. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void addEntry() {
    DiaryEntry entry;
    FILE *file = fopen(DIARY_FILE, "a");

    if (!file) {
        perror("Error opening the diary file");
        return;
    }

    printf("Enter the date (YYYY-MM-DD): ");
    fgets(entry.date, sizeof(entry.date), stdin);
    entry.date[strcspn(entry.date, "\n")] = 0; // Remove newline character

    printf("Write your diary entry:\n");
    fgets(entry.content, sizeof(entry.content), stdin);
    entry.content[strcspn(entry.content, "\n")] = 0; // Remove newline character

    fprintf(file, "%s\n%s\n", entry.date, entry.content);
    fclose(file);
    printf("Diary entry added successfully!\n");
}

void viewEntries() {
    DiaryEntry entry;
    FILE *file = fopen(DIARY_FILE, "r");

    if (!file) {
        perror("Error opening the diary file");
        return;
    }

    printf("==== Diary Entries ====\n");
    while (fgets(entry.date, sizeof(entry.date), file)) {
        fgets(entry.content, sizeof(entry.content), file);
        entry.date[strcspn(entry.date, "\n")] = 0; // Remove new line character
        entry.content[strcspn(entry.content, "\n")] = 0; // Remove new line character
        printf("Date: %s\n", entry.date);
        printf("Entry: %s\n", entry.content);
        printf("-----------------------\n");
    }
    fclose(file);
}

void searchByDate() {
    char date[MAX_TITLE_LENGTH];
    DiaryEntry entry;
    int found = 0;

    printf("Enter the date to search (YYYY-MM-DD): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = 0; // Remove newline character

    FILE *file = fopen(DIARY_FILE, "r");
    if (!file) {
        perror("Error opening the diary file");
        return;
    }

    while (fgets(entry.date, sizeof(entry.date), file)) {
        fgets(entry.content, sizeof(entry.content), file);
        entry.date[strcspn(entry.date, "\n")] = 0; // Remove new line character
        entry.content[strcspn(entry.content, "\n")] = 0; // Remove new line character
        
        if (strcmp(entry.date, date) == 0) {
            printf("Date: %s\n", entry.date);
            printf("Entry: %s\n", entry.content);
            printf("-----------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No entries found for the date: %s\n", date);
    }

    fclose(file);
}
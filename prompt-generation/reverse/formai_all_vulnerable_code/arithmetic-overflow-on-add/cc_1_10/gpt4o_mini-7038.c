//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define FILE_NAME "diary.txt"

typedef struct {
    char date[11];  // Format: YYYY-MM-DD
    char entry[MAX_LENGTH];
} DiaryEntry;

void addEntry();
void viewEntries();
void searchEntry();
void getCurrentDate(char *buffer, size_t length);
void initializeDiaryFile();

int main() {
    int choice;
    initializeDiaryFile();

    printf("Welcome to your Digital Diary!\n");
    do {
        printf("\n--- Menu ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Search Entry by Date\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        getchar();  // Consume newline character

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
                printf("Exiting. Thank you for using the Digital Diary!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void initializeDiaryFile() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file) {
        fclose(file);
    } else {
        printf("Error initializing diary file!\n");
    }
}

void getCurrentDate(char *buffer, size_t length) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(buffer, length, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

void addEntry() {
    DiaryEntry entry;
    getCurrentDate(entry.date, sizeof(entry.date));

    printf("Write your diary entry (press ENTER to finish):\n");
    fgets(entry.entry, sizeof(entry.entry), stdin);
    entry.entry[strcspn(entry.entry, "\n")] = '\0';  // Remove newline character

    FILE *file = fopen(FILE_NAME, "a");
    if (file) {
        fprintf(file, "%s\n%s\n", entry.date, entry.entry);
        fclose(file);
        printf("Diary entry added successfully!\n");
    } else {
        printf("Error saving the entry.\n");
    }
}

void viewEntries() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file) {
        char line[MAX_LENGTH];
        printf("\n--- Diary Entries ---\n");
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Error opening diary file!\n");
    }
}

void searchEntry() {
    char date[11];
    printf("Enter the date (YYYY-MM-DD) to search for: ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';  // Remove newline character

    FILE *file = fopen(FILE_NAME, "r");
    if (file) {
        char line[MAX_LENGTH];
        int found = 0;
        printf("\n--- Search Results ---\n");

        while (fgets(line, sizeof(line), file)) {
            if (strcmp(line, date) == 0) {
                found = 1;
                printf("Date: %s", line);
                if (fgets(line, sizeof(line), file)) {
                    printf("Entry: %s", line);
                }
                printf("\n");
            }
        }

        if (!found) {
            printf("No entries found for the date: %s\n", date);
        }
        fclose(file);
    } else {
        printf("Error opening diary file!\n");
    }
}
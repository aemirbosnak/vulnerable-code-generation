//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 1024
#define FILENAME "diary.txt"

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char content[MAX_LENGTH];
} Entry;

void getCurrentDate(char *date) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

void addEntry() {
    Entry entry;
    getCurrentDate(entry.date);

    printf("Enter your diary entry for %s:\n", entry.date);
    getchar(); // Clear the newline from previous input
    fgets(entry.content, MAX_LENGTH, stdin);
    
    FILE *file = fopen(FILENAME, "a");
    if (file != NULL) {
        fprintf(file, "%s\n%s\n", entry.date, entry.content);
        fclose(file);
        printf("Diary entry saved!\n");
    } else {
        printf("Error saving the diary entry.\n");
    }
}

void viewEntries() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No entries found.\n");
        return;
    }

    Entry entry;
    printf("Diary Entries:\n");
    while (fgets(entry.date, sizeof(entry.date), file) != NULL) {
        fgets(entry.content, sizeof(entry.content), file);
        printf("Date: %sContent: %s\n", entry.date, entry.content);
    }
    
    fclose(file);
}

void clearDiary() {
    if (remove(FILENAME) == 0) {
        printf("Diary cleared successfully.\n");
    } else {
        printf("Error clearing the diary.\n");
    }
}

void menu() {
    int choice;
    do {
        printf("\nDigital Diary Menu:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Clear Diary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                clearDiary();
                break;
            case 4:
                printf("Exiting the diary. Have a nice day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    printf("Welcome to your Digital Diary!\n");
    menu();
    return 0;
}
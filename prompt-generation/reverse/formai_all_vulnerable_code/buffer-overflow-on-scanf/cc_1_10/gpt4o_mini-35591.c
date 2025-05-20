//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[MAX_LENGTH];
    char entry[MAX_LENGTH];
} DiaryEntry;

void addEntry();
void viewEntries();
void deleteEntry();
void clearBuffer();
void displayMenu();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

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
                printf("Exiting the diary. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addEntry() {
    DiaryEntry entry;
    FILE *file = fopen("diary.txt", "a");

    if (!file) {
        perror("Unable to open diary file");
        return;
    }

    printf("Enter the date (YYYY-MM-DD): ");
    fgets(entry.date, MAX_LENGTH, stdin);
    entry.date[strcspn(entry.date, "\n")] = 0; // Remove newline character

    printf("Write your diary entry:\n");
    fgets(entry.entry, MAX_LENGTH, stdin);
    entry.entry[strcspn(entry.entry, "\n")] = 0; // Remove newline character

    fprintf(file, "%s|%s\n", entry.date, entry.entry);
    fclose(file);

    printf("Diary entry added successfully!\n");
}

void viewEntries() {
    FILE *file = fopen("diary.txt", "r");
    char line[MAX_LENGTH * 2];

    if (!file) {
        perror("Unable to open diary file");
        return;
    }

    printf("\n----- Diary Entries -----\n");
    while (fgets(line, sizeof(line), file)) {
        char *date = strtok(line, "|");
        char *entry = strtok(NULL, "\n");
        if (date && entry) {
            printf("Date: %s\nEntry: %s\n", date, entry);
        }
    }
    fclose(file);
    printf("-------------------------\n");
}

void deleteEntry() {
    FILE *file = fopen("diary.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    char line[MAX_LENGTH * 2];
    char dateToDelete[MAX_LENGTH];

    if (!file || !tempFile) {
        perror("Unable to open diary file");
        return;
    }

    printf("Enter the date of the entry to delete (YYYY-MM-DD): ");
    fgets(dateToDelete, MAX_LENGTH, stdin);
    dateToDelete[strcspn(dateToDelete, "\n")] = 0; // Remove newline character

    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char *date = strtok(line, "|");
        if (date && strcmp(date, dateToDelete) != 0) {
            fputs(line, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    remove("diary.txt");
    rename("temp.txt", "diary.txt");

    if (found) {
        printf("Diary entry for %s deleted successfully!\n", dateToDelete);
    } else {
        printf("No entry found for the date %s.\n", dateToDelete);
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void displayMenu() {
    printf("\n----- Digital Diary -----\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
    printf("-------------------------\n");
}
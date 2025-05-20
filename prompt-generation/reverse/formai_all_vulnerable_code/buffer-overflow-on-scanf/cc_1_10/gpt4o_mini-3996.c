//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 255
#define FILENAME "diary.txt"

typedef struct {
    char date[MAX_LENGTH];
    char content[MAX_LENGTH];
} DiaryEntry;

void addEntry();
void viewEntries();
void deleteEntry(int entryNumber);

int main() {
    int choice;

    while (1) {
        printf("\n=================== Digital Diary ===================\n");
        printf("1. Add Diary Entry\n");
        printf("2. View Diary Entries\n");
        printf("3. Delete Diary Entry\n");
        printf("4. Exit\n");
        printf("======================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from the input buffer

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3: {
                int entryNumber;
                printf("Enter entry number to delete: ");
                scanf("%d", &entryNumber);
                deleteEntry(entryNumber);
                break;
            }
            case 4:
                printf("Exiting Diary...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addEntry() {
    DiaryEntry newEntry;
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Failed to open diary file");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    fgets(newEntry.date, MAX_LENGTH, stdin);
    printf("Write your diary entry: ");
    fgets(newEntry.content, MAX_LENGTH, stdin);

    fprintf(file, "%s:%s", newEntry.date, newEntry.content); // Save entry with date
    fclose(file);
    printf("Entry added successfully!\n");
}

void viewEntries() {
    FILE *file = fopen(FILENAME, "r");
    char line[MAX_LENGTH * 2];
    int entryNumber = 1;

    if (!file) {
        printf("No entries found.\n");
        return;
    }

    printf("\n=================== Diary Entries ===================\n");
    while (fgets(line, sizeof(line), file)) {
        char *date = strtok(line, ":");
        char *content = strtok(NULL, ":");
        printf("%d. [%s] %s\n", entryNumber++, date, content);
    }
    printf("======================================================\n");
    fclose(file);
}

void deleteEntry(int entryNumber) {
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    char line[MAX_LENGTH * 2];
    int currentLine = 1;

    if (!file || !tempFile) {
        perror("Error opening files");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        if (currentLine != entryNumber) {
            fputs(line, tempFile); // Write lines other than the one to delete
        }
        currentLine++;
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME); // Remove original file
    rename("temp.txt", FILENAME); // Rename temp file to original

    printf("Entry %d deleted successfully!\n", entryNumber);
}
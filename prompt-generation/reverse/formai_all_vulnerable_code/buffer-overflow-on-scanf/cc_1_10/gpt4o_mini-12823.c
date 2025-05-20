//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256
#define FILENAME "diary.txt"

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char content[ENTRY_LENGTH];
} DiaryEntry;

void writeEntry(DiaryEntry entry) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Failed to open diary file.\n");
        return;
    }
    fprintf(file, "%s: %s\n", entry.date, entry.content);
    fclose(file);
}

void readEntries() {
    char buffer[ENTRY_LENGTH + 20]; // Extra space for date prefix
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No diary entries found.\n");
        return;
    }
    
    printf("Diary Entries:\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

void deleteDiary() {
    if (remove(FILENAME) == 0) {
        printf("Diary erased successfully.\n");
    } else {
        printf("Failed to delete diary.\n");
    }
}

void getCurrentDate(char *dateStr) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(dateStr, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

int main() {
    int choice;
    DiaryEntry entry;

    while (1) {
        printf("\n=== Digital Diary ===\n");
        printf("1. Write an Entry\n");
        printf("2. Read Entries\n");
        printf("3. Clear Diary\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // To consume newline after scanf

        switch (choice) {
            case 1:
                printf("Enter your diary entry (max %d characters):\n", ENTRY_LENGTH);
                fgets(entry.content, ENTRY_LENGTH, stdin);
                // Remove newline character from entry.content
                entry.content[strcspn(entry.content, "\n")] = '\0';
                getCurrentDate(entry.date);
                writeEntry(entry);
                printf("Diary entry written successfully.\n");
                break;
            case 2:
                readEntries();
                break;
            case 3:
                deleteDiary();
                break;
            case 4:
                printf("Exiting diary application.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
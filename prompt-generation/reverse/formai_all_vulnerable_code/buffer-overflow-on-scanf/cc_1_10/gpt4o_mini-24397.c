//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_CONTENT 256
#define DIARY_FILE "diary.txt"

typedef struct {
    char date[11]; // format: YYYY-MM-DD
    char content[MAX_CONTENT];
} DiaryEntry;

void writeEntryToFile(DiaryEntry entry) {
    FILE *file = fopen(DIARY_FILE, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%s | %s\n", entry.date, entry.content);
    fclose(file);
}

void readEntriesFromFile() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        printf("No entries found yet.\n");
        return;
    }
    
    char line[300];
    printf("======== Diary Entries ========\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    printf("===============================\n");
}

void getCurrentDate(char *date) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int choice;

    do {
        printf("========= Digital Diary =========\n");
        printf("1. Write a new entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // consume the newline character

        switch (choice) {
            case 1:
                if (strlen(entries[0].content) < MAX_CONTENT) {
                    getCurrentDate(entries[0].date);
                    printf("Enter your diary entry: ");
                    fgets(entries[0].content, MAX_CONTENT, stdin);
                    entries[0].content[strcspn(entries[0].content, "\n")] = 0; // Remove newline character

                    writeEntryToFile(entries[0]);
                    printf("Entry saved successfully!\n");
                } else {
                    printf("Maximum entry limit reached!\n");
                }
                break;

            case 2:
                readEntriesFromFile();
                break;

            case 3:
                printf("Exiting the diary. Take care!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
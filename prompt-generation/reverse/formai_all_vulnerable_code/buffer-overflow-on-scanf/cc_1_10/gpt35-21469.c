//FormAI DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 1000      // Maximum length of each diary entry
#define MAX_ENTRIES 100           // Maximum number of diary entries
#define FILENAME "diary.txt"      // Diary file name

typedef struct {
    int year;
    int month;
    int day;
} Date;                           // Structure to hold date information

typedef struct {
    Date date;
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;                     // Structure to hold a single diary entry

void addEntry(DiaryEntry entries[], int *count);      // Add a new diary entry
void viewEntries(DiaryEntry entries[], int count);    // View existing diary entries
int menu();                                            // Display menu and return user's choice

int main() {
    DiaryEntry entries[MAX_ENTRIES];              // Array to hold all diary entries
    int entryCount = 0;                           // Number of existing diary entries
    FILE *filePtr = fopen(FILENAME, "r");         // Attempt to open diary file for reading

    if (filePtr != NULL) {
        printf("Loading diary from file...\n");

        // Read in existing diary entries from file
        while (!feof(filePtr) && entryCount < MAX_ENTRIES) {
            char dateStr[11];                   // Date string in format "YYYY/MM/DD"
            fgets(dateStr, 11, filePtr);        // Read in date string
            entries[entryCount].date.year = atoi(strtok(dateStr, "/"));
            entries[entryCount].date.month = atoi(strtok(NULL, "/"));
            entries[entryCount].date.day = atoi(strtok(NULL, "/"));
            fgets(entries[entryCount].entry, MAX_ENTRY_LENGTH, filePtr);  // Read in diary entry
            entryCount++;
        }

        fclose(filePtr);    // Close diary file
    } else {
        printf("No diary file found\n");
    }

    int choice = menu();

    while (choice != 3) {
        switch (choice) {
            case 1:
                addEntry(entries, &entryCount);
                break;
            case 2:
                viewEntries(entries, entryCount);
                break;
            default:
                printf("Invalid choice\n");
        }

        choice = menu();
    }

    printf("Saving diary to file...\n");

    filePtr = fopen(FILENAME, "w");   // Open diary file for writing

    // Write all existing diary entries to file
    for (int i = 0; i < entryCount; i++) {
        fprintf(filePtr, "%d/%02d/%02d\n%s", entries[i].date.year, entries[i].date.month, entries[i].date.day, entries[i].entry);
    }

    fclose(filePtr);    // Close diary file

    printf("Diary saved to file %s\n", FILENAME);

    return 0;
}

void addEntry(DiaryEntry entries[], int *count) {
    // Get current date and time
    time_t t = time(NULL);
    struct tm currentTime = *localtime(&t);
    Date currentDate = {currentTime.tm_year + 1900, currentTime.tm_mon + 1, currentTime.tm_mday};

    // Get new diary entry from user
    printf("Enter your diary entry (max %d characters):\n", MAX_ENTRY_LENGTH);
    fgets(entries[*count].entry, MAX_ENTRY_LENGTH, stdin);

    // Trim excess newline character from input
    char *newline = strchr(entries[*count].entry, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }

    // Add current date to diary entry
    entries[*count].date = currentDate;

    printf("Diary entry added!\n");

    (*count)++;   // Increase number of existing diary entries
}

void viewEntries(DiaryEntry entries[], int count) {
    if (count == 0) {
        printf("No diary entries found\n");
        return;
    }

    // Display all existing diary entries
    printf("Existing diary entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%d/%02d/%02d: %s\n", entries[i].date.year, entries[i].date.month, entries[i].date.day, entries[i].entry);
    }
}

int menu() {
    printf("\n1. Add diary entry\n");
    printf("2. View existing entries\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);
    getchar();   // Consume newline character left in input buffer

    return choice;
}
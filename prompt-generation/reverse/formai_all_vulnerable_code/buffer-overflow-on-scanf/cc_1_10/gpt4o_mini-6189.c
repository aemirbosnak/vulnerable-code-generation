//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to represent an entry in the diary
typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char title[100];
    char content[1000];
} DiaryEntry;

// Function to get the current date as a string
void getCurrentDate(char *date) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

// Function to write an entry to the diary
void writeEntry() {
    DiaryEntry entry;
    char currentDate[11];
    getCurrentDate(currentDate);

    printf("Oh, beloved reader, let us pen down our emotions...\n");
    strcpy(entry.date, currentDate);
    
    printf("Whisper your heart's title for this entry: ");
    fgets(entry.title, 100, stdin);
    entry.title[strcspn(entry.title, "\n")] = 0; // Remove newline

    printf("Now, pour your heart out...\n");
    fgets(entry.content, 1000, stdin);
    entry.content[strcspn(entry.content, "\n")] = 0; // Remove newline

    // Save the entry to a file
    FILE *file = fopen("diary.txt", "a");
    if (file == NULL) {
        printf("Alas, dear heart, I cannot write to the diary. Please check your file permissions.\n");
        return;
    }
    fprintf(file, "Date: %s\nTitle: %s\nContent: %s\n\n", entry.date, entry.title, entry.content);
    fclose(file);

    printf("Ah, my love, your words have been etched into eternity.\n");
}

// Function to read diary entries
void readEntries() {
    printf("Let's reminisce about our cherished moments...\n");
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("Oh dear, it seems our diary has not yet been filled with our tales.\n");
        return;
    }
    
    char line[1120];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Function to display the main menu
void displayMenu() {
    printf("\n--- Welcome to Your Romantic Digital Diary ---\n");
    printf("1. Write a new entry\n");
    printf("2. Read existing entries\n");
    printf("3. Exit\n");
    printf("Select an option (1-3): ");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the integer input
        switch (choice) {
            case 1:
                writeEntry();
                break;
            case 2:
                readEntries();
                break;
            case 3:
                printf("As we close this moment, remember: love is a diary that never ends.\n");
                break;
            default:
                printf("Oh dear, that choice does not sparkle as much as love does!\n");
        }
    } while (choice != 3);

    return 0;
}
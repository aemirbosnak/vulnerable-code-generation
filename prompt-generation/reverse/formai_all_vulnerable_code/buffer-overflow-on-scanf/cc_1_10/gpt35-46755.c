//FormAI DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100 // Maximum number of entries in diary
#define MAX_LENGTH 500 // Maximum length of an entry
#define DATE_FORMAT "[%d/%m/%y]" // Format for date in diary

typedef struct DiaryEntry {
    char date[12];
    char text[MAX_LENGTH];
} DiaryEntry;

int num_entries = 0;
DiaryEntry entries[MAX_ENTRIES];

// Function prototype
void addEntry();

int main() {
    char option;

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add new entry\n");
        printf("2. View previous entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                addEntry();
                break;

            case '2':
                if (num_entries == 0) {
                    printf("\nNo entries found!\n");
                } else {
                    printf("\nPrevious diary entries:\n");
                    for (int i = 0; i < num_entries; i++) {
                        printf("%d. %s %s\n", i+1, entries[i].date, entries[i].text);
                    }
                }
                break;

            case '3':
                printf("\nThank you for using Digital Diary!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid option! Try again.\n");
                break;
        }
    }

    return 0;    
}

void addEntry() {
    char text[MAX_LENGTH];

    // Get current date and time
    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);
    char date_string[12];
    strftime(date_string, sizeof(date_string), DATE_FORMAT, current_time);

    printf("\nEnter your diary entry for %s\n", date_string);
    printf("(max length %d characters):\n", MAX_LENGTH);
    scanf(" %[^\n]%*c", text);

    // Add entry to diary
    if (num_entries < MAX_ENTRIES) {
        DiaryEntry newEntry;
        strcpy(newEntry.date, date_string);
        strcpy(newEntry.text, text);
        entries[num_entries++] = newEntry;

        printf("\nEntry added successfully!\n");
    } else {
        printf("\nDiary is full!\n");
    }
}
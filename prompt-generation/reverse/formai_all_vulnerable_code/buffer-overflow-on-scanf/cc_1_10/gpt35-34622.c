//FormAI DATASET v1.0 Category: Digital Diary ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

// Structure to hold each diary entry
typedef struct {
    char date[11]; // dd/mm/yyyy format
    char text[1000];
} DiaryEntry;

// Function to add a new entry to the diary
void addEntry(DiaryEntry entries[], int *count) {
    char date[11];
    char text[1000];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(date, sizeof(date), "%d/%m/%Y", tm); // Get current date in dd/mm/yyyy format

    printf("Enter your diary entry for today (maximum 1000 characters):\n");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    // Add the new entry to the array
    strcpy(entries[*count].date, date);
    strcpy(entries[*count].text, text);
    (*count)++;

    printf("Entry added successfully!\n");
}

// Function to view all entries in the diary
void viewAllEntries(DiaryEntry entries[], int count) {
    if (count == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("All diary entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].text);
    }
}

// Function to view entries on a particular date
void viewEntriesOnDate(DiaryEntry entries[], int count) {
    char date[11];
    int foundEntries = 0;

    printf("Enter the date (dd/mm/yyyy) to view entries:\n");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            printf("%s: %s\n", entries[i].date, entries[i].text);
            foundEntries++;
        }
    }

    if (foundEntries == 0) {
        printf("No entries found on the given date.\n");
    }
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("\n");
        printf("1. Add a new diary entry\n");
        printf("2. View all diary entries\n");
        printf("3. View diary entries on a particular date\n");
        printf("4. Exit\n");
        printf("Enter your choice (1/2/3/4):\n");

        int choice;
        scanf("%d", &choice);
        getchar(); // consume the newline character left by scanf

        switch (choice) {
            case 1: addEntry(entries, &count); break;
            case 2: viewAllEntries(entries, count); break;
            case 3: viewEntriesOnDate(entries, count); break;
            case 4: printf("Goodbye!\n"); exit(0);
            default: printf("Invalid choice, please try again.\n"); break;
        }
    }

    return 0;
}
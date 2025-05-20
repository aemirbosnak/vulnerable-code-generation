//FormAI DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000 // Maximum entries that can be stored in the diary

struct Entry {
    char date[11]; // Format: YYYY-MM-DD
    char time[6]; // Format: HH:MM
    char content[1000]; // Content of the entry
};

// Function prototypes
void clearScreen();
void addEntry(struct Entry *entries, int *numEntries);
void viewEntries(struct Entry *entries, int numEntries);
void searchEntries(struct Entry *entries, int numEntries);
void editEntries(struct Entry *entries, int numEntries);

int main() {
    struct Entry entries[MAX_ENTRIES];
    int numEntries = 0; // Number of entries currently stored in the diary
    int choice;

    do {
        clearScreen();
        printf("************ DIGITAL DIARY ************\n\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Edit entries\n");
        printf("5. Exit\n\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(entries, &numEntries);
                break;
            case 2:
                viewEntries(entries, numEntries);
                break;
            case 3:
                searchEntries(entries, numEntries);
                break;
            case 4:
                editEntries(entries, numEntries);
                break;
            case 5:
                printf("\nThank you for using the digital diary.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 5.\n");
        }

        printf("\nPress ENTER to continue...");
        getchar();
        getchar(); // Wait for user to press ENTER
    } while (choice != 5);

    return 0;
}

// Function to clear the screen
void clearScreen() {
    #ifdef __linux__
        system("clear");
    #else
        system("cls");
    #endif
}

// Function to add a new entry to the diary
void addEntry(struct Entry *entries, int *numEntries) {
    if (*numEntries >= MAX_ENTRIES) {
        printf("\nUnable to add entry. Diary is full.\n");
        return;
    }

    // Get current date and time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Add new entry
    printf("\nEnter the content of the entry:\n");
    getchar(); // Clear input buffer
    fgets(entries[*numEntries].content, 1000, stdin);
    entries[*numEntries].content[strcspn(entries[*numEntries].content, "\n")] = 0; // Remove newline character
    sprintf(entries[*numEntries].date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    sprintf(entries[*numEntries].time, "%02d:%02d", tm.tm_hour, tm.tm_min);

    *numEntries += 1;

    printf("\nEntry added successfully.\n");
}

// Function to view all entries in the diary
void viewEntries(struct Entry *entries, int numEntries) {
    if (numEntries == 0) {
        printf("\nNo entries found.\n");
        return;
    }

    printf("\n%-15s %-10s %-10s\n", "Date", "Time", "Content");
    for (int i = 0; i < numEntries; i++) {
        printf("%-15s %-10s %s\n", entries[i].date, entries[i].time, entries[i].content);
    }
}

// Function to search for an entry in the diary
void searchEntries(struct Entry *entries, int numEntries) {
    if (numEntries == 0) {
        printf("\nNo entries found.\n");
        return;
    }

    char keyword[1000];
    printf("\nEnter a keyword to search for: ");
    getchar(); // Clear input buffer
    fgets(keyword, 1000, stdin);
    keyword[strcspn(keyword, "\n")] = 0; // Remove newline character

    printf("\n%-15s %-10s %-10s\n", "Date", "Time", "Content");
    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].content, keyword) != NULL) {
            printf("%-15s %-10s %s\n", entries[i].date, entries[i].time, entries[i].content);
        }
    }
}

// Function to edit an entry in the diary
void editEntries(struct Entry *entries, int numEntries) {
    if (numEntries == 0) {
        printf("\nNo entries found.\n");
        return;
    }

    int index;
    printf("\nEnter the index of the entry to be edited (1-%d): ", numEntries);
    scanf("%d", &index);

    if (index < 1 || index > numEntries) {
        printf("\nInvalid index. Please enter a number between 1 and %d.\n", numEntries);
        return;
    }

    printf("\nEnter the new content of the entry:\n");
    getchar(); // Clear input buffer
    fgets(entries[index-1].content, 1000, stdin);
    entries[index-1].content[strcspn(entries[index-1].content, "\n")] = 0; // Remove newline character

    printf("\nEntry edited successfully.\n");
}
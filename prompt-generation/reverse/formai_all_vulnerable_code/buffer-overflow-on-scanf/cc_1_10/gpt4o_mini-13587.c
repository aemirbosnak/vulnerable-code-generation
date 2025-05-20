//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct DiaryEntry {
    char date[11];   // Format: YYYY-MM-DD
    char content[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void viewEntries();
void searchEntry();
int isValidDate(const char *date);
void displayMenu();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // flush newline character

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                printf("Exiting the diary.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entry by Date\n");
    printf("4. Exit\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full, cannot add more entries.\n");
        return;
    }

    DiaryEntry newEntry;
    printf("Enter date (YYYY-MM-DD): ");
    fgets(newEntry.date, sizeof(newEntry.date), stdin);
    newEntry.date[strcspn(newEntry.date, "\n")] = 0; // remove newline character

    if (!isValidDate(newEntry.date)) {
        printf("Invalid date format. Please try again.\n");
        return;
    }

    printf("Enter your diary entry: ");
    fgets(newEntry.content, sizeof(newEntry.content), stdin);
    newEntry.content[strcspn(newEntry.content, "\n")] = 0; // remove newline character

    diary[entryCount++] = newEntry; // add entry to diary
    printf("Entry added successfully.\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\n--- Diary Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].content);
        printf("--------------------\n");
    }
}

void searchEntry() {
    char date[11];
    printf("Enter date (YYYY-MM-DD) to search: ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = 0; // remove newline character

    if (!isValidDate(date)) {
        printf("Invalid date format. Please try again.\n");
        return;
    }

    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n", diary[i].content);
            printf("--------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No entries found for the date %s.\n", date);
    }
}

int isValidDate(const char *date) {
    // Simple validation for date format YYYY-MM-DD
    if (strlen(date) != 10) return 0;
    if (date[4] != '-' || date[7] != '-') return 0;
    
    for (int i = 0; i < strlen(date); i++) {
        if (i != 4 && i != 7 && (date[i] < '0' || date[i] > '9')) return 0;
    }
    
    return 1;
}
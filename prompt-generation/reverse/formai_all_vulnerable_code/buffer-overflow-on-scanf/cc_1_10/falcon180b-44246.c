//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", entries[entryCount].date);

    printf("Enter your entry:\n");
    fgets(entries[entryCount].entry, MAX_ENTRY_LENGTH, stdin);

    entryCount++;

    printf("Entry added successfully.\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Diary entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void searchEntry() {
    if (entryCount == 0) {
        printf("Diary is empty.\n");
        return;
    }

    char searchDate[20];
    printf("Enter date to search (YYYY-MM-DD): ");
    scanf("%s", searchDate);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].date, searchDate) == 0) {
            printf("%s\n%s", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

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
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
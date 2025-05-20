//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct Entry {
    char date[MAX_LENGTH];
    char content[MAX_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Alas! The diary is full. No more entries can be inscribed.\n");
        return;
    }

    printf("Pray, enter the date of the entry (e.g., '1st January 1250'): ");
    fgets(diary[entryCount].date, MAX_LENGTH, stdin);
    diary[entryCount].date[strcspn(diary[entryCount].date, "\n")] = 0; // Remove newline

    printf("With great fervor, pen down your thoughts:\n");
    fgets(diary[entryCount].content, MAX_LENGTH, stdin);
    diary[entryCount].content[strcspn(diary[entryCount].content, "\n")] = 0; // Remove newline

    entryCount++;
    printf("Thy entry has been successfully recorded! \n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("Alas! The quill hath not danced upon the parchment yet.\n");
        return;
    }

    printf("\n*** The Chronicles of Thy Thoughts ***\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Date: %s\n", diary[i].date);
        printf("Content: %s\n\n", diary[i].content);
    }
}

void searchEntry() {
    char dateSearch[MAX_LENGTH];
    printf("Pray, enter the date thou wishest to search for: ");
    fgets(dateSearch, MAX_LENGTH, stdin);
    dateSearch[strcspn(dateSearch, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(diary[i].date, dateSearch) == 0) {
            printf("Entry found!\n");
            printf("Date: %s\n", diary[i].date);
            printf("Content: %s\n\n", diary[i].content);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Alas! No entries found for such a date.\n");
    }
}

void printMenu() {
    printf("\n=============== The Royal Diary ===============\n");
    printf("1. Add a new entry\n");
    printf("2. View all entries\n");
    printf("3. Search an entry by date\n");
    printf("4. Exit\n");
    printf("===============================================\n");
}

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Choose an option from the menu: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

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
                printf("Fare thee well, fairest scribe. The diary shall await thy return.\n");
                exit(0);
            default:
                printf("An unrecognized choice hath been made. Please try again.\n");
        }
    }

    return 0;
}
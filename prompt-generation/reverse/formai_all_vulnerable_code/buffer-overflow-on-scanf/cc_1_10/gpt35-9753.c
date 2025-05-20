//FormAI DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_LENGTH 100

struct Entry {
    char date[20];
    char content[MAX_LENGTH];
};

int numOfEntries = 0;
struct Entry entries[MAX_ENTRIES];

void addEntry() {
    if (numOfEntries >= MAX_ENTRIES) {
        printf("Sorry, the diary is full!\n");
        return;
    }

    printf("Enter the date (ex: 2022-03-20): ");
    scanf("%s", entries[numOfEntries].date);

    printf("Enter your content:\n");
    getchar(); // clears input buffer before fgets
    fgets(entries[numOfEntries].content, MAX_LENGTH, stdin);

    numOfEntries++;
    printf("Entry added!\n");
}

void viewEntry() {
    if (numOfEntries == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    printf("Enter the date of the entry to view (ex: 2022-03-20): ");
    char targetDate[20];
    scanf("%s", targetDate);

    int found = 0;
    for (int i = 0; i < numOfEntries; i++) {
        if (strcmp(entries[i].date, targetDate) == 0) {
            printf("Entry for %s:\n%s\n", entries[i].date, entries[i].content);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No entry found for %s.\n", targetDate);
    }
}

void deleteEntry() {
    if (numOfEntries == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    printf("Enter the date of the entry to delete (ex: 2022-03-20): ");
    char targetDate[20];
    scanf("%s", targetDate);

    int found = 0;
    for (int i = 0; i < numOfEntries; i++) {
        if (strcmp(entries[i].date, targetDate) == 0) {
            for (int j = i; j < numOfEntries; j++) {
                entries[j] = entries[j+1];
            }
            numOfEntries--;
            found = 1;
            printf("Entry deleted!\n");
            break;
        }
    }

    if (!found) {
        printf("No entry found for %s.\n", targetDate);
    }
}

void displayMenu() {
    printf("\n1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntry();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try Again!\n");
        }
    }

    return 0;
}
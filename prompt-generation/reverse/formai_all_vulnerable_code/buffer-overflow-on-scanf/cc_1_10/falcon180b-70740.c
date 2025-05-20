//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: Diary is full.\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", diary[numEntries].date);

    printf("Enter your entry:\n");
    fgets(diary[numEntries].entry, MAX_ENTRY_LENGTH, stdin);

    numEntries++;
}

void viewEntries() {
    if (numEntries == 0) {
        printf("No entries yet.\n");
        return;
    }

    printf("Diary entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\n%s\n", diary[i].date, diary[i].entry);
    }
}

void deleteEntry() {
    if (numEntries == 0) {
        printf("No entries yet.\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD) to delete entry: ");
    scanf("%s", diary[numEntries-1].date);

    numEntries--;
}

int main() {
    srand(time(0));
    printf("Welcome to your digital diary!\n");
    printf("What would you like to do?\n");
    printf("1. Add entry\n");
    printf("2. View entries\n");
    printf("3. Delete entry\n");
    printf("4. Exit\n");

    int choice;
    scanf("%d", &choice);

    while (choice!= 4) {
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
    }

    return 0;
}
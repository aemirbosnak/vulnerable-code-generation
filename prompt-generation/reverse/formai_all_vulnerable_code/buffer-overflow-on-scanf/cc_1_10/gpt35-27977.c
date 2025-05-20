//FormAI DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 1000 // Maximum number of entries allowed in the diary.

typedef struct DiaryEntry {
    char date[11];
    char title[100];
    char entry[1000];
} DiaryEntry;

int numEntries = 0; // Keeps track of the number of entries in the diary.
DiaryEntry diary[MAX_ENTRIES]; // Array to store diary entries.

// Function to add a new entry to the diary.
void addEntry() {
    if (numEntries == MAX_ENTRIES) {
        printf("Diary is full. Cannot add new entries.\n");
        return;
    }

    DiaryEntry newEntry;

    printf("Enter date (DD/MM/YYYY): ");
    scanf(" %s", newEntry.date); // Space before %s to consume newline character.
    printf("Enter title: ");
    scanf(" %[^\n]s", newEntry.title); // %[^\n]s to capture whole line.
    printf("Enter entry: ");
    scanf(" %[^\n]s", newEntry.entry); // %[^\n]s to capture whole line.

    diary[numEntries] = newEntry;
    numEntries++;

    printf("Entry added successfully!\n");
}

// Function to display all entries of the diary.
void displayEntries() {
    if (numEntries == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("Displaying all entries:\n");

    for (int i = 0; i < numEntries; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Title: %s\n", diary[i].title);
        printf("Entry: %s\n", diary[i].entry);
        printf("\n");
    }
}

int main() {
    int choice;

    printf("*** C Digital Diary ***\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add new entry\n");
        printf("2. Display all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                printf("Thank you for using the C Digital Diary!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
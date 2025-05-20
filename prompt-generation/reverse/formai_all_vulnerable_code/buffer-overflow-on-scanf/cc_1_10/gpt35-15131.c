//FormAI DATASET v1.0 Category: Digital Diary ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

// Data structure to hold diary entry
typedef struct {
    char date[11];
    char entry[1000];
} DiaryEntry;

int num_entries = 0; // Number of entries currently in diary
DiaryEntry entries[MAX_ENTRIES]; // Array to hold diary entries

// Function to add a new entry to diary
void add_entry() {
    // Get current date/time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char date[11];
    sprintf(date, "%02d/%02d/%04d", tm->tm_mday, tm->tm_mon+1, tm->tm_year+1900);

    // Prompt user to enter diary entry
    printf("Enter new diary entry (1000 character limit):\n");
    char entry[1000];
    fgets(entry, 1000, stdin);

    // Create new diary entry and add to array
    DiaryEntry new_entry;
    strcpy(new_entry.date, date);
    strcpy(new_entry.entry, entry);
    entries[num_entries++] = new_entry;
}

// Function to display all diary entries
void display_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
    } else {
        printf("Date      Entry\n");
        printf("================\n");
        for (int i = 0; i < num_entries; i++) {
            printf("%s  %s", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\n\n********** My Happy Digital Diary **********\n");
        printf("1. Add new Diary Entry\n");
        printf("2. Display All Diary Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                add_entry();
                printf("Entry added successfully!\n");
                break;
            case 2:
                display_entries();
                break;
            case 3:
                printf("Exiting program... Have a happy day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
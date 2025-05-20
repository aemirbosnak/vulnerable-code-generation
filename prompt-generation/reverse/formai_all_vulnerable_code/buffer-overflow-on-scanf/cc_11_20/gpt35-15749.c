//FormAI DATASET v1.0 Category: Digital Diary ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY_LENGTH 512
#define MAX_ENTRIES 100

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    do {
        printf("\nDigital Diary Menu\n");
        printf("1. Add new entry\n");
        printf("2. View all entries\n");
        printf("3. Search entries by date\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                if (num_entries >= MAX_ENTRIES) {
                    printf("Error: Maximum entries exceeded.\n");
                    break;
                }
                printf("Enter date (DD/MM/YYYY): ");
                scanf("%10s", entries[num_entries].date);
                printf("Enter entry: ");
                scanf(" %[^\n]", entries[num_entries].entry);
                num_entries++;
                printf("Entry added.\n");
                break;
            case '2':
                if (num_entries == 0) {
                    printf("There are no entries yet.\n");
                    break;
                }
                printf("All entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("Date: %s\n", entries[i].date);
                    printf("Entry: %s\n", entries[i].entry);
                }
                break;
            case '3':
                if (num_entries == 0) {
                    printf("There are no entries yet.\n");
                    break;
                }
                char date[11];
                printf("Enter date to search for (DD/MM/YYYY): ");
                scanf("%10s", date);
                int found = 0;
                for (int i = 0; i < num_entries; i++) {
                    if (strcmp(entries[i].date, date) == 0) {
                        printf("Date: %s\n", entries[i].date);
                        printf("Entry: %s\n", entries[i].entry);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("No entries found for date %s.\n", date);
                }
                break;
            case '4':
                printf("Exiting Digital Diary.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != '4');
    return 0;
}
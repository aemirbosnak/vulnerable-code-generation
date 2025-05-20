//FormAI DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 1000    // Maximum number of entries in the diary

struct DiaryEntry {
    char date[11];
    char time[6];
    char entry[200];
};

typedef struct DiaryEntry DiaryEntry;

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;
    char temp[200];

    printf("Welcome to your digital diary!\n");

    // Loop until user chooses to exit
    while (1) {
        printf("MENU\n");
        printf("1. Add new entry\n");
        printf("2. View all entries\n");
        printf("3. Search for entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add new entry
                printf("Enter today's date (DD-MM-YYYY): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter the current time (HH:MM): ");
                scanf("%s", entries[num_entries].time);

                // Get entry text
                printf("Enter your entry: ");
                getchar();                      // Clear input buffer
                fgets(temp, sizeof(temp), stdin);
                strncpy(entries[num_entries].entry, temp, sizeof(entries[num_entries].entry));

                // Increment the number of entries
                num_entries++;

                printf("\nEntry added successfully!\n\n");

                break;

            case 2:
                // View all entries
                if (num_entries == 0) {
                    printf("There are no entries to display.\n\n");
                } else {
                    printf("Date\t\tTime\t\tDiary Entry\n");
                    for (int i = 0; i < num_entries; i++) {
                        printf("%s\t%s\t%s", entries[i].date, entries[i].time, entries[i].entry);
                    }
                    printf("\n");
                }

                break;

            case 3:
                // Search for entries
                printf("Enter the date to search for (DD-MM-YYYY): ");
                scanf("%s", temp);

                // Loop through each entry and compare the date
                for (int i = 0; i < num_entries; i++) {
                    if (strcmp(entries[i].date, temp) == 0) {
                        printf("\nDate: %s\tTime: %s\n%s\n\n", entries[i].date, entries[i].time, entries[i].entry);
                    }
                }

                break;

            case 4:
                // Exit the program
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }
}
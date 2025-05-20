//FormAI DATASET v1.0 Category: Digital Diary ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char entry[500];
} DiaryEntry;

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;

    do {
        printf("\n1. Add an entry");
        printf("\n2. View all entries");
        printf("\n3. Search entries by date");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (num_entries >= MAX_ENTRIES) {
                    printf("\nDiary is full!");
                    break;
                }

                DiaryEntry new_entry;
                printf("\nEnter the date (dd/mm/yyyy): ");
                scanf("%s", new_entry.date);
                printf("\nEnter the entry: ");
                fflush(stdin);
                fgets(new_entry.entry, 500, stdin);

                entries[num_entries] = new_entry;
                num_entries++;

                printf("\nEntry added successfully");
                break;
            }

            case 2: {
                if (num_entries == 0) {
                    printf("\nNo entries found!");
                    break;
                }

                printf("\nAll entries:\n");

                for (int i = 0; i < num_entries; i++) {
                    printf("\nEntry #%d", i+1);
                    printf("\nDate: %s", entries[i].date);
                    printf("\n%s", entries[i].entry);
                }

                break;
            }

            case 3: {
                if (num_entries == 0) {
                    printf("\nNo entries found!");
                    break;
                }

                char search_date[20];
                printf("\nEnter the date to search (dd/mm/yyyy): ");
                scanf("%s", search_date);

                int found_flag = 0;

                for (int i = 0; i < num_entries; i++) {
                    if (strcmp(entries[i].date, search_date) == 0) {
                        found_flag = 1;
                        printf("\nMatch found at entry #%d", i+1);
                        printf("\nDate: %s", entries[i].date);
                        printf("\n%s", entries[i].entry);
                    }
                }

                if (!found_flag) {
                    printf("\nNo matching entries found!");
                }

                break;
            }

            case 4:
                printf("\nExiting program..");
                break;

            default:
                printf("\nInvalid choice!");
                break;
        }
    } while (choice != 4);

    return 0;
}
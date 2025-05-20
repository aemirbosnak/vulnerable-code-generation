//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

// Struct to hold entry information
typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

// Function to compare two entries by date
int compare_entries(const void* a, const void* b) {
    entry_t* entryA = (entry_t*)a;
    entry_t* entryB = (entry_t*)b;

    return strcmp(entryA->date, entryB->date);
}

// Function to print all entries in the diary
void print_entries(entry_t* entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    // Initialize diary with empty entries
    entry_t entries[MAX_ENTRIES] = {{0}};
    int num_entries = 0;

    // Main loop
    while (1) {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. Print entries\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Add entry
            if (num_entries >= MAX_ENTRIES) {
                printf("Diary is full.\n");
            } else {
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", entries[num_entries].date);

                printf("Enter entry:\n");
                fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
                entries[num_entries].entry[strcspn(entries[num_entries].entry, "\n")] = '\0';

                num_entries++;
            }
            break;

        case 2:
            // Print entries
            if (num_entries == 0) {
                printf("Diary is empty.\n");
            } else {
                qsort(entries, num_entries, sizeof(entry_t), compare_entries);
                print_entries(entries, num_entries);
            }
            break;

        case 3:
            // Exit
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
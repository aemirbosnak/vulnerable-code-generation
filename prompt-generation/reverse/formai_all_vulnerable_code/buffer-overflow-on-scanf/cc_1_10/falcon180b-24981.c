//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", entries[num_entries].date);

    printf("Enter time (HH:MM:SS): ");
    scanf("%s", entries[num_entries].time);

    printf("Enter your entry:\n");
    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
    num_entries++;
}

void view_entries() {
    int i;
    printf("Viewing %d entries:\n", num_entries);
    for (i = 0; i < num_entries; i++) {
        printf("%s %s %s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LENGTH];
    int i, found = 0;

    printf("Enter keyword to search: ");
    scanf("%s", keyword);
    tolower(keyword);

    for (i = 0; i < num_entries; i++) {
        if (strstr(tolower(entries[i].entry), keyword)) {
            printf("%s %s %s\n", entries[i].date, entries[i].time, entries[i].entry);
            found = 1;
        }
    }

    if (!found) {
        printf("No entries found.\n");
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to Digital Diary!\n");
    printf("Press 1 to add an entry.\n");
    printf("Press 2 to view all entries.\n");
    printf("Press 3 to search for a specific entry.\n");
    printf("Press 0 to exit.\n");

    int choice;
    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entries();
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
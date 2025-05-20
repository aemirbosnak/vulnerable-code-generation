//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[11];
    char time[9];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *time, char *entry) {
    strncpy(entries[num_entries].date, date, 11);
    strncpy(entries[num_entries].time, time, 9);
    strncpy(entries[num_entries].entry, entry, MAX_ENTRY_LENGTH);
    num_entries++;
}

void display_entries() {
    printf("Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

void search_entries(char *keyword) {
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));
    char date[11];
    char time[9];
    char entry[MAX_ENTRY_LENGTH];
    int choice;
    bool quit = false;

    while (!quit) {
        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Search entries\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter time (HH:MM:SS): ");
                scanf("%s", time);
                printf("Enter entry:\n");
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                entry[strcspn(entry, "\n")] = '\0'; // Remove newline character
                add_entry(date, time, entry);
                break;
            case 2:
                display_entries();
                break;
            case 3:
                printf("Enter keyword to search: ");
                scanf("%s", entry);
                search_entries(entry);
                break;
            case 4:
                quit = true;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
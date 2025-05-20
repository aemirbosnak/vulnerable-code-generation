//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

void add_entry(Entry entries[], int num_entries, char* new_date, char* new_entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }
    strcpy(entries[num_entries].date, new_date);
    strcpy(entries[num_entries].entry, new_entry);
    num_entries++;
}

void display_entries(Entry entries[], int num_entries) {
    printf("Date\t\t\tEntry\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t\t\t%s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char new_date[20];
    char new_entry[MAX_ENTRY_LENGTH];

    time_t now = time(NULL);
    strftime(new_date, sizeof(new_date), "%Y-%m-%d", localtime(&now));

    while (1) {
        printf("1. Add entry\n2. Display entries\n3. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", new_date);
                printf("Enter entry: ");
                scanf("%s", new_entry);
                add_entry(entries, num_entries, new_date, new_entry);
                break;
            case 2:
                display_entries(entries, num_entries);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
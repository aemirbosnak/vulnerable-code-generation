//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", entries[num_entries].date);

    printf("Enter time (HH:MM:SS): ");
    scanf("%s", entries[num_entries].time);

    printf("Enter your diary entry:\n");
    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);

    num_entries++;
}

void view_entries() {
    printf("Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

void search_entries() {
    char search_date[20], search_time[20];

    printf("Enter date to search (YYYY-MM-DD): ");
    scanf("%s", search_date);

    printf("Enter time to search (HH:MM:SS): ");
    scanf("%s", search_time);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].date, search_date) == 0 && strcmp(entries[i].time, search_time) == 0) {
            printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to your Digital Diary!\n");

    while (1) {
        printf("\n1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
        int choice;
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
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

// Struct to hold entry information
typedef struct {
    char date[20];
    char time[10];
    char entry[500];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

// Function to add a new entry
void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(entries[num_entries].date, 20, "%Y-%m-%d", t);
    strftime(entries[num_entries].time, 10, "%H:%M:%S", t);

    printf("Enter your entry:\n");
    fgets(entries[num_entries].entry, 500, stdin);

    num_entries++;
    printf("Entry added.\n");
}

// Function to display all entries
void display_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n%s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

// Function to search for entries by date
void search_by_date() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    char search_date[20];
    printf("Enter date to search (YYYY-MM-DD): ");
    scanf("%s", search_date);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].date, search_date) == 0) {
            printf("%s - %s\n%s\n", entries[i].date, entries[i].time, entries[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Digital Diary!\n");

    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Search by date\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            display_entries();
            break;
        case 3:
            search_by_date();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
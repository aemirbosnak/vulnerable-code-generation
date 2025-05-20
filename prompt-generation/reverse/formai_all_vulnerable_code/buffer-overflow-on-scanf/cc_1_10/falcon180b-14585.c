//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_SIZE 1000

typedef struct {
    char date[11];
    char time[9];
    char entry[MAX_ENTRY_SIZE];
} Entry;

Entry entries[MAX_ENTRIES];
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

    printf("Enter diary entry:\n");
    fgets(entries[num_entries].entry, MAX_ENTRY_SIZE, stdin);

    num_entries++;
    printf("Entry added.\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Diary entries:\n");
    printf("Date\tTime\tEntry\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%s", entries[i].date, entries[i].time, entries[i].entry);
    }
}

void search_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    char keyword[MAX_ENTRY_SIZE];
    printf("Enter keyword to search: ");
    fgets(keyword, MAX_ENTRY_SIZE, stdin);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)) {
            printf("Date\tTime\tEntry\n");
            printf("%s\t%s\t%s", entries[i].date, entries[i].time, entries[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to Digital Diary!\n");
    printf("Enter 1 to add an entry.\n");
    printf("Enter 2 to view all entries.\n");
    printf("Enter 3 to search for an entry.\n");

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
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
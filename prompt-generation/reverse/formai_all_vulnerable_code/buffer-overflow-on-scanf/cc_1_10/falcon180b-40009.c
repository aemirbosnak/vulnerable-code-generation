//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[10];
    char time[10];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int num_entries = 0;
Entry entries[MAX_ENTRIES];

void add_entry() {
    char date[10];
    char time[10];
    char entry[MAX_ENTRY_LENGTH];

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", date);

    printf("Enter the time (HH:MM:SS): ");
    scanf("%s", time);

    printf("Enter your entry: ");
    scanf("%s", entry);

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].time, time);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void view_entries() {
    printf("Date\tTime\tEntry\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LENGTH];

    printf("Enter the keyword to search for: ");
    scanf("%s", keyword);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)) {
            printf("%s\t%s\t%s\n", entries[i].date, entries[i].time, entries[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));
    int choice;

    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}
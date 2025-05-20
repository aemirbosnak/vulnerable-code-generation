//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_SIZE];
} Entry;

void add_entry(Entry entries[], int num_entries) {
    char date[20];
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", date);
    time_t t;
    struct tm *tm;
    strptime(date, "%Y-%m-%d", &tm);
    t = mktime(tm);
    printf("Enter your diary entry:\n");
    scanf("%[^\n]", entries[num_entries].entry);
    strftime(entries[num_entries].date, 20, "%Y-%m-%d", tm);
    num_entries++;
}

void view_entries(Entry entries[], int num_entries) {
    printf("Diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("1. Add entry\n2. View entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_entry(entries, num_entries);
            break;
        case 2:
            view_entries(entries, num_entries);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
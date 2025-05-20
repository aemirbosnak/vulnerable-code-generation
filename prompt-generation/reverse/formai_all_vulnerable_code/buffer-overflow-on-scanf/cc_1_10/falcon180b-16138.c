//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int entry_count = 0;
Entry entries[MAX_ENTRIES];

void add_entry() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(entries[entry_count].date, 20, "%Y-%m-%d %H:%M:%S", t);
    printf("Enter your diary entry: ");
    fgets(entries[entry_count].entry, MAX_ENTRY_LENGTH, stdin);
    entry_count++;
}

void view_entries() {
    printf("Diary Entries:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    srand(time(NULL));
    int choice;
    while (1) {
        printf("Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Exit\n");
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
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
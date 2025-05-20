//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char time[10];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(entries[numEntries].date, 20, "%Y-%m-%d", t);
    strftime(entries[numEntries].time, 10, "%H:%M:%S", t);

    printf("Enter your diary entry:\n");
    scanf("%[^\n]", entries[numEntries].entry);

    numEntries++;
}

void viewEntries() {
    printf("Diary Entries:\n");
    printf("---------------------------------\n");
    printf("Date        Time        Entry\n");
    printf("---------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%s %s %s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

int main() {
    printf("Welcome to the Digital Diary!\n");
    printf("---------------------------------\n");

    while (1) {
        printf("\n1. Add an entry\n2. View entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEntry();
            break;
        case 2:
            viewEntries();
            break;
        case 3:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
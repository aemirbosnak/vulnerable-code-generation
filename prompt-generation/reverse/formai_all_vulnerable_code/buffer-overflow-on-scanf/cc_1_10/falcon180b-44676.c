//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    num_entries++;
    if (num_entries > MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        exit(1);
    }
    strcpy(entries[num_entries-1].date, date);
    strcpy(entries[num_entries-1].entry, entry);
}

void view_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries(char* keyword) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
    char keyword[MAX_ENTRY_LENGTH];
    int choice;

    time_t now = time(NULL);
    strftime(date, 20, "%Y-%m-%d", localtime(&now));

    do {
        printf("Welcome to the Digital Diary!\n");
        printf("Current date: %s\n", date);
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter entry:\n");
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                add_entry(date, entry);
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("Enter keyword to search:\n");
                fgets(keyword, MAX_ENTRY_LENGTH, stdin);
                search_entries(keyword);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}
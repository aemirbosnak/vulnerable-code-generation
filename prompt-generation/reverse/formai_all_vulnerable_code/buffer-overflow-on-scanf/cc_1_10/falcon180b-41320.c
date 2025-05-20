//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void print_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
    int choice;

    time_t now = time(NULL);
    strftime(date, 20, "%Y-%m-%d", localtime(&now));

    while (1) {
        printf("Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. Print Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter your entry:\n");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            add_entry(date, entry);
            printf("Entry added successfully.\n");
            break;
        case 2:
            print_entries();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
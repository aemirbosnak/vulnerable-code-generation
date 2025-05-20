//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strncpy(entries[num_entries].date, date, 19);
    strncpy(entries[num_entries].entry, entry, MAX_ENTRY_LENGTH - 1);
    entries[num_entries].entry[MAX_ENTRY_LENGTH - 1] = '\0';
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char input[MAX_ENTRY_LENGTH];
    char date[20];
    int choice;

    do {
        printf("1. Add Entry\n2. Print Entries\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter entry: ");
                fgets(input, MAX_ENTRY_LENGTH, stdin);
                input[strcspn(input, "\n")] = '\0';
                add_entry(date, input);
                break;
            case 2:
                print_entries();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}
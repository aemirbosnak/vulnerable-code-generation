//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

void print_entry(Entry entry) {
    printf("%s: %s\n", entry.date, entry.entry);
}

void add_entry(Entry* entries, int num_entries, char* date, char* entry) {
    if (num_entries >= MAX_ENTRY_LENGTH) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

int main() {
    int choice;
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
    Entry entries[MAX_ENTRY_LENGTH];
    int num_entries = 0;

    printf("Welcome to the Digital Diary!\n\n");

    while (1) {
        printf("1. Add entry\n2. View entries\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter entry:\n");
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                entry[strcspn(entry, "\n")] = '\0'; // Remove newline character
                add_entry(entries, num_entries, date, entry);
                break;
            case 2:
                for (int i = 0; i < num_entries; i++) {
                    print_entry(entries[i]);
                }
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

void add_entry(Entry* entries, int num_entries, char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void display_entries(Entry* entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    char username[20];
    printf("Enter your name: ");
    scanf("%s", username);

    char* input;
    while (1) {
        printf("\n%s's Digital Diary\n", username);
        printf("1. Add new entry\n");
        printf("2. Display entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", input);

        switch (input[0]) {
            case '1':
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", input);
                printf("Enter entry: ");
                scanf("%s", input);
                add_entry(entries, num_entries, input, input);
                printf("Entry added successfully.\n");
                break;
            case '2':
                display_entries(entries, num_entries);
                break;
            case '3':
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
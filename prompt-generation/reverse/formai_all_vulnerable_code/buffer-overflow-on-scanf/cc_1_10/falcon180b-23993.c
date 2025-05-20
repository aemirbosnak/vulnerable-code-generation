//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} entry;

void create_index(entry entries[], int num_entries) {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Creating index for entry %s...\n", entries[i].name);
        // Code to create index for the given entry
    }
}

void search_index(entry entries[], int num_entries, char *search_value) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].value, search_value) == 0) {
            printf("Found entry: %s -> %s\n", entries[i].name, entries[i].value);
        }
    }
}

int main() {
    entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES) {
        printf("Enter a name (up to %d characters): ", MAX_NAME_LENGTH - 1);
        scanf("%s", entries[num_entries].name);

        printf("Enter a value (up to %d characters): ", MAX_VALUE_LENGTH - 1);
        scanf("%s", entries[num_entries].value);

        num_entries++;
    }

    char search_value[MAX_VALUE_LENGTH];
    printf("Enter a value to search for: ");
    scanf("%s", search_value);

    create_index(entries, num_entries);
    search_index(entries, num_entries, search_value);

    return 0;
}
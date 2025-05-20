//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_SIZE 50
#define MAX_VALUE_SIZE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    char value[MAX_VALUE_SIZE];
    int index;
} Entry;

int compare_entries(const void *a, const void *b) {
    const Entry *entry_a = (const Entry *)a;
    const Entry *entry_b = (const Entry *)b;

    return strcmp(entry_a->name, entry_b->name);
}

int main() {
    int num_entries = 0;
    Entry entries[MAX_ENTRIES];

    while (num_entries < MAX_ENTRIES) {
        printf("Enter a name (or 'done' to finish): ");
        fflush(stdout);
        char name[MAX_NAME_SIZE];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter a value: ");
        fflush(stdout);
        char value[MAX_VALUE_SIZE];
        scanf("%s", value);

        strcpy(entries[num_entries].name, name);
        strcpy(entries[num_entries].value, value);
        entries[num_entries].index = num_entries;
        num_entries++;
    }

    qsort(entries, num_entries, sizeof(Entry), compare_entries);

    printf("Sorted entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].value);
    }

    return 0;
}
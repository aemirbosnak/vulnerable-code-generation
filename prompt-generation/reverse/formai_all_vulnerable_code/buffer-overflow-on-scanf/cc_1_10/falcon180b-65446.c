//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct entry {
    char *key;
    int value;
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries;

int compare_entries(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void print_entries() {
    qsort(entries, num_entries, sizeof(entry_t), compare_entries);
    for (int i = 0; i < num_entries; i++) {
        printf("%s -> %d\n", entries[i].key, entries[i].value);
    }
}

int main() {
    num_entries = 0;

    char key[50];
    int value;

    while (1) {
        printf("Enter a key (or leave blank to exit): ");
        scanf("%s", key);

        if (key[0] == '\0') {
            break;
        }

        printf("Enter a value: ");
        scanf("%d", &value);

        if (num_entries >= MAX_ENTRIES) {
            printf("Database is full.\n");
            continue;
        }

        entries[num_entries].key = strdup(key);
        entries[num_entries].value = value;
        num_entries++;
    }

    print_entries();

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10000
#define MAX_ENTRY_SIZE 100

typedef struct {
    char *key;
    int value;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries;

int compare_entries(const void *a, const void *b) {
    Entry *entry_a = (Entry *)a;
    Entry *entry_b = (Entry *)b;

    return strcmp(entry_a->key, entry_b->key);
}

void load_database() {
    FILE *file = fopen("database.txt", "r");

    if (file == NULL) {
        printf("Error loading database.\n");
        exit(1);
    }

    char line[MAX_ENTRY_SIZE];
    while (fgets(line, MAX_ENTRY_SIZE, file)!= NULL) {
        char *key = line;
        int value = atoi(strchr(line, ':') + 1);

        if (num_entries >= MAX_ENTRIES) {
            printf("Database is full.\n");
            exit(1);
        }

        entries[num_entries].key = strdup(key);
        entries[num_entries].value = value;
        num_entries++;
    }

    fclose(file);
}

void search_database(const char *key) {
    qsort(entries, num_entries, sizeof(Entry), compare_entries);

    int left = 0;
    int right = num_entries - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int cmp = strcmp(key, entries[mid].key);
        if (cmp == 0) {
            printf("Found entry: %s -> %d\n", key, entries[mid].value);
            return;
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    load_database();

    char key[MAX_ENTRY_SIZE];
    while (1) {
        printf("Enter search key: ");
        fgets(key, MAX_ENTRY_SIZE, stdin);

        search_database(key);
    }

    return 0;
}
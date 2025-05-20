//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_KEY_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
    int index;
} entry;

int compare_keys(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    entry *entries = NULL;
    int num_entries = 0;
    char input[MAX_VALUE_LEN] = {0};
    char key[MAX_KEY_LEN] = {0};
    char value[MAX_VALUE_LEN] = {0};
    char *token = NULL;

    printf("Enter key-value pairs (enter 'quit' to exit):\n");
    while (fgets(input, MAX_VALUE_LEN, stdin)) {
        token = strtok(input, " ");
        if (token == NULL) {
            continue;
        }
        if (strcmp(token, "quit") == 0) {
            break;
        }
        strcpy(key, token);
        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Invalid input.\n");
            continue;
        }
        strcpy(value, token);
        if (num_entries >= MAX_ENTRIES) {
            printf("Maximum number of entries reached.\n");
            continue;
        }
        entries = realloc(entries, sizeof(entry) * (num_entries + 1));
        if (entries == NULL) {
            printf("Memory error.\n");
            exit(1);
        }
        strcpy(entries[num_entries].key, key);
        strcpy(entries[num_entries].value, value);
        entries[num_entries].index = num_entries;
        num_entries++;
    }

    qsort(entries, num_entries, sizeof(entry), compare_keys);

    printf("Sorted entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s -> %s\n", entries[i].key, entries[i].value);
    }

    free(entries);
    return 0;
}
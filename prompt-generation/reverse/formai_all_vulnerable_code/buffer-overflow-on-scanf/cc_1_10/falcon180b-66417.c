//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 200
#define MAX_NUM_ENTRIES 1000

struct entry {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
};

struct index {
    struct entry entries[MAX_NUM_ENTRIES];
    int num_entries;
};

void create_index(struct index *index) {
    index->num_entries = 0;
}

void add_entry(struct index *index, char *key, char *value) {
    if (index->num_entries >= MAX_NUM_ENTRIES) {
        printf("Error: Index is full.\n");
        return;
    }

    struct entry entry;
    strcpy(entry.key, key);
    strcpy(entry.value, value);

    index->entries[index->num_entries++] = entry;
}

void search_index(struct index *index, char *key) {
    int i;
    for (i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            printf("%s: %s\n", key, index->entries[i].value);
            return;
        }
    }

    printf("Not found.\n");
}

int main() {
    struct index index;
    create_index(&index);

    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];

    while (1) {
        printf("Enter key (or 'q' to quit): ");
        scanf("%s", key);

        if (strcmp(key, "q") == 0) {
            break;
        }

        printf("Enter value: ");
        scanf("%s", value);

        add_entry(&index, key, value);
    }

    char search_key[MAX_KEY_LENGTH];
    while (1) {
        printf("Enter key to search (or 'q' to quit): ");
        scanf("%s", search_key);

        if (strcmp(search_key, "q") == 0) {
            break;
        }

        search_index(&index, search_key);
    }

    return 0;
}
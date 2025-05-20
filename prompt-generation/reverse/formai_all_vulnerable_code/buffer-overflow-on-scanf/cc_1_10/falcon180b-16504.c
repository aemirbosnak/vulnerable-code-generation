//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 500
#define MAX_INDEX_ENTRIES 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} entry_t;

typedef struct {
    entry_t entries[MAX_INDEX_ENTRIES];
    int num_entries;
} index_t;

void index_init(index_t* index) {
    index->num_entries = 0;
}

int index_add(index_t* index, char* key, char* value) {
    if (index->num_entries >= MAX_INDEX_ENTRIES) {
        printf("Error: index is full\n");
        return -1;
    }

    entry_t entry;
    strcpy(entry.key, key);
    strcpy(entry.value, value);

    index->entries[index->num_entries++] = entry;

    return 0;
}

int index_search(index_t* index, char* key, char* value) {
    for (int i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            strcpy(value, index->entries[i].value);
            return 0;
        }
    }

    printf("Error: key not found\n");
    return -1;
}

int main() {
    index_t index;
    index_init(&index);

    int choice;
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];

    do {
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter value: ");
            scanf("%s", value);
            index_add(&index, key, value);
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%s", key);
            if (index_search(&index, key, value) == 0) {
                printf("Value: %s\n", value);
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}
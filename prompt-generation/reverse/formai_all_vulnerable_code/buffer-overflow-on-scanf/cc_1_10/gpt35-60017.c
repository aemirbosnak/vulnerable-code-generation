//FormAI DATASET v1.0 Category: Database Indexing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_DATA_LENGTH 1024
#define MAX_ENTRIES 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char data[MAX_DATA_LENGTH];
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
} Index;

void addEntry(Index* index, char* key, char* data) {
    if (index->count >= MAX_ENTRIES) {
        printf("Index full, cannot add any more entries\n");
        return;
    }

    Entry* entry = &(index->entries[index->count]);
    strncpy(entry->key, key, MAX_KEY_LENGTH);
    strncpy(entry->data, data, MAX_DATA_LENGTH);
    index->count++;

    printf("Added entry with key '%s' and data '%s'\n", key, data);
}

Entry* findEntry(Index* index, char* key) {
    for (int i = 0; i < index->count; i++) {
        Entry* entry = &(index->entries[i]);
        if (strncmp(entry->key, key, MAX_KEY_LENGTH) == 0) {
            printf("Found entry with key '%s' and data '%s'\n", entry->key, entry->data);
            return entry;
        }
    }
    printf("No entry found with key '%s'\n", key);
    return NULL;
}

int main() {
    Index index = {0};
    char key[MAX_KEY_LENGTH], data[MAX_DATA_LENGTH];

    while (1) {
        printf("\nEnter command (add/find/quit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter data: ");
            scanf("%s", data);
            addEntry(&index, key, data);
        } else if (strcmp(command, "find") == 0) {
            printf("Enter key: ");
            scanf("%s", key);
            findEntry(&index, key);
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid command. Please enter 'add', 'find', or 'quit'\n");
        }
    }

    return 0;
}
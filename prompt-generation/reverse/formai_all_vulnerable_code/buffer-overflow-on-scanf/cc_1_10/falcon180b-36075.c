//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_KEY_LENGTH 20
#define MAX_VALUE_LENGTH 50

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries;

void add_entry(char* key, char* value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].key, key);
    strcpy(entries[num_entries].value, value);
    num_entries++;

    printf("Entry added: %s = %s\n", key, value);
}

void search_entry(char* key) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            printf("Value for %s: %s\n", key, entries[i].value);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    char command[50];

    printf("Welcome to the C Database Indexing System!\n");

    while (1) {
        printf("Enter command (add/search/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char key[MAX_KEY_LENGTH];
            char value[MAX_VALUE_LENGTH];

            printf("Enter key: ");
            scanf("%s", key);

            printf("Enter value: ");
            scanf("%s", value);

            add_entry(key, value);
        } else if (strcmp(command, "search") == 0) {
            char key[MAX_KEY_LENGTH];

            printf("Enter key: ");
            scanf("%s", key);

            search_entry(key);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
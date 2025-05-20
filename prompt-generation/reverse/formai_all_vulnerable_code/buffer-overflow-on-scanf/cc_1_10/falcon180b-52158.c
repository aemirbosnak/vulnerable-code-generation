//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* key, char* value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Database is full.\n");
        exit(1);
    }

    strcpy(entries[num_entries].key, key);
    strcpy(entries[num_entries].value, value);
    num_entries++;
}

void search_entry(char* key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            printf("Value: %s\n", entries[i].value);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    char command[MAX_KEY_LEN];
    while (1) {
        printf("Enter command (add/search/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char key[MAX_KEY_LEN], value[MAX_VALUE_LEN];
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter value: ");
            scanf("%s", value);
            add_entry(key, value);
        } else if (strcmp(command, "search") == 0) {
            char key[MAX_KEY_LEN];
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
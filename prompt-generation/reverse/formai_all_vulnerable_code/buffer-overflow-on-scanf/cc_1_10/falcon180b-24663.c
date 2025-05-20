//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MIN_KEY_LENGTH 3
#define MAX_KEY_LENGTH 50

typedef struct entry {
    char key[MAX_KEY_LENGTH];
    int value;
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* key, int value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: database is full\n");
        return;
    }

    strncpy(entries[num_entries].key, key, MAX_KEY_LENGTH);
    entries[num_entries].value = value;
    num_entries++;
}

int search_entry(char* key) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            return entries[i].value;
        }
    }

    return -1;
}

int main() {
    char key[MAX_KEY_LENGTH];
    int value;

    printf("Welcome to the C Database Indexing System\n");

    while (1) {
        printf("Enter a command (add, search, quit): ");
        scanf("%s", key);

        if (strcmp(key, "add") == 0) {
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter value: ");
            scanf("%d", &value);

            if (strlen(key) < MIN_KEY_LENGTH || strlen(key) > MAX_KEY_LENGTH) {
                printf("Error: invalid key length\n");
            } else {
                add_entry(key, value);
            }
        } else if (strcmp(key, "search") == 0) {
            printf("Enter key: ");
            scanf("%s", key);

            value = search_entry(key);

            if (value == -1) {
                printf("Key not found\n");
            } else {
                printf("Value: %d\n", value);
            }
        } else if (strcmp(key, "quit") == 0) {
            break;
        } else {
            printf("Error: invalid command\n");
        }
    }

    return 0;
}
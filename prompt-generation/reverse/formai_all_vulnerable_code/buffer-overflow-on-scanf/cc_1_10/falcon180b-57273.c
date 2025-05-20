//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char *key;
    int value;
} entry_t;

entry_t database[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *key, int value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Database is full.\n");
        return;
    }
    entry_t *new_entry = &database[num_entries];
    new_entry->key = strdup(key);
    new_entry->value = value;
    num_entries++;
}

void remove_entry(char *key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(database[i].key, key) == 0) {
            free(database[i].key);
            num_entries--;
            return;
        }
    }
    printf("Error: Entry not found.\n");
}

void search_entry(char *key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(database[i].key, key) == 0) {
            printf("Key: %s\nValue: %d\n", database[i].key, database[i].value);
            return;
        }
    }
    printf("Error: Entry not found.\n");
}

int main() {
    char choice;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add entry\n2. Remove entry\n3. Search entry\n4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1': {
                char key[100];
                int value;
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%d", &value);
                add_entry(key, value);
                break;
            }
            case '2': {
                char key[100];
                printf("Enter key: ");
                scanf("%s", key);
                remove_entry(key);
                break;
            }
            case '3': {
                char key[100];
                printf("Enter key: ");
                scanf("%s", key);
                search_entry(key);
                break;
            }
            case '4': {
                exit(0);
            }
            default: {
                printf("Error: Invalid choice.\n");
            }
        }
    }
    return 0;
}
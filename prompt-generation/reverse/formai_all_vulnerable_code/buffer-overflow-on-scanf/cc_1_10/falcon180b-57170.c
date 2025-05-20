//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Entry;

int num_entries = 0;
Entry entries[MAX_ENTRIES];

void add_entry(char* key, char* value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].key, key);
    strcpy(entries[num_entries].value, value);

    num_entries++;
}

void search_entries(char* key) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            printf("Key: %s\nValue: %s\n", entries[i].key, entries[i].value);
        }
    }
}

int main() {
    int choice, key_len, value_len;
    char key[MAX_KEY_LEN], value[MAX_VALUE_LEN];

    printf("Welcome to the C Database Indexing System!\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%s", value);

                key_len = strlen(key);
                value_len = strlen(value);

                if (key_len > MAX_KEY_LEN || value_len > MAX_VALUE_LEN) {
                    printf("Error: Key or value is too long.\n");
                } else {
                    add_entry(key, value);
                }

                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%s", key);

                search_entries(key);

                break;

            case 3:
                exit(0);

            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}
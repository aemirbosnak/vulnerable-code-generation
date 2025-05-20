//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 1000
#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct entry {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Entry;

Entry database[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* key, char* value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("ERROR: Database is full.\n");
        return;
    }

    strncpy(database[num_entries].key, key, MAX_KEY_LENGTH);
    strncpy(database[num_entries].value, value, MAX_VALUE_LENGTH);

    num_entries++;
}

void search_entry(char* key) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(database[i].key, key) == 0) {
            printf("Key: %s\nValue: %s\n", database[i].key, database[i].value);
            return;
        }
    }

    printf("Key not found.\n");
}

int main() {
    int choice, i;

    do {
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", database[num_entries].key);
                printf("Enter value: ");
                scanf("%s", database[num_entries].value);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%s", database[num_entries].key);
                search_entry(database[num_entries].key);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}
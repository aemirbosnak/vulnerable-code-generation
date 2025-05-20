//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Entry;

Entry database[MAX_ENTRIES];
int num_entries;

void create_database() {
    num_entries = 0;
}

void add_entry(char* key, char* value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Database is full.\n");
        return;
    }

    strcpy(database[num_entries].key, key);
    strcpy(database[num_entries].value, value);

    num_entries++;
}

void delete_entry(char* key) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(database[i].key, key) == 0) {
            memset(&database[i], 0, sizeof(Entry));
            num_entries--;
            printf("Entry deleted successfully.\n");
            return;
        }
    }

    printf("Error: Entry not found.\n");
}

void search_entry(char* key) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(database[i].key, key) == 0) {
            printf("Key: %s\nValue: %s\n", database[i].key, database[i].value);
            return;
        }
    }

    printf("Error: Entry not found.\n");
}

int main() {
    create_database();

    while (1) {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char key[MAX_KEY_LENGTH];
                char value[MAX_VALUE_LENGTH];
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%s", value);
                add_entry(key, value);
                break;
            }
            case 2: {
                char key[MAX_KEY_LENGTH];
                printf("Enter key: ");
                scanf("%s", key);
                delete_entry(key);
                break;
            }
            case 3: {
                char key[MAX_KEY_LENGTH];
                printf("Enter key: ");
                scanf("%s", key);
                search_entry(key);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Error: Invalid choice.\n");
            }
        }
    }

    return 0;
}
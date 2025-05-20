//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct entry {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Entry;

Entry database[MAX_ENTRIES];
int num_entries;

void add_entry(char* key, char* value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Database is full.\n");
        return;
    }

    strcpy(database[num_entries].key, key);
    strcpy(database[num_entries].value, value);

    num_entries++;
}

void search_entry(char* key) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(database[i].key, key) == 0) {
            printf("Value for key '%s': %s\n", key, database[i].value);
            return;
        }
    }

    printf("No entry found for key '%s'.\n", key);
}

int main() {
    char command[MAX_KEY_LENGTH];

    printf("Welcome to the Sherlock Holmes Database System.\n");
    printf("Please enter commands in the format: add key value\n");
    printf("or search key\n");

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char key[MAX_KEY_LENGTH], value[MAX_VALUE_LENGTH];
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
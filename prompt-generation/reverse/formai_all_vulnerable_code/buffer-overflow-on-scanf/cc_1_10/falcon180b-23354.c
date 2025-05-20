//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000 // maximum number of entries in the database
#define MAX_KEY_SIZE 50 // maximum size of the key
#define MAX_VALUE_SIZE 100 // maximum size of the value

typedef struct {
    char key[MAX_KEY_SIZE]; // key
    char value[MAX_VALUE_SIZE]; // value
} entry;

entry database[MAX_ENTRIES]; // the database
int num_entries = 0; // number of entries in the database

void add_entry(char* key, char* value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: database is full\n");
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
            printf("%s: %s\n", key, database[i].value);
            return;
        }
    }
    printf("Entry not found\n");
}

void delete_entry(char* key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(database[i].key, key) == 0) {
            strcpy(database[i].key, "");
            strcpy(database[i].value, "");
            num_entries--;
            return;
        }
    }
    printf("Entry not found\n");
}

int main() {
    char command[100];
    while (1) {
        printf("Enter command (add/search/delete): ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            char key[MAX_KEY_SIZE], value[MAX_VALUE_SIZE];
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter value: ");
            scanf("%s", value);
            add_entry(key, value);
        } else if (strcmp(command, "search") == 0) {
            char key[MAX_KEY_SIZE];
            printf("Enter key: ");
            scanf("%s", key);
            search_entry(key);
        } else if (strcmp(command, "delete") == 0) {
            char key[MAX_KEY_SIZE];
            printf("Enter key: ");
            scanf("%s", key);
            delete_entry(key);
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}
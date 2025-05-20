//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 200
#define MAX_INDEX_LEN 50
#define MAX_TABLE_SIZE 1000

struct index {
    char key[MAX_KEY_LEN];
    int value;
};

struct table {
    struct index *index;
    char *value;
};

void create_table(struct table *table) {
    table->index = malloc(MAX_TABLE_SIZE * sizeof(struct index));
    memset(table->index, 0, MAX_TABLE_SIZE * sizeof(struct index));
}

void add_entry(struct table *table, char *key, char *value) {
    int index = hash(key);
    struct index *entry = &(table->index[index]);
    strcpy(entry->key, key);
    entry->value = strtol(value, NULL, 10);
}

int hash(char *key) {
    int sum = 0;
    int i = 0;
    while (key[i]!= '\0') {
        sum += key[i];
        i++;
    }
    return sum % MAX_TABLE_SIZE;
}

int search_table(struct table *table, char *key) {
    int index = hash(key);
    struct index *entry = &(table->index[index]);
    while (entry->key[0]!= '\0') {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry++;
    }
    return -1;
}

int main() {
    struct table table;
    create_table(&table);
    add_entry(&table, "apple", "10");
    add_entry(&table, "banana", "20");
    add_entry(&table, "cherry", "30");
    add_entry(&table, "date", "40");
    add_entry(&table, "elderberry", "50");
    add_entry(&table, "fig", "60");
    add_entry(&table, "grape", "70");
    add_entry(&table, "honeydew", "80");
    add_entry(&table, "kiwi", "90");

    int value = search_table(&table, "banana");
    printf("Value of banana: %d\n", value);

    return 0;
}
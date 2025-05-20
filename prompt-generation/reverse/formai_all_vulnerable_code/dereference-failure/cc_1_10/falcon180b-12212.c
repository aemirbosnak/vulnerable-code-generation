//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000
#define MAX_NUM_INDEXES 50
#define MAX_NUM_KEYS 100
#define MAX_NUM_VALUES 1000

typedef struct {
    char *key;
    int value_index;
} Index;

typedef struct {
    char *key;
    char *value;
} KeyValue;

static int num_indexes = 0;
static Index *indexes = NULL;
static int num_keys = 0;
static char *keys[MAX_NUM_KEYS];
static int num_values = 0;
static char *values[MAX_NUM_VALUES];

void add_index(char *key, int value_index) {
    if (num_indexes >= MAX_NUM_INDEXES) {
        printf("Error: Maximum number of indexes reached.\n");
        return;
    }
    Index *new_index = (Index *) malloc(sizeof(Index));
    new_index->key = strdup(key);
    new_index->value_index = value_index;
    indexes[num_indexes++] = *new_index;
}

void add_key(char *key) {
    if (num_keys >= MAX_NUM_KEYS) {
        printf("Error: Maximum number of keys reached.\n");
        return;
    }
    keys[num_keys++] = strdup(key);
}

void add_value(char *value) {
    if (num_values >= MAX_NUM_VALUES) {
        printf("Error: Maximum number of values reached.\n");
        return;
    }
    values[num_values++] = strdup(value);
}

int get_value_index(char *key) {
    for (int i = 0; i < num_indexes; i++) {
        if (strcmp(indexes[i].key, key) == 0) {
            return indexes[i].value_index;
        }
    }
    printf("Error: Key not found in index.\n");
    return -1;
}

int main() {
    add_index("name", 0);
    add_index("age", 1);
    add_key("John");
    add_key("Jane");
    add_value("25");
    add_value("30");
    int value_index = get_value_index("name");
    printf("Value index for name: %d\n", value_index);
    value_index = get_value_index("age");
    printf("Value index for age: %d\n", value_index);
    return 0;
}
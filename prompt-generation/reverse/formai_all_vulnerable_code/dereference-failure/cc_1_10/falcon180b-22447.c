//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000
#define MAX_NUM_KEYS 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} KeyValue;

int num_keys = 0;
KeyValue *keys = NULL;

void add_key(char *key, char *value) {
    if (num_keys >= MAX_NUM_KEYS) {
        printf("Error: maximum number of keys reached.\n");
        return;
    }

    KeyValue *new_keys = realloc(keys, sizeof(KeyValue) * (num_keys + 1));
    if (new_keys == NULL) {
        printf("Error: failed to allocate memory for new keys.\n");
        return;
    }

    keys = new_keys;

    strcpy(keys[num_keys].key, key);
    strcpy(keys[num_keys].value, value);

    num_keys++;
}

void search_keys(char *query) {
    int i;
    for (i = 0; i < num_keys; i++) {
        if (strcmp(keys[i].key, query) == 0) {
            printf("Key: %s\nValue: %s\n", keys[i].key, keys[i].value);
        }
    }
}

int main() {
    add_key("Name", "John");
    add_key("Age", "25");
    add_key("Gender", "Male");

    search_keys("Name");

    return 0;
}
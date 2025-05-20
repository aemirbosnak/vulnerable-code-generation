//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 50
#define MAX_VALUE_LEN 100
#define MAX_NUM_KEYS 100

struct key_value {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
};

struct key_value *key_value_list;
int num_keys;

void init() {
    key_value_list = (struct key_value *) malloc(MAX_NUM_KEYS * sizeof(struct key_value));
    num_keys = 0;
}

void add_key_value(char *key, char *value) {
    int i;
    for (i = 0; i < num_keys; i++) {
        if (strcmp(key_value_list[i].key, key) == 0) {
            strcpy(key_value_list[i].value, value);
            return;
        }
    }
    if (num_keys >= MAX_NUM_KEYS) {
        printf("Error: Maximum number of keys reached.\n");
        return;
    }
    strcpy(key_value_list[num_keys].key, key);
    strcpy(key_value_list[num_keys].value, value);
    num_keys++;
}

void delete_key_value(char *key) {
    int i;
    for (i = 0; i < num_keys; i++) {
        if (strcmp(key_value_list[i].key, key) == 0) {
            memmove(&key_value_list[i], &key_value_list[i + 1], (num_keys - i - 1) * sizeof(struct key_value));
            num_keys--;
            return;
        }
    }
}

void search_key_value(char *key) {
    int i;
    for (i = 0; i < num_keys; i++) {
        if (strcmp(key_value_list[i].key, key) == 0) {
            printf("Value: %s\n", key_value_list[i].value);
            return;
        }
    }
    printf("Key not found.\n");
}

int main() {
    init();
    add_key_value("name", "John");
    add_key_value("age", "30");
    search_key_value("name");
    search_key_value("age");
    delete_key_value("age");
    search_key_value("age");
    return 0;
}
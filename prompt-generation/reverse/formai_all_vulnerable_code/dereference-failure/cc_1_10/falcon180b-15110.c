//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char *key;
    char *value;
} kv_pair;

typedef struct {
    kv_pair *pairs;
    int count;
} kv_table;

kv_table *kv_table_create() {
    kv_table *table = (kv_table *)malloc(sizeof(kv_table));
    table->pairs = NULL;
    table->count = 0;
    return table;
}

void kv_table_destroy(kv_table *table) {
    int i;
    for (i = 0; i < table->count; i++) {
        free(table->pairs[i].key);
        free(table->pairs[i].value);
    }
    free(table->pairs);
    free(table);
}

void kv_table_add(kv_table *table, char *key, char *value) {
    kv_pair *pair = (kv_pair *)malloc(sizeof(kv_pair));
    pair->key = strdup(key);
    pair->value = strdup(value);
    table->pairs = (kv_pair *)realloc(table->pairs, sizeof(kv_pair) * (table->count + 1));
    table->pairs[table->count++] = *pair;
    free(pair);
}

char *kv_table_get(kv_table *table, char *key) {
    int i;
    for (i = 0; i < table->count; i++) {
        if (strcmp(table->pairs[i].key, key) == 0) {
            return table->pairs[i].value;
        }
    }
    return NULL;
}

void kv_table_print(kv_table *table) {
    int i;
    for (i = 0; i < table->count; i++) {
        printf("%s: %s\n", table->pairs[i].key, table->pairs[i].value);
    }
}

int main() {
    kv_table *table = kv_table_create();

    kv_table_add(table, "name", "John Doe");
    kv_table_add(table, "age", "30");
    kv_table_add(table, "address", "123 Main St");

    kv_table_print(table);

    char *value = kv_table_get(table, "name");
    printf("Name: %s\n", value);

    kv_table_destroy(table);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *key;
    char *value;
} kv_pair;

typedef struct {
    kv_pair *data;
    int count;
    int capacity;
} kv_table;

kv_table *kv_create() {
    kv_table *table = (kv_table *)malloc(sizeof(kv_table));
    table->data = (kv_pair *)malloc(sizeof(kv_pair) * 16);
    table->count = 0;
    table->capacity = 16;
    return table;
}

void kv_destroy(kv_table *table) {
    for (int i = 0; i < table->count; i++) {
        free(table->data[i].key);
        free(table->data[i].value);
    }
    free(table->data);
    free(table);
}

void kv_put(kv_table *table, const char *key, const char *value) {
    if (table->count >= table->capacity) {
        table->capacity *= 2;
        table->data = (kv_pair *)realloc(table->data, sizeof(kv_pair) * table->capacity);
    }
    table->data[table->count].key = strdup(key);
    table->data[table->count].value = strdup(value);
    table->count++;
}

const char *kv_get(kv_table *table, const char *key) {
    for (int i = 0; i < table->count; i++) {
        if (strcmp(table->data[i].key, key) == 0) {
            return table->data[i].value;
        }
    }
    return NULL;
}

void kv_remove(kv_table *table, const char *key) {
    for (int i = 0; i < table->count; i++) {
        if (strcmp(table->data[i].key, key) == 0) {
            free(table->data[i].key);
            free(table->data[i].value);
            for (int j = i; j < table->count - 1; j++) {
                table->data[j] = table->data[j + 1];
            }
            table->count--;
            return;
        }
    }
}

int kv_count(kv_table *table) {
    return table->count;
}

void kv_print(kv_table *table) {
    for (int i = 0; i < table->count; i++) {
        printf("%s: %s\n", table->data[i].key, table->data[i].value);
    }
}

int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    kv_table *table = kv_create();

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");
        kv_put(table, key, value);
    }

    fclose(file);

    printf("Table:\n");
    kv_print(table);

    kv_remove(table, "name");

    printf("\nTable after removing 'name':\n");
    kv_print(table);

    kv_destroy(table);

    return 0;
}
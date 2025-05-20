//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VALUE_LENGTH 100
#define MAX_KEY_LENGTH 100
#define MAX_ROWS 100
#define MAX_COLUMNS 100

typedef struct {
    char *key;
    char *value;
} Record;

typedef struct {
    Record **records;
    int num_records;
} Table;

void table_init(Table *t) {
    t->records = NULL;
    t->num_records = 0;
}

void table_destroy(Table *t) {
    int i;
    for (i = 0; i < t->num_records; i++) {
        free(t->records[i]->key);
        free(t->records[i]->value);
        free(t->records[i]);
    }
    free(t->records);
}

void table_add_record(Table *t, char *key, char *value) {
    Record *r = malloc(sizeof(Record));
    r->key = strdup(key);
    r->value = strdup(value);
    t->records = realloc(t->records, sizeof(Record *) * (t->num_records + 1));
    t->records[t->num_records++] = r;
}

int table_search(Table *t, char *key) {
    int i;
    for (i = 0; i < t->num_records; i++) {
        if (strcmp(t->records[i]->key, key) == 0) {
            return i;
        }
    }
    return -1;
}

char *table_get_value(Table *t, char *key) {
    int i = table_search(t, key);
    if (i >= 0) {
        return t->records[i]->value;
    } else {
        return NULL;
    }
}

void table_print(Table *t) {
    int i;
    for (i = 0; i < t->num_records; i++) {
        printf("%s: %s\n", t->records[i]->key, t->records[i]->value);
    }
}

int main() {
    Table db;
    table_init(&db);

    table_add_record(&db, "name", "Alice");
    table_add_record(&db, "age", "25");
    table_add_record(&db, "city", "New York");

    table_print(&db);

    char *value = table_get_value(&db, "name");
    if (value!= NULL) {
        printf("Name: %s\n", value);
    } else {
        printf("Name not found\n");
    }

    table_destroy(&db);
    return 0;
}
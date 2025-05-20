//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000
#define MAX_INDEXES 100
#define MAX_INDEX_LEN 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} data_t;

typedef struct {
    char name[MAX_INDEX_LEN];
    int (*compare_func)(const void *, const void *);
} index_t;

int strcmp_index(const void *a, const void *b) {
    data_t *data_a = (data_t *)a;
    data_t *data_b = (data_t *)b;
    return strcmp(data_a->key, data_b->key);
}

int int_index(const void *a, const void *b) {
    data_t *data_a = (data_t *)a;
    data_t *data_b = (data_t *)b;
    return strcmp(data_a->value, data_b->value);
}

void create_index(index_t *index, char *name, int (*compare_func)(const void *, const void *)) {
    strcpy(index->name, name);
    index->compare_func = compare_func;
}

int main() {
    data_t data[100];
    index_t indexes[MAX_INDEXES];
    int num_indexes = 0;
    int num_data = 0;

    create_index(indexes + num_indexes, "key_index", strcmp_index);
    num_indexes++;

    while (1) {
        printf("Enter data (key value): ");
        scanf("%s %s", data[num_data].key, data[num_data].value);
        num_data++;

        if (num_data == 100) {
            break;
        }
    }

    for (int i = 0; i < num_data; i++) {
        for (int j = 0; j < num_indexes; j++) {
            indexes[j].compare_func(data + i, data);
        }
    }

    return 0;
}
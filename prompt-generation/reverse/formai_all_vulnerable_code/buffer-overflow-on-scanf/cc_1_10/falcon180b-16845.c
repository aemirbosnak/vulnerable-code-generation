//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_INDEX_LENGTH 1000
#define MAX_NUM_INDEXES 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
    int index_count;
    struct index_info {
        char name[MAX_INDEX_LENGTH];
        int value_index;
    } indexes[MAX_NUM_INDEXES];
} record;

void create_index(record *r, char *index_name, int value_index) {
    int i;
    for (i = 0; i < r->index_count; i++) {
        if (strcmp(r->indexes[i].name, index_name) == 0) {
            fprintf(stderr, "Error: index %s already exists.\n", index_name);
            exit(1);
        }
    }
    strcpy(r->indexes[r->index_count].name, index_name);
    r->indexes[r->index_count].value_index = value_index;
    r->index_count++;
}

void print_indexes(record *r) {
    int i;
    for (i = 0; i < r->index_count; i++) {
        printf("%s -> %d\n", r->indexes[i].name, r->indexes[i].value_index);
    }
}

int main() {
    record r;
    char buffer[MAX_VALUE_LENGTH];
    char name[MAX_NAME_LENGTH];
    char index_name[MAX_INDEX_LENGTH];
    int value_index;
    int i;

    printf("Enter name: ");
    scanf("%s", r.name);

    printf("Enter value: ");
    fgets(buffer, MAX_VALUE_LENGTH, stdin);
    strcpy(r.value, buffer);

    r.index_count = 0;

    while (1) {
        printf("Enter index name (or press enter to finish): ");
        scanf("%s", index_name);
        if (strcmp(index_name, "") == 0) {
            break;
        }
        value_index = strlen(r.value) - strlen(strstr(r.value, index_name));
        create_index(&r, index_name, value_index);
    }

    print_indexes(&r);

    return 0;
}
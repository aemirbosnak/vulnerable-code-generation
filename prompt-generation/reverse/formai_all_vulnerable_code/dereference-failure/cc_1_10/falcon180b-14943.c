//Falcon-180B DATASET v1.0 Category: Database querying ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_FIELD_SIZE 100
#define MAX_QUERY_SIZE 1000

typedef struct {
    char *field_name;
    int field_size;
    int field_type;
} field_t;

typedef struct {
    char *table_name;
    int num_fields;
    field_t *fields;
} table_t;

typedef struct {
    char *query;
    int num_tables;
    table_t *tables;
} query_t;

void parse_query(char *query, query_t *q) {
    char *token = strtok(query, " ");
    int num_tables = 0;

    while (token!= NULL) {
        if (strcmp(token, "FROM") == 0) {
            num_tables++;
        }
        token = strtok(NULL, " ");
    }

    q->num_tables = num_tables;
    q->tables = malloc(num_tables * sizeof(table_t));

    token = strtok(query, " ");
    int i = 0;

    while (token!= NULL) {
        if (strcmp(token, "FROM") == 0) {
            token = strtok(NULL, " ");
            table_t *t = &q->tables[i];
            t->table_name = token;
            i++;
        }
        token = strtok(NULL, " ");
    }
}

void execute_query(query_t *q) {
    int i, j;

    for (i = 0; i < q->num_tables; i++) {
        table_t *t = &q->tables[i];
        for (j = 0; j < t->num_fields; j++) {
            field_t *f = &t->fields[j];
            printf("%s: ", f->field_name);
        }
        printf("\n");
    }
}

int main() {
    char query[MAX_QUERY_SIZE];
    query_t q;

    printf("Enter query: ");
    fgets(query, MAX_QUERY_SIZE, stdin);

    parse_query(query, &q);
    execute_query(&q);

    return 0;
}
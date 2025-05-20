//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 100000
#define MAX_COL 1000

typedef struct {
    char *data;
    int len;
} row_t;

typedef struct {
    row_t **rows;
    int num_rows;
    int num_cols;
} table_t;

table_t *table_create() {
    table_t *t = malloc(sizeof(table_t));
    t->rows = NULL;
    t->num_rows = 0;
    t->num_cols = 0;
    return t;
}

void table_destroy(table_t *t) {
    for (int i = 0; i < t->num_rows; i++) {
        for (int j = 0; j < t->num_cols; j++) {
            free(t->rows[i][j].data);
        }
        free(t->rows[i]);
    }
    free(t->rows);
    free(t);
}

void table_add_row(table_t *t, row_t *row) {
    if (t->num_rows == 0) {
        t->num_cols = row->len;
    } else if (t->num_cols!= row->len) {
        printf("Error: table column length mismatch\n");
        exit(1);
    }
    t->rows = realloc(t->rows, sizeof(row_t *) * (t->num_rows + 1));
    t->rows[t->num_rows++] = row;
}

void table_print(table_t *t) {
    for (int i = 0; i < t->num_rows; i++) {
        for (int j = 0; j < t->num_cols; j++) {
            printf("%s ", t->rows[i][j].data);
        }
        printf("\n");
    }
}

int main() {
    table_t *t = table_create();
    row_t *row1 = malloc(sizeof(row_t));
    row1->data = strdup("Alice");
    row1->len = strlen(row1->data);
    table_add_row(t, row1);

    row_t *row2 = malloc(sizeof(row_t));
    row2->data = strdup("Bob");
    row2->len = strlen(row2->data);
    table_add_row(t, row2);

    row_t *row3 = malloc(sizeof(row_t));
    row3->data = strdup("Charlie");
    row3->len = strlen(row3->data);
    table_add_row(t, row3);

    table_print(t);

    table_destroy(t);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Database querying ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_ROW_LEN 100
#define MAX_COL_LEN 100

struct table {
    char **rows;
    int num_rows;
    int num_cols;
};

struct table *create_table(int num_rows, int num_cols) {
    struct table *t = malloc(sizeof(struct table));
    t->rows = malloc(sizeof(char *) * num_rows);
    t->num_rows = num_rows;
    t->num_cols = num_cols;

    for (int i = 0; i < num_rows; i++) {
        t->rows[i] = malloc(sizeof(char) * MAX_ROW_LEN);
    }

    return t;
}

void destroy_table(struct table *t) {
    for (int i = 0; i < t->num_rows; i++) {
        free(t->rows[i]);
    }
    free(t->rows);
    free(t);
}

void add_row(struct table *t, char *row) {
    t->rows[t->num_rows - 1] = row;
}

int main() {
    struct table *table = create_table(3, 3);

    add_row(table, "John");
    add_row(table, "Doe");
    add_row(table, "25");

    printf("Table:\n");

    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->rows[i]);
        }
        printf("\n");
    }

    destroy_table(table);

    return 0;
}
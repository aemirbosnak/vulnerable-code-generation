//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = malloc(num_cols * sizeof(char));
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%c", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(3, 3);
    table->data[0][0] = 'a';
    table->data[0][1] = 'b';
    table->data[0][2] = 'c';
    table->data[1][0] = 'd';
    table->data[1][1] = 'e';
    table->data[1][2] = 'f';
    table->data[2][0] = 'g';
    table->data[2][1] = 'h';
    table->data[2][2] = 'i';
    print_table(table);
    destroy_table(table);
    return 0;
}
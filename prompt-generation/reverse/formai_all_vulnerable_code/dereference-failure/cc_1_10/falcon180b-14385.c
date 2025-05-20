//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA 1000

typedef struct {
    char *data;
    int rows;
    int cols;
} Table;

Table* create_table(int rows, int cols) {
    Table *table = (Table*) malloc(sizeof(Table));
    table->data = (char*) malloc(rows * cols * MAX_DATA);
    table->rows = rows;
    table->cols = cols;
    return table;
}

void destroy_table(Table *table) {
    free(table->data);
    free(table);
}

void print_table(Table *table) {
    int i, j;
    for (i = 0; i < table->rows; i++) {
        for (j = 0; j < table->cols; j++) {
            printf("%c", table->data[i * table->cols + j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(5, 5);
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            table->data[i * 5 + j] = 'a' + i + j;
        }
    }

    print_table(table);

    destroy_table(table);

    return 0;
}
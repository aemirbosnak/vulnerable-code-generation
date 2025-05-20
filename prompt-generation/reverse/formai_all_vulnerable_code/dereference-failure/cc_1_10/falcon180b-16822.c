//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_LENGTH 1000

typedef struct {
    char *name;
    int id;
} record_t;

typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} table_t;

table_t *create_table(int num_rows, int num_cols) {
    table_t *table = malloc(sizeof(table_t));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = malloc(num_cols * sizeof(char));
        memset(table->data[i], 0, num_cols * sizeof(char));
    }
    return table;
}

void destroy_table(table_t *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void print_table(table_t *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%c", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    table_t *table = create_table(MAX_ROWS, MAX_COLS);
    record_t *record = malloc(sizeof(record_t));
    record->name = "John Doe";
    record->id = 1;
    int row = 0;
    int col = 0;
    while (row < MAX_ROWS && col < MAX_COLS) {
        if (col == 0) {
            printf("ID\tName\n");
        }
        if (record->name[col - 1]!= '\0') {
            table->data[row][col] = record->name[col - 1];
        } else {
            table->data[row][col] = '\0';
        }
        col++;
        if (col == MAX_COLS) {
            row++;
            col = 0;
        }
    }
    destroy_table(table);
    free(record);
    return 0;
}
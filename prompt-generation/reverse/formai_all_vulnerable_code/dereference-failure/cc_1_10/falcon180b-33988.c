//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

void create_table(Table *table) {
    table->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    table->num_rows = 0;
    table->num_cols = 0;
}

void destroy_table(Table *table) {
    int i;
    for (i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
}

void add_row(Table *table, char *row_data) {
    int num_cols = strlen(row_data);
    if (num_cols > MAX_COLS) {
        printf("Error: row is too long\n");
        return;
    }
    table->data[table->num_rows] = (char *)malloc(num_cols + 1);
    strcpy(table->data[table->num_rows], row_data);
    table->num_rows++;
    if (num_cols > table->num_cols) {
        table->num_cols = num_cols;
    }
}

void print_table(Table *table) {
    int i, j;
    for (i = 0; i < table->num_rows; i++) {
        for (j = 0; j < table->num_cols; j++) {
            printf("%c", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    create_table(&table);

    add_row(&table, "Name|Age|City");
    add_row(&table, "John|25|New York");
    add_row(&table, "Jane|30|Los Angeles");
    add_row(&table, "Bob|40|Chicago");

    print_table(&table);

    destroy_table(&table);

    return 0;
}
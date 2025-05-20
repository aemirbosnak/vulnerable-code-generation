//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 1000
#define MAX_DATA_SIZE 1024

typedef struct {
    char *name;
    int num_rows;
    int num_columns;
    char **data;
} Table;

Table *create_table(char *name, int num_rows, int num_columns) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->name = strdup(name);
    table->num_rows = num_rows;
    table->num_columns = num_columns;
    table->data = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *)malloc(MAX_DATA_SIZE);
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table->name);
    free(table);
}

int main() {
    Table *table = create_table("example_table", 3, 3);

    table->data[0] = strdup("1");
    table->data[1] = strdup("2");
    table->data[2] = strdup("3");

    table->data[3] = strdup("4");
    table->data[4] = strdup("5");
    table->data[5] = strdup("6");

    table->data[6] = strdup("7");
    table->data[7] = strdup("8");
    table->data[8] = strdup("9");

    printf("Table name: %s\n", table->name);
    printf("Number of rows: %d\n", table->num_rows);
    printf("Number of columns: %d\n", table->num_columns);

    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_columns; j++) {
            printf("%s ", table->data[i * table->num_columns + j]);
        }
        printf("\n");
    }

    destroy_table(table);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int num_cols;
    char **data;
} Table;

Table *create_table(char *name, int num_cols) {
    Table *table = malloc(sizeof(Table));
    table->name = strdup(name);
    table->num_cols = num_cols;
    table->data = malloc(num_cols * sizeof(char *));
    for (int i = 0; i < num_cols; i++) {
        table->data[i] = NULL;
    }
    return table;
}

void add_row(Table *table, char **row_data) {
    for (int i = 0; i < table->num_cols; i++) {
        table->data[i] = realloc(table->data[i], strlen(row_data[i]) + 1);
        strcpy(table->data[i], row_data[i]);
    }
}

void print_table(Table *table) {
    printf("Table %s:\n", table->name);
    for (int i = 0; i < table->num_cols; i++) {
        printf("%s ", table->data[i]);
    }
    printf("\n");
}

void free_table(Table *table) {
    for (int i = 0; i < table->num_cols; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table->name);
    free(table);
}

int main() {
    Table *table1 = create_table("table1", 3);
    add_row(table1, (char *[]){"Alice", "25", "New York"});
    add_row(table1, (char *[]){"Bob", "30", "San Francisco"});
    add_row(table1, (char *[]){"Charlie", "35", "Seattle"});

    Table *table2 = create_table("table2", 2);
    add_row(table2, (char *[]){"1", "2"});
    add_row(table2, (char *[]){"3", "4"});
    add_row(table2, (char *[]){"5", "6"});

    print_table(table1);
    print_table(table2);

    free_table(table1);
    free_table(table2);

    return 0;
}
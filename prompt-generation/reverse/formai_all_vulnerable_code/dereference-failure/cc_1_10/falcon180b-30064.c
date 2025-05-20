//Falcon-180B DATASET v1.0 Category: Database querying ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_LEN 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (char **)malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *)malloc(sizeof(char) * num_cols);
        memset(table->data[i], '\0', num_cols);
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
            printf("%s ", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(3, 3);

    strcpy(table->data[0][0], "Name");
    strcpy(table->data[0][1], "Age");
    strcpy(table->data[0][2], "Gender");

    strcpy(table->data[1][0], "John");
    strcpy(table->data[1][1], "25");
    strcpy(table->data[1][2], "Male");

    strcpy(table->data[2][0], "Jane");
    strcpy(table->data[2][1], "30");
    strcpy(table->data[2][2], "Female");

    print_table(table);

    destroy_table(table);

    return 0;
}
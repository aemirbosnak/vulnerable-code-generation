//Falcon-180B DATASET v1.0 Category: Database querying ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_VAL_LEN 100

typedef struct {
    char **values;
    int num_cols;
    int num_rows;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table *) malloc(sizeof(Table));
    table->num_cols = num_cols;
    table->num_rows = num_rows;
    table->values = (char **) malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        table->values[i] = (char *) malloc(num_cols * MAX_VAL_LEN);
        for (int j = 0; j < num_cols; j++) {
            table->values[i][j] = '\0';
        }
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            free(table->values[i][j]);
        }
        free(table->values[i]);
    }
    free(table->values);
    free(table);
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->values[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create a table with 3 rows and 4 columns
    Table *table = create_table(3, 4);

    // Set the values in the table
    strcpy(table->values[0][0], "John");
    strcpy(table->values[0][1], "25");
    strcpy(table->values[0][2], "Male");
    strcpy(table->values[0][3], "USA");

    strcpy(table->values[1][0], "Jane");
    strcpy(table->values[1][1], "30");
    strcpy(table->values[1][2], "Female");
    strcpy(table->values[1][3], "Canada");

    strcpy(table->values[2][0], "Bob");
    strcpy(table->values[2][1], "20");
    strcpy(table->values[2][2], "Male");
    strcpy(table->values[2][3], "UK");

    // Print the table
    print_table(table);

    // Destroy the table
    destroy_table(table);

    return 0;
}
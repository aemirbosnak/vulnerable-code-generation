//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_STRING_LEN 50

typedef struct {
    int row_count;
    int col_count;
    char **data;
} Database;

Database *create_database(int rows, int cols) {
    Database *db = (Database *)malloc(sizeof(Database));
    db->row_count = rows;
    db->col_count = cols;
    db->data = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        db->data[i] = (char *)malloc(cols * MAX_STRING_LEN);
    }
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->row_count; i++) {
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

void set_cell_value(Database *db, int row, int col, char *value) {
    strcpy(db->data[row][col], value);
}

char *get_cell_value(Database *db, int row, int col) {
    return db->data[row][col];
}

int main() {
    Database *db = create_database(5, 3);
    set_cell_value(db, 0, 0, "John");
    set_cell_value(db, 0, 1, "Doe");
    set_cell_value(db, 0, 2, "25");
    set_cell_value(db, 1, 0, "Jane");
    set_cell_value(db, 1, 1, "Doe");
    set_cell_value(db, 1, 2, "30");
    set_cell_value(db, 2, 0, "Bob");
    set_cell_value(db, 2, 1, "Smith");
    set_cell_value(db, 2, 2, "35");
    set_cell_value(db, 3, 0, "Alice");
    set_cell_value(db, 3, 1, "Doe");
    set_cell_value(db, 3, 2, "28");
    set_cell_value(db, 4, 0, "Charlie");
    set_cell_value(db, 4, 1, "Brown");
    set_cell_value(db, 4, 2, "40");

    char *name = "Doe";
    int age = 30;
    char *query = (char *)malloc(MAX_STRING_LEN);
    sprintf(query, "SELECT * FROM database WHERE name=\"%s\" AND age=%d;", name, age);

    char *result = get_cell_value(db, 1, 2);
    printf("Result: %s\n", result);

    destroy_database(db);
    free(query);
    return 0;
}
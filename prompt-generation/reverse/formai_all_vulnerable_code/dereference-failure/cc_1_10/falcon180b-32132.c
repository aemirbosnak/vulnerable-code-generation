//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *data;
    int rows;
    int cols;
} Database;

Database *create_database(int rows, int cols) {
    Database *db = (Database *)malloc(sizeof(Database));
    db->data = (char *)malloc(rows * cols * MAX_DATA_SIZE);
    db->rows = rows;
    db->cols = cols;
    return db;
}

void destroy_database(Database *db) {
    free(db->data);
    free(db);
}

void set_cell(Database *db, int row, int col, char *data) {
    int index = row * db->cols + col;
    strncpy(db->data + index * MAX_DATA_SIZE, data, MAX_DATA_SIZE - 1);
}

char *get_cell(Database *db, int row, int col) {
    int index = row * db->cols + col;
    return db->data + index * MAX_DATA_SIZE;
}

int main() {
    Database *db = create_database(5, 4);

    set_cell(db, 0, 0, "Name");
    set_cell(db, 0, 1, "Age");
    set_cell(db, 0, 2, "Gender");
    set_cell(db, 0, 3, "City");

    set_cell(db, 1, 0, "John");
    set_cell(db, 1, 1, "25");
    set_cell(db, 1, 2, "Male");
    set_cell(db, 1, 3, "New York");

    set_cell(db, 2, 0, "Jane");
    set_cell(db, 2, 1, "30");
    set_cell(db, 2, 2, "Female");
    set_cell(db, 2, 3, "Los Angeles");

    set_cell(db, 3, 0, "Bob");
    set_cell(db, 3, 1, "40");
    set_cell(db, 3, 2, "Male");
    set_cell(db, 3, 3, "Chicago");

    set_cell(db, 4, 0, "Alice");
    set_cell(db, 4, 1, "35");
    set_cell(db, 4, 2, "Female");
    set_cell(db, 4, 3, "San Francisco");

    printf("Database:\n");
    for (int i = 0; i < db->rows; i++) {
        for (int j = 0; j < db->cols; j++) {
            char *data = get_cell(db, i, j);
            printf("%s ", data);
        }
        printf("\n");
    }

    destroy_database(db);

    return 0;
}
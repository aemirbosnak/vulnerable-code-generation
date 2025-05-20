//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 1000
#define MAX_DATA_SIZE 1000

typedef struct {
    char *data;
    int rows;
    int columns;
} database_t;

database_t *create_database(int rows, int columns) {
    database_t *db = (database_t *)malloc(sizeof(database_t));
    db->data = (char *)malloc(rows * columns * sizeof(char));
    db->rows = rows;
    db->columns = columns;
    return db;
}

void destroy_database(database_t *db) {
    free(db->data);
    free(db);
}

void set_data(database_t *db, int row, int column, char *data) {
    int offset = row * db->columns + column;
    strncpy(db->data + offset, data, strlen(data));
}

char *get_data(database_t *db, int row, int column) {
    int offset = row * db->columns + column;
    return db->data + offset;
}

void print_database(database_t *db) {
    for (int i = 0; i < db->rows; i++) {
        for (int j = 0; j < db->columns; j++) {
            printf("%s ", get_data(db, i, j));
        }
        printf("\n");
    }
}

int main() {
    database_t *db = create_database(5, 3);
    set_data(db, 0, 0, "Name");
    set_data(db, 0, 1, "Age");
    set_data(db, 0, 2, "Gender");
    set_data(db, 1, 0, "John");
    set_data(db, 1, 1, "25");
    set_data(db, 1, 2, "Male");
    set_data(db, 2, 0, "Jane");
    set_data(db, 2, 1, "30");
    set_data(db, 2, 2, "Female");
    set_data(db, 3, 0, "Bob");
    set_data(db, 3, 1, "20");
    set_data(db, 3, 2, "Male");
    set_data(db, 4, 0, "Alice");
    set_data(db, 4, 1, "28");
    set_data(db, 4, 2, "Female");
    print_database(db);
    destroy_database(db);
    return 0;
}
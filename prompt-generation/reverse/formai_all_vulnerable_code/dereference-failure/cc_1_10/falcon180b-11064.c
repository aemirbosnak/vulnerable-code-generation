//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char* data;
    int rows;
    int cols;
} database;

void create_database(database* db, int rows, int cols) {
    db->data = (char*)malloc(rows * cols * sizeof(char));
    db->rows = rows;
    db->cols = cols;
    memset(db->data, '\0', rows * cols * sizeof(char));
}

void delete_database(database* db) {
    free(db->data);
    db->data = NULL;
    db->rows = 0;
    db->cols = 0;
}

void add_data(database* db, int row, int col, char* data) {
    if (row >= 0 && row < db->rows && col >= 0 && col < db->cols) {
        int index = row * db->cols + col;
        int len = strlen(data);
        if (len > MAX_DATA_SIZE) {
            printf("Error: Data too large.\n");
            return;
        }
        strncat(db->data + index, data, len);
    } else {
        printf("Error: Invalid position.\n");
    }
}

void print_database(database* db) {
    printf("\n");
    for (int i = 0; i < db->rows; i++) {
        for (int j = 0; j < db->cols; j++) {
            int index = i * db->cols + j;
            printf("%c", db->data[index]);
        }
        printf("\n");
    }
}

int main() {
    database db;
    create_database(&db, 5, 10);
    add_data(&db, 0, 0, "Hello");
    add_data(&db, 1, 0, "World");
    add_data(&db, 2, 0, "C");
    add_data(&db, 3, 0, "Database");
    add_data(&db, 4, 0, "Simulation");
    print_database(&db);
    delete_database(&db);
    return 0;
}
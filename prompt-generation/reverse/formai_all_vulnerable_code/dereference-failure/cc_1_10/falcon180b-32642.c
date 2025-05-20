//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Struct to hold database information
typedef struct {
    char db_name[50];
    int num_rows;
    int num_cols;
    char **data;
} database_t;

// Function to create a new database
database_t *create_db(char *name, int rows, int cols) {
    database_t *db = malloc(sizeof(database_t));
    strcpy(db->db_name, name);
    db->num_rows = rows;
    db->num_cols = cols;
    db->data = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        db->data[i] = malloc(cols * sizeof(char));
        for (int j = 0; j < cols; j++) {
            db->data[i][j] = '\0';
        }
    }
    return db;
}

// Function to insert data into the database
void insert_data(database_t *db, int row, int col, char *data) {
    strncat(db->data[row - 1], data, col);
}

// Function to retrieve data from the database
char *get_data(database_t *db, int row, int col) {
    return db->data[row - 1] + col - 1;
}

// Function to delete a row from the database
void delete_row(database_t *db, int row) {
    free(db->data[row - 1]);
    for (int i = row - 1; i < db->num_rows - 1; i++) {
        db->data[i] = db->data[i + 1];
    }
    db->num_rows--;
    db->data = realloc(db->data, db->num_rows * sizeof(char *));
}

// Function to delete a column from the database
void delete_col(database_t *db, int col) {
    for (int i = 0; i < db->num_rows; i++) {
        db->data[i] = realloc(db->data[i], (db->num_cols - 1) * sizeof(char));
    }
    db->num_cols--;
}

// Function to print the database
void print_db(database_t *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%c", db->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    database_t *db = create_db("test_db", 3, 4);
    insert_data(db, 1, 1, "hello");
    insert_data(db, 2, 1, "world");
    print_db(db);
    delete_col(db, 1);
    print_db(db);
    delete_row(db, 2);
    print_db(db);
    free(db);
    return 0;
}
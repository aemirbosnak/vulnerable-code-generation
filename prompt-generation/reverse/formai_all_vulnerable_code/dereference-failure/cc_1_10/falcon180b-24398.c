//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Database;

Database *db_create() {
    Database *db = (Database *)malloc(sizeof(Database));
    db->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    db->num_rows = 0;
    db->num_cols = 0;
    return db;
}

void db_destroy(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

void db_add_row(Database *db, char *row_data) {
    char **new_data = (char **)realloc(db->data, (db->num_rows + 1) * sizeof(char *));
    if (new_data == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    db->data = new_data;
    db->data[db->num_rows] = strdup(row_data);
    db->num_rows++;
    db->num_cols = strlen(row_data);
}

void db_print(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%c", db->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Database *db = db_create();
    db_add_row(db, "Name,Age,Gender");
    db_add_row(db, "John,25,Male");
    db_add_row(db, "Jane,30,Female");
    db_add_row(db, "Bob,20,Male");
    db_print(db);
    db_destroy(db);
    return 0;
}
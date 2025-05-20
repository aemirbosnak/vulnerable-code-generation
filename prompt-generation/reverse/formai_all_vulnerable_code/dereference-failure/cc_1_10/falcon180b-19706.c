//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db) {
    db->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    db->num_rows = 0;
    db->num_cols = 0;
}

void add_row(Database *db, char *row_data) {
    int i;
    char **new_data = (char **)malloc((db->num_rows + 1) * sizeof(char *));
    for (i = 0; i < db->num_rows; i++) {
        new_data[i] = db->data[i];
    }
    new_data[db->num_rows] = row_data;
    free(db->data);
    db->data = new_data;
    db->num_rows++;
    db->num_cols = strlen(row_data);
}

void print_database(Database *db) {
    int i, j;
    for (i = 0; i < db->num_rows; i++) {
        for (j = 0; j < db->num_cols; j++) {
            printf("%c", db->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Database db;
    init_database(&db);
    add_row(&db, "John Doe");
    add_row(&db, "Jane Smith");
    add_row(&db, "Bob Johnson");
    print_database(&db);
    return 0;
}
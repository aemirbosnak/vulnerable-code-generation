//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_ROW_LENGTH 1000

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

void free_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
}

void add_row(Database *db, char *row_data) {
    db->data[db->num_rows] = (char *)malloc(strlen(row_data) + 1);
    strcpy(db->data[db->num_rows], row_data);
    db->num_rows++;
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        printf("%s\n", db->data[i]);
    }
}

int main() {
    Database db;
    init_database(&db);

    add_row(&db, "John Doe");
    add_row(&db, "Jane Doe");
    add_row(&db, "Bob Smith");

    print_database(&db);

    free_database(&db);

    return 0;
}
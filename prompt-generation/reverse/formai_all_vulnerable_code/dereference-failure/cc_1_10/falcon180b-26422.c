//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *data;
    int size;
} Data;

typedef struct {
    Data **rows;
    int num_rows;
    int num_columns;
} Database;

// Function prototypes
void create_database(Database *db, int num_rows, int num_columns);
void add_row(Database *db, int row_num, Data *data);
void delete_row(Database *db, int row_num);
void update_row(Database *db, int row_num, Data *data);
void print_database(Database *db);

int main() {
    Database db;
    create_database(&db, 3, 2);

    Data d1 = {"Name1", 5};
    Data d2 = {"Name2", 10};
    Data d3 = {"Name3", 15};

    add_row(&db, 0, &d1);
    add_row(&db, 1, &d2);
    add_row(&db, 2, &d3);

    print_database(&db);

    update_row(&db, 1, &d3);

    print_database(&db);

    delete_row(&db, 2);

    print_database(&db);

    return 0;
}

void create_database(Database *db, int num_rows, int num_columns) {
    db->num_rows = num_rows;
    db->num_columns = num_columns;
    db->rows = (Data **)malloc(num_rows * sizeof(Data *));
    for (int i = 0; i < num_rows; i++) {
        db->rows[i] = NULL;
    }
}

void add_row(Database *db, int row_num, Data *data) {
    if (row_num >= 0 && row_num < db->num_rows) {
        db->rows[row_num] = data;
    } else {
        printf("Invalid row number\n");
    }
}

void delete_row(Database *db, int row_num) {
    if (row_num >= 0 && row_num < db->num_rows) {
        free(db->rows[row_num]);
        db->rows[row_num] = NULL;
    } else {
        printf("Invalid row number\n");
    }
}

void update_row(Database *db, int row_num, Data *data) {
    if (row_num >= 0 && row_num < db->num_rows) {
        free(db->rows[row_num]);
        db->rows[row_num] = data;
    } else {
        printf("Invalid row number\n");
    }
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        if (db->rows[i]!= NULL) {
            printf("%s\n", db->rows[i]->data);
        } else {
            printf("NULL\n");
        }
    }
}
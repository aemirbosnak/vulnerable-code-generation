//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 20
#define MAX_DATA_SIZE 50

typedef struct {
    char *name;
    int id;
    float score;
} DataRow;

typedef struct {
    char *header;
    int num_rows;
    int num_cols;
    DataRow *data;
} Database;

void init_database(Database *db) {
    db->header = "My Database";
    db->num_rows = 0;
    db->num_cols = 3;
    db->data = (DataRow *)malloc(MAX_ROWS * sizeof(DataRow));
}

int add_data(Database *db, char *name, int id, float score) {
    if (db->num_rows >= MAX_ROWS) {
        printf("Error: Maximum number of rows reached.\n");
        return -1;
    }

    DataRow *row = &db->data[db->num_rows];
    row->name = (char *)malloc(MAX_DATA_SIZE * sizeof(char));
    strcpy(row->name, name);
    row->id = id;
    row->score = score;

    db->num_rows++;
    return 0;
}

int search_data(Database *db, char *name) {
    for (int i = 0; i < db->num_rows; i++) {
        if (strcmp(db->data[i].name, name) == 0) {
            printf("ID: %d, Score: %.2f\n", db->data[i].id, db->data[i].score);
            return 0;
        }
    }

    printf("Data not found.\n");
    return -1;
}

int main() {
    Database db;
    init_database(&db);

    add_data(&db, "John", 1, 90.5);
    add_data(&db, "Jane", 2, 85.3);

    search_data(&db, "John");
    search_data(&db, "Jane");
    search_data(&db, "Bob");

    return 0;
}
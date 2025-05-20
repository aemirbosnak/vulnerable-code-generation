//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 50
#define MAX_DATA_SIZE 100

typedef struct {
    char *name;
    int num_rows;
    int num_cols;
    char **data;
} Database;

void create_database(Database *db, char *name) {
    db->name = strdup(name);
    db->num_rows = 0;
    db->num_cols = 0;
    db->data = NULL;
}

void add_row(Database *db, char *data) {
    db->num_rows++;
    db->data = realloc(db->data, sizeof(char *) * db->num_rows);
    db->data[db->num_rows - 1] = strdup(data);
}

void add_col(Database *db, char *data) {
    db->num_cols++;
    db->data = realloc(db->data, sizeof(char *) * db->num_rows * db->num_cols);
    for (int i = 0; i < db->num_rows; i++) {
        db->data[i * db->num_cols + db->num_cols - 1] = strdup(data);
    }
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%s ", db->data[i * db->num_cols + j]);
        }
        printf("\n");
    }
}

int main() {
    Database db;
    create_database(&db, "test_db");

    add_row(&db, "1 2 3");
    add_row(&db, "4 5 6");

    add_col(&db, "a");
    add_col(&db, "b");

    print_database(&db);

    return 0;
}
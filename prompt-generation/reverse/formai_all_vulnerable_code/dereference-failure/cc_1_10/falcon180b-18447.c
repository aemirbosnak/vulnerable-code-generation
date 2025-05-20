//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db) {
    db->data = NULL;
    db->num_rows = 0;
    db->num_cols = 0;
}

void destroy_database(Database *db) {
    int i;
    for (i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
}

void add_row(Database *db, char *row_data) {
    int row_len = strlen(row_data);
    if (db->num_cols == 0) {
        db->num_cols = row_len;
    } else if (row_len!= db->num_cols) {
        printf("Error: Row length does not match column length.\n");
        return;
    }
    db->data = realloc(db->data, sizeof(char *) * (db->num_rows + 1));
    db->data[db->num_rows] = malloc(row_len + 1);
    strcpy(db->data[db->num_rows], row_data);
    db->num_rows++;
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
    add_row(&db, "Name,Age,Gender");
    add_row(&db, "Alice,25,F");
    add_row(&db, "Bob,30,M");
    add_row(&db, "Charlie,22,M");
    print_database(&db);
    destroy_database(&db);
    return 0;
}
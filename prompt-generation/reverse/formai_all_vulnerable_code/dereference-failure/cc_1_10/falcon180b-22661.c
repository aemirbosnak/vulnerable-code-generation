//Falcon-180B DATASET v1.0 Category: Database querying ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_ROW_LEN 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Database;

Database *create_database(int num_rows, int num_cols) {
    Database *db = (Database *)malloc(sizeof(Database));
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    db->data = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        db->data[i] = (char *)malloc(num_cols * MAX_ROW_LEN);
    }
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

void add_row(Database *db, char *row_data) {
    int row_len = strlen(row_data);
    if (row_len > db->num_cols * MAX_ROW_LEN) {
        printf("Error: Row data too long.\n");
        return;
    }
    db->data[db->num_rows - 1] = (char *)realloc(db->data[db->num_rows - 1], row_len + 1);
    strcpy(db->data[db->num_rows - 1], row_data);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%s ", db->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Database *db = create_database(3, 3);
    add_row(db, "Name Age Gender");
    add_row(db, "John 25 M");
    add_row(db, "Jane 30 F");
    add_row(db, "Jack 20 M");
    print_database(db);
    destroy_database(db);
    return 0;
}
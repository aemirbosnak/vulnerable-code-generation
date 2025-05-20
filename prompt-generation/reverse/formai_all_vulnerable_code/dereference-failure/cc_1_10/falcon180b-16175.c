//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_ROW_LENGTH 100

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} Database;

void initialize_database(Database *db) {
    db->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    db->num_rows = 0;
    db->num_columns = 0;
}

void add_row(Database *db, char *data) {
    db->data[db->num_rows] = (char *)malloc(MAX_ROW_LENGTH * sizeof(char));
    strcpy(db->data[db->num_rows], data);
    db->num_rows++;
}

void add_column(Database *db, char *data) {
    int i;
    for (i = 0; i < db->num_rows; i++) {
        db->data[i] = (char *)realloc(db->data[i], strlen(db->data[i]) + strlen(data) + 2);
        strcat(db->data[i], ",");
        strcat(db->data[i], data);
    }
    db->num_columns++;
}

void print_database(Database *db) {
    int i, j;
    for (i = 0; i < db->num_rows; i++) {
        for (j = 0; j < db->num_columns; j++) {
            printf("%s ", db->data[i]);
        }
        printf("\n");
    }
}

void free_database(Database *db) {
    int i;
    for (i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
}

int main() {
    Database db;
    initialize_database(&db);
    add_row(&db, "Name,Age,Gender");
    add_row(&db, "John,25,Male");
    add_row(&db, "Jane,30,Female");
    add_column(&db, "Occupation");
    add_row(&db, "Doctor");
    add_row(&db, "Engineer");
    add_row(&db, "Lawyer");
    print_database(&db);
    free_database(&db);
    return 0;
}
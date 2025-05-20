//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_ROW_LENGTH 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} Database;

Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->data = malloc(MAX_ROWS * sizeof(char *));
    db->num_rows = 0;
    db->num_columns = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        db->data[i] = malloc(MAX_ROW_LENGTH * sizeof(char));
        strcpy(db->data[i], "");
    }
    return db;
}

void add_column(Database *db, char *name) {
    db->num_columns++;
    for (int i = 0; i < db->num_rows; i++) {
        db->data[i] = realloc(db->data[i], strlen(db->data[i]) + strlen(name) + 2);
        strcat(db->data[i], name);
        strcat(db->data[i], ",");
    }
}

void add_row(Database *db, char *row_data) {
    db->num_rows++;
    db->data[db->num_rows - 1] = malloc(strlen(row_data) + 1);
    strcpy(db->data[db->num_rows - 1], row_data);
    for (int i = 0; i < db->num_columns - 1; i++) {
        strcat(db->data[db->num_rows - 1], ",");
    }
}

void print_database(Database *db) {
    printf("+----+");
    for (int i = 0; i < db->num_columns; i++) {
        printf("+%s+", db->data[0][i * MAX_ROW_LENGTH]);
    }
    printf("\n");
    for (int i = 0; i < db->num_rows; i++) {
        printf("| ");
        for (int j = 0; j < db->num_columns; j++) {
            printf("%s |", db->data[i][j * MAX_ROW_LENGTH]);
        }
        printf("\n");
    }
}

int main() {
    Database *db = create_database();
    add_column(db, "Name");
    add_column(db, "Age");
    add_row(db, "John Doe, 25");
    add_row(db, "Jane Doe, 30");
    print_database(db);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Database;

Database *create_database(int num_rows, int num_cols) {
    Database *db = malloc(sizeof(Database));
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    db->data = calloc(num_rows, sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        db->data[i] = calloc(num_cols, MAX_DATA_SIZE);
    }
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            free(db->data[i][j]);
        }
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%s ", db->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Database *db = create_database(3, 3);
    db->data[0][0] = "John";
    db->data[0][1] = "Doe";
    db->data[0][2] = "25";
    db->data[1][0] = "Jane";
    db->data[1][1] = "Doe";
    db->data[1][2] = "30";
    db->data[2][0] = "Bob";
    db->data[2][1] = "Smith";
    db->data[2][2] = "40";
    print_database(db);
    destroy_database(db);
    return 0;
}
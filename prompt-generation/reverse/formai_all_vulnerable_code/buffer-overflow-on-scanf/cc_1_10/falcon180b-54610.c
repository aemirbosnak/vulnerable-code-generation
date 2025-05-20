//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    int **data;
} Database;

void create_database(Database *db, int rows, int cols) {
    db->rows = rows;
    db->cols = cols;
    db->data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        db->data[i] = (int *)malloc(cols * sizeof(int));
    }
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
}

void fill_database(Database *db, int min_val, int max_val) {
    srand(time(NULL));
    for (int i = 0; i < db->rows; i++) {
        for (int j = 0; j < db->cols; j++) {
            db->data[i][j] = rand() % (max_val - min_val + 1) + min_val;
        }
    }
}

void print_database(Database *db) {
    for (int i = 0; i < db->rows; i++) {
        for (int j = 0; j < db->cols; j++) {
            printf("%d ", db->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Database db;
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    create_database(&db, rows, cols);
    fill_database(&db, 1, 100);
    print_database(&db);

    destroy_database(&db);

    return 0;
}
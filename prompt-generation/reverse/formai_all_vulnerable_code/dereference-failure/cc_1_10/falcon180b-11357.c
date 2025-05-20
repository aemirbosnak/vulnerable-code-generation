//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
    float salary;
} Record;

typedef struct {
    Record *data;
    int rows;
    int cols;
} Database;

void create_table(Database *db, int rows, int cols) {
    db->data = (Record *)malloc(rows * sizeof(Record));
    db->rows = rows;
    db->cols = cols;
    int i, j;
    for (i = 0; i < rows; i++) {
        db->data[i] = (Record) {.name = NULL,.age = 0,.salary = 0.0 };
        for (j = 0; j < cols; j++) {
            db->data[i].name = realloc(db->data[i].name, strlen(db->data[i].name) + 1);
            sprintf(db->data[i].name + strlen(db->data[i].name), "Column%d", j + 1);
        }
    }
}

void insert_record(Database *db, int row, int col, char *name, int age, float salary) {
    if (row >= 0 && row < db->rows && col >= 0 && col < db->cols) {
        db->data[row].name = realloc(db->data[row].name, strlen(db->data[row].name) + strlen(name) + 1);
        strcat(db->data[row].name, name);
        db->data[row].age = age;
        db->data[row].salary = salary;
    }
}

void print_table(Database *db) {
    int i, j;
    for (i = 0; i < db->rows; i++) {
        for (j = 0; j < db->cols; j++) {
            printf("%s\t", db->data[i].name);
        }
        printf("\n");
    }
}

int main() {
    Database db;
    create_table(&db, 5, 3);
    insert_record(&db, 0, 0, "John", 25, 50000.0);
    insert_record(&db, 0, 1, "Doe", 30, 60000.0);
    insert_record(&db, 1, 0, "Jane", 28, 55000.0);
    insert_record(&db, 1, 1, "Smith", 35, 70000.0);
    insert_record(&db, 2, 2, "Alice", 22, 40000.0);
    insert_record(&db, 3, 0, "Bob", 40, 80000.0);
    insert_record(&db, 4, 1, "Charlie", 45, 90000.0);
    print_table(&db);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person **rows;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db, int num_rows, int num_cols) {
    db->rows = malloc(num_rows * sizeof(Person*));
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    for (int i = 0; i < num_rows; i++) {
        db->rows[i] = malloc(num_cols * sizeof(Person));
    }
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            free(db->rows[i][j].name);
        }
        free(db->rows[i]);
    }
    free(db->rows);
}

int main() {
    Database db;
    init_database(&db, 2, 2);

    db.rows[0][0] = (Person) {.name = strdup("Alice"),.age = 25 };
    db.rows[0][1] = (Person) {.name = strdup("Bob"),.age = 30 };
    db.rows[1][0] = (Person) {.name = strdup("Charlie"),.age = 35 };
    db.rows[1][1] = (Person) {.name = strdup("David"),.age = 40 };

    for (int i = 0; i < db.num_rows; i++) {
        for (int j = 0; j < db.num_cols; j++) {
            printf("%s, %d\n", db.rows[i][j].name, db.rows[i][j].age);
        }
    }

    destroy_database(&db);
    return 0;
}